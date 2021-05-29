#include "UserInterface.h"

namespace xphase
{
	int UserInterface::GameMenu::create(Window &window)
	{
		//task:
		/// create game menu by ini file

		INIReader reader(window.getPathtoGame() + TO_CFG + "gamemenu.ini");
		std::string path_to_font = window.getPathtoGame() + TO_RES + reader.Get("Main", "font", "");

		// Get Colors
		sf::Color panelColor;
		panelColor.r = reader.GetInteger("Menu", "r", 0);
		panelColor.g = reader.GetInteger("Menu", "g", 0);
		panelColor.b = reader.GetInteger("Menu", "b", 0);

		sf::Color textPanelColor;
		textPanelColor.r = reader.GetInteger("Menu Text", "r", 0);
		textPanelColor.g = reader.GetInteger("Menu Text", "g", 0);
		textPanelColor.b = reader.GetInteger("Menu Text", "b", 0);

		sf::Color buttonsColor;
		buttonsColor.r = reader.GetInteger("Buttons", "r", 0);
		buttonsColor.g = reader.GetInteger("Buttons", "g", 0);
		buttonsColor.b = reader.GetInteger("Buttons", "b", 0);

		sf::Color textButtonsColor;
		textButtonsColor.r = reader.GetInteger("Buttons", "text_r", 0);
		textButtonsColor.g = reader.GetInteger("Buttons", "text_g", 0);
		textButtonsColor.b = reader.GetInteger("Buttons", "text_b", 0);

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
		
		///Set
		menuDraw.setPointCount(4);

		menuDraw.setPoint(0, sf::Vector2f(0, 0));
		menuDraw.setPoint(1, sf::Vector2f(size.x, 0));
		menuDraw.setPoint(2, sf::Vector2f(size.x, size.y));
		menuDraw.setPoint(3, sf::Vector2f(0, size.y));

		menuDraw.setFillColor(panelColor);

		menuDraw.setPosition( pos.x, pos.y );

		return EXIT_OK;
	}

	bool UserInterface::GameMenu::update(Window &window, Player &player)
	{
		//create an animation
		switch (isGameMenuSequence())
		{
		case true:

			needPoint =
			{
				player.getPosCen().x + window.screenMatrix.getRealScreenSizeButHalf().x - (size.x + window.screenMatrix.getRealScreenSize().x / 16),
				player.getPosCen().y - size.y / 2
			};

			switch (isNotEndAnimation)
			{
			case false:
				animation();
				break;

			case true:
				break;
			}
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
			//window.drawArea.draw(text);

			switch (isNotEndAnimation)
			{
			case false:
				for (short unit = 0; unit < 3; unit++)
					buttons[unit].drawButton(window.drawArea);
				break;
			}
			break;
		}
	}

	void UserInterface::GameMenu::animation()
	{
		//TASK:
		/// Mathematicly create an animation of panel

		menuDraw.setPosition( needPoint.x, needPoint.y );
	}
}