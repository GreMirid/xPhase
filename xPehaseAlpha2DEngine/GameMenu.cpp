#include "UserInterface.h"

namespace xphase
{
	int UserInterface::GameMenu::create(Window &window)
	{
		//modificator for other resolutions

		vec2f mod =
		{
			window.screenMatrix.getMatrixScale().x,
			window.screenMatrix.getMatrixScale().y
		};

		//task:
		/// create game menu by ini file

		INIReader reader(window.getPathtoGame() + TO_CFG + "gamemenu.ini");
		std::string path_to_font = window.getPathtoGame() + TO_RES + reader.Get("Menu", "font", "");

		// Get Colors
		sf::Color *panelColor = new sf::Color(
			reader.GetInteger("Menu", "r", 0),
			reader.GetInteger("Menu", "g", 0),
			reader.GetInteger("Menu", "b", 0));

		sf::Color *textPanelColor = new sf::Color(
			reader.GetInteger("Menu Text", "r", 0),
			reader.GetInteger("Menu Text", "g", 0),
			reader.GetInteger("Menu Text", "b", 0));

		sf::Color *buttonsColor = new sf::Color(
			reader.GetInteger("Buttons", "r", 0),
			reader.GetInteger("Buttons", "g", 0),
			reader.GetInteger("Buttons", "b", 0));

		sf::Color *textButtonsColor = new sf::Color(
			reader.GetInteger("Buttons", "text_r", 0),
			reader.GetInteger("Buttons", "text_g", 0),
			reader.GetInteger("Buttons", "text_b", 0));

		// Get text
		sf::String text_menu = reader.Get("Menu Text", "text", "Menu");
		text_menu = sf::String::fromUtf8(text_menu.begin(), text_menu.end());

		// Game Menu Panel

		///Calculate
		size = 
		{
			window.screenMatrix.getRealScreenSizeButHalf().x / 2,
			window.screenMatrix.getRealScreenSizeButHalf().y / 0.7f
		};

		vec2f pos =
		{
			window.screenMatrix.getRealScreenSize().x,
			window.screenMatrix.getRealScreenSizeButHalf().y - (size.y / 2)
		};
		
		///Set panel
		menuDraw.setPointCount(4);

		menuDraw.setPoint(0, sf::Vector2f(0, 0));
		menuDraw.setPoint(1, sf::Vector2f(size.x, 0));
		menuDraw.setPoint(2, sf::Vector2f(size.x, size.y));
		menuDraw.setPoint(3, sf::Vector2f(0, size.y));

		menuDraw.setFillColor(*panelColor);

		menuDraw.setPosition( pos.x, pos.y );

		///Set text
		text.setFont(*m_Font.loadFont(path_to_font));
		text.setFillColor(*textPanelColor);
		text.setString(text_menu);
		text.setCharacterSize(reader.GetInteger("Menu Text", "character_size", 12) * ((mod.x + mod.y) / 2));

		///Set Buttons
		std::string button_name;

		vec2f size_button = 
		{
			reader.GetReal("Buttons", "size_x", 0.f) * mod.x,
			reader.GetReal("Buttons", "size_y", 0.f) * mod.y
		};

		int role = DoNotExec;

		bool isLigt = reader.GetBoolean("Buttons", "is_light", true);

		int characterSize = reader.GetInteger("Buttons", "character_size", 12) * ((mod.x + mod.y) / 2);

		for (short unit = 0; unit < 3; unit++)
		{
			switch (unit)
			{
			case 0: button_name = "First Button"; break;
			case 1: button_name = "Second Button"; break;
			case 2: button_name = "Third Button"; break;
			}

			sf::String text_button = reader.Get(button_name, "text", "");
			text_button = sf::String::fromUtf8(text_button.begin(), text_button.end());

			/// Choose role
			if (reader.Get(button_name, "role", "") == "menu") role = toMainMenu;
			else if (reader.Get(button_name, "role", "") == "config") role = Configure;
			else if (reader.Get(button_name, "role", "") == "exit") role = Quit;
			else role = DoNotExec;

			buttons[unit].setColors(*buttonsColor, isLigt);

			buttons[unit].set
			(
				{0, 0},
				size_button,
				role
			);

			buttons[unit].setText(text_button, *m_Font.loadFont(path_to_font), *textButtonsColor, characterSize);
		}

		return EXIT_OK;
	}

	bool UserInterface::GameMenu::update(Window &window, Player &player, float delta)
	{
		//create an animation
		switch (isGameMenuSequence())
		{
		case true:
			//set an animation
			needPoint =
			{
				player.getPosCen().x + window.screenMatrix.getRealScreenSizeButHalf().x - (size.x + window.screenMatrix.getRealScreenSize().x / 16),
				player.getPosCen().y - size.y / 2
			};

			switch (isNotEndAnimation)
			{
			case true:
				animation(delta);
				break;

			case false:

				//buttons update
				for (short unit = 0; unit < 3; unit++)
				{
					buttons[unit].isButtonUnderCursor
					(
						window.drawArea,
						{
							player.getPosCen().x - window.screenMatrix.getRealScreenSizeButHalf().x,
							player.getPosCen().y - window.screenMatrix.getRealScreenSizeButHalf().y
						}
					);
				}

				break;
			}
			break;
		case false:
			//set null position for menu
			menuDraw.setPosition
			(
				player.getPosCen().x + window.screenMatrix.getRealScreenSizeButHalf().x,
				player.getPosCen().y - size.y / 2
			);
			isNotEndAnimation = true;
			break;
		}

		return isGameMenuSequence();
	}

	void UserInterface::GameMenu::draw(Window &window)
	{
		switch (isGameMenuSequence())
		{
		case true:
			window.drawArea.draw(menuDraw);
			
			switch (isNotEndAnimation)
			{
			case false:
				window.drawArea.draw(text);
				for (short unit = 0; unit < 3; unit++)
					buttons[unit].drawButton(window.drawArea);
				break;
			}
			break;
		}
	}

	int UserInterface::GameMenu::buttonsWasPressed()
	{
		for (short unit = 0; unit < 3; unit++)
		{
			if (buttons[unit].isButtonPressed())
			{
				switch (buttons[unit].getRole())
				{
				case toMainMenu: return MainMenuSequnce;
				case Configure: return SettingsSequence;
				case Quit: return ExitSequence;
				default: break;
				}
				break;
			}
		}

		return GameSequnce;
	}

	void UserInterface::GameMenu::animation(float delta)
	{
		//TASK:
		/// Mathematicly create an animation of panel

		if (menuDraw.getPosition().x > needPoint.x)
		{
			menuDraw.move(-(size.x / 32 * (delta * 0.0001f) ), 0);
			isNotEndAnimation = true;
		}
		else
		{
			//task:
			/// set positions for objects

			text.setPosition
			(
				menuDraw.getPosition().x + ((size.x / 2) - (text.getLocalBounds().width / 2)),
				menuDraw.getPosition().y + size.x / 8
			);
			
			vec2f buttonsPos =
			{
				menuDraw.getPosition().x + ((size.x / 2) - (buttons[0].getSize().x / 2)),
				menuDraw.getPosition().y + size.y - ((buttons[0].getSize().y * 3) + size.x / 2)
			};

			for (short unit = 0; unit < 3; unit++)
			{
				buttons[unit].setPosition(buttonsPos);

				buttonsPos.y += buttons[0].getSize().y + 1;
			}

			isNotEndAnimation = false;
		}
	}
}