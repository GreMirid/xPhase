#include "UserInterface.h"

namespace xphase
{
	int UserInterface::MainMenu::create(Window& window)
	{
		//TASK:
		/// Load params from ini
		INIReader reader(window.getPathtoGame() + TO_CFG + "mainmenu.ini");

		if (reader.ParseError() != 0) return EXIT_ERROR;

		switch (reader.GetBoolean("Main", "is_just_color", true))
		{
		case true:
			isJustOnlyColor(true);

			backgraundColor = sf::Color(reader.GetInteger("Color", "r", 255), reader.GetInteger("Color", "g", 255), reader.GetInteger("Color", "b", 255));

			break;

		case false:
			// Spagetti
			if (!backgraundTexture.loadFromFile(window.getPathtoGame() + TO_RES + reader.GetString("Image", "path", "")))
			{
				isJustOnlyColor(true); return EXIT_ERROR;
			}

			//TASK:
			/// Get Loaded Texture and Shrink it to all Window
			backgraundSprite.setTexture(backgraundTexture);
			backgraundSprite.setPosition(0, 0);
			backgraundSprite.setScale(window.screenMatrix.getRealScreenSize().x / backgraundTexture.getSize().x, window.screenMatrix.getRealScreenSize().y / backgraundTexture.getSize().y);

			break;
		}

		//TASK:
		/// Get params about buttons from INI and calculate size of buttons block

		int count = reader.GetInteger("Main", "buttons_count", 0);

		vec2f buttonsBlockSize = { reader.GetInteger("Buttons", "buttons_size_x", 0), (reader.GetInteger("Buttons", "buttons_size_y", 0) * count) + count};

		//i'm do this late

		return EXIT_OK;
	}
	int UserInterface::MainMenu::draw(Window & window)
	{
		switch (isJustOnlyColor())
		{
		case true: window.drawArea.clear(backgraundColor); break;
		case false: window.drawArea.draw(backgraundSprite); break;
		}

		for (size_t unit = 0; unit < buttons.size(); unit++)
			buttons[unit].drawButton(window.drawArea);

		return isMainMenuSequence();
	}
}