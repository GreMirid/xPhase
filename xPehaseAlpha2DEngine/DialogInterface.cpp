#include "UserInterface.h"

namespace xphase
{
	int UserInterface::DialogInterface::create(Window &window)
	{
		//TASK:
		/// Get data from .ini file
		INIReader reader(window.getPathtoGame() + TO_CFG + "dialoginterface.ini");

		///set texts when trigger still active but dialog is ended
		endDialogText = reader.Get("Text", "end_dialog_text", "");
		endDialogText = sf::String::fromUtf8(endDialogText.begin(), endDialogText.end());
		buttonEndDialogText = reader.Get("Text", "end_dialog_button_text", "");
		buttonEndDialogText = sf::String::fromUtf8(buttonEndDialogText.begin(), buttonEndDialogText.end());

		//get graphical data
		///colors
		sf::Color color = sf::Color
		(
			reader.GetInteger("Color", "r", 0),
			reader.GetInteger("Color", "g", 0),
			reader.GetInteger("Color", "b", 0)
		);

		sf::Color textColor = sf::Color
		(
			reader.GetInteger("Text", "r", 0),
			reader.GetInteger("Text", "g", 0),
			reader.GetInteger("Text", "b", 0)
		);

		///lettersize
		int letterSize = reader.GetInteger("Text", "character_size", 20) * window.screenMatrix.getTotalMatrixScale();

		///path to font
		std::string fontPath = window.getPathtoGame() + TO_RES + reader.Get("Text", "font", "fonts/mainfont.ttf");

		//set
		///Texts
		dialogText.setFillColor(textColor); dialogText.setFont(*m_Font.loadFont(fontPath)); dialogText.setCharacterSize(letterSize);
		nameText.setFillColor(textColor); nameText.setFont(*m_Font.loadFont(fontPath)); nameText.setCharacterSize(letterSize);

		///nameText
		sf::String t = "TrippleTestifiaqate";
		nameText.setString(t);

		///Dialog
		vec2f sizeDialog =
		{
			window.screenMatrix.getRealScreenSize().x - (window.screenMatrix.getRealScreenSize().x / 8),
			window.screenMatrix.getRealScreenSize().y / 6
		};

		dialogBar.setPointCount(4);
		dialogBar.setPoint(0, sf::Vector2f(0, 0));
		dialogBar.setPoint(1, sf::Vector2f(sizeDialog.x, 0));
		dialogBar.setPoint(2, sf::Vector2f(sizeDialog.x, sizeDialog.y));
		dialogBar.setPoint(3, sf::Vector2f(0, sizeDialog.y));

		dialogBar.setFillColor(color);

		///Name
		vec2f sizeName =
		{
			(sizeDialog.x / 5) - 4,
			nameText.getLocalBounds().height * 1.5f
		};

		nameBar.setPointCount(4);
		nameBar.setPoint(0, sf::Vector2f(0, 0));
		nameBar.setPoint(1, sf::Vector2f(sizeName.x, 0));
		nameBar.setPoint(2, sf::Vector2f(sizeName.x, sizeName.y));
		nameBar.setPoint(3, sf::Vector2f(0, sizeName.y));

		nameBar.setFillColor(color);

		//set buttons
		sf::String buttonsText = "";

		for (short unit = 0; unit < 4; unit++)
		{
			buttons[unit].setColors(color, reader.GetBoolean("Buttons", "lighter", true));

			buttons[unit].set
			(
				{ 0, 0 },
				sizeName,
				unit
			);

			buttons[unit].setText
			(
				buttonsText,
				*m_Font.loadFont(fontPath),
				textColor,
				letterSize
			);
		}

		setText(endDialogText);

		std::vector<sf::String> bt;
		bt.emplace_back(buttonEndDialogText);

		setButtons(bt);

		return EXIT_OK;
	}

	void UserInterface::DialogInterface::update(Window &window, Player &player)
	{
		if (itWillShowFlag)
		{
			//task:
			/// set all elements  to need pos
			calculatePos
			(
				window,
				{
					player.getPosCen().x - window.screenMatrix.getRealScreenSizeButHalf().x,
					player.getPosCen().y - window.screenMatrix.getRealScreenSizeButHalf().y
				}
			);

			///
			itWillShowFlag = false;
			isDialog(true);
		}

		//if buttons need
		if (isButtonsShow())
		{
			for (short unit = 0; unit < buttonsToShowCount; unit++)
			{
				buttons[unit].isButtonUnderCursor
				(
					window.drawArea,
					{
						player.getPosCen().x - window.screenMatrix.getRealScreenSizeButHalf().x,
						player.getPosCen().y - window.screenMatrix.getRealScreenSizeButHalf().y
					}
				);
				if (buttons[unit].isButtonPressed())
				{
					answerNumber = unit;
					isButtonsShow(false);
				}
				else answerNumber = 5;
			}
		}

		// If it cannot need a dialog now
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) hide(player);
	}

	void UserInterface::DialogInterface::draw(Window &window)
	{
		if (isDialog())
		{
			window.drawArea.draw(dialogBar);
			window.drawArea.draw(nameBar);
			window.drawArea.draw(dialogText);
			window.drawArea.draw(nameText);

			if (isButtonsShow())
				for (short unit = 0; unit < buttonsToShowCount; unit++)
					buttons[unit].drawButton(window.drawArea);
		}
	}

	void UserInterface::DialogInterface::hide(Player &player)
	{
		player.isOnTrigger(false);
		itWillShowFlag = true;
		isDialog(false);
	}

	void UserInterface::DialogInterface::setButtons(std::vector<sf::String> &buttonsText)
	{
		buttonsToShowCount = buttonsText.size();

		//task:
		/// create buttons for intarface with answers by "role 0 - 4"

		for (short unit = 0; unit < buttonsToShowCount; unit++)
			buttons[unit].reSetText(buttonsText[unit]);
	}

	void UserInterface::DialogInterface::setText(sf::String &text)
	{
		dialogText.setString(text);
	}

	void UserInterface::DialogInterface::setName(sf::String &text)
	{
		nameText.setString(text);
	}

	void UserInterface::DialogInterface::calculatePos(Window &window, const vec2f &nowZeroPos)
	{
		vec2f posDialog =
		{
			nowZeroPos.x + ((window.screenMatrix.getRealScreenSize().x - dialogBar.getLocalBounds().width) / 2),
			nowZeroPos.y + (window.screenMatrix.getRealScreenSize().y - (window.screenMatrix.getRealScreenSize().y / 4.5f))
		};

		vec2f posName =
		{
			posDialog.x,
			posDialog.y + dialogBar.getGlobalBounds().height + 1
		};

		dialogBar.setPosition(posDialog.x, posDialog.y);
		nameBar.setPosition(posName.x, posName.y);

		dialogText.setPosition(posDialog.x + 5, posDialog.y + 2);
		nameText.setPosition
		(
			posName.x + 2,
			posName.y + ((nameBar.getLocalBounds().height / 1.5f) - (nameText.getLocalBounds().height))
		);

		//calculate buttons
		const short sizeOfButton = nameBar.getLocalBounds().width;

		for (short unit = 0; unit < 4; unit++)
		{
			buttons[unit].setPosition({ posName.x + sizeOfButton + 1, posName.y });
			posName.x += sizeOfButton;
		}
	}
}