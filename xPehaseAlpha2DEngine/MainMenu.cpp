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
			std::string path = window.getPathtoGame() + TO_RES + reader.GetString("Image", "path", "");

			//TASK:
			/// Get Loaded Texture and Shrink it to all Window
			backgraundSprite.setTexture(*m_Textures.loadTexture(path));
			backgraundSprite.setPosition(0, 0);

			backgraundSprite.setScale
			(
				window.screenMatrix.getRealScreenSize().x / backgraundSprite.getTexture()->getSize().x,
				window.screenMatrix.getRealScreenSize().y / backgraundSprite.getTexture()->getSize().y
			);

			break;
		}

		//TASK:
		/// Get params about buttons from INI and calculate size of buttons block

		int count = reader.GetInteger("Main", "buttons_count", 0) - 1;

		/// get the size of full block and get central position to move all block on screen
		vec2f buttonsSize =
		{
			reader.GetInteger("Buttons", "buttons_size_x", 0) * window.screenMatrix.getMatrixScale().x,
			reader.GetInteger("Buttons", "buttons_size_y", 0) * window.screenMatrix.getMatrixScale().y
		};

		vec2f buttonsBlockSize =
		{
			buttonsSize.x,
			(buttonsSize.y * count) + count
		};

		vec2f buttonsBlockPos = { 0, 0 };

		vec2f buttonsPosFromIni = { reader.GetInteger("Buttons", "buttons_x", 0) , reader.GetInteger("Buttons", "buttons_y", 0) };

		/// x
		if (reader.GetString("Buttons", "buttons_x", "") == "SC_A")
			buttonsBlockPos.x = (window.screenMatrix.getRealScreenSize().x / 2) - (buttonsBlockSize.x / 2);
		else
			buttonsBlockPos.x = window.screenMatrix.getRealPoint(buttonsPosFromIni).x;

		/// y
		if (reader.GetString("Buttons", "buttons_y", "") == "SC_A")
			buttonsBlockPos.y = (window.screenMatrix.getRealScreenSize().y / 2) - (buttonsBlockSize.y / 2);
		else
			buttonsBlockPos.y = window.screenMatrix.getRealPoint(buttonsPosFromIni).y;

		/// create buttons
		/// set font
		std::string font_path = window.getPathtoGame() + TO_RES + reader.GetString("Buttons", "buttons_font", "");

		colorB.r = reader.GetInteger("Buttons", "buttons_clr_t_r", 0);
		colorB.g = reader.GetInteger("Buttons", "buttons_clr_t_g", 0);
		colorB.b = reader.GetInteger("Buttons", "buttons_clr_t_b", 0);

		for (int unit = 0; unit < (count + 1); unit++)
		{
			/// Choose Button
			switch (unit)
			{
			case 0: buttonNum = "FirstButton"; break;
			case 1: buttonNum = "SecondButton"; break;
			case 2: buttonNum = "ThirdButton"; break;
			case 3: buttonNum = "FourButton"; break;
			default: return EXIT_OK;
			}

			/// Choose role
			if (reader.Get(buttonNum, "role", "") == "play") role = Play;
			else if (reader.Get(buttonNum, "role", "") == "configure") role = Configure;
			else if (reader.Get(buttonNum, "role", "") == "exit") role = Quit;
			else if (reader.Get(buttonNum, "role", "") == "extra") role = Extra;
			else role = DoNotExec;

			/// Create a temp Button
			Button temp;

			/// Set Colors for Buttons
			temp.setColors
			(
				sf::Color
				(
					reader.GetInteger("Buttons", "buttons_color_r", 255),
					reader.GetInteger("Buttons", "buttons_color_g", 255),
					reader.GetInteger("Buttons", "buttons_color_b", 255)
				),
				reader.GetBoolean("Buttons", "buttons_is_light", true)
			);

			/// Give to Button other data
			temp.set
			(
				buttonsBlockPos,
				buttonsSize,
				role
			);

			/// Set Next Y pos for button
			buttonsBlockPos.y += buttonsSize.y + 1;

			/// Get Text for Button from ini
			sf::String textB = reader.GetString(buttonNum, "text", "");

			/// to unf**k with other languages
			textB = sf::String::fromUtf8(textB.begin(), textB.end());

			temp.setText
			(
				textB,
				*m_Font.loadFont(font_path),
				colorB,
				reader.GetInteger("Buttons", "buttons_f_size", 0) * ( (window.screenMatrix.getMatrixScale().x + window.screenMatrix.getMatrixScale().y) / 2)
			);

			/// Add buttons to Objects
			buttons.emplace_back(temp);
		}

		/// Game Logo

		std::string path_to_logo = window.getPathtoGame() + TO_RES + reader.Get("Logo", "path", "ui/logo.png");

		gameLogo.setTexture(*m_Textures.loadTexture(path_to_logo));
		gameLogo.setScale
		(
			reader.GetReal("Logo", "scale_x", 0) * window.screenMatrix.getMatrixScale().x,
			reader.GetReal("Logo", "scale_y", 0) * window.screenMatrix.getMatrixScale().y

		);

		vec2f logoPos = { 0, 0 };

		vec2f logoPosFromIni =
		{
				reader.GetReal("Logo", "pos_x", 0),
				reader.GetReal("Logo", "pos_y", 0)
		};

		/// x
		if (reader.GetString("Logo", "pos_x", "") == "SC_A")
			logoPos.x = (window.screenMatrix.getRealScreenSize().x / 2) - ((gameLogo.getTexture()->getSize().x * gameLogo.getScale().x)/ 2);
		else
			logoPos.x = window.screenMatrix.getRealPoint(logoPosFromIni).x;

		/// y
		if (reader.GetString("Logo", "pos_y", "") == "SC_A")
			logoPos.y = (window.screenMatrix.getRealScreenSize().y / 2) - ((gameLogo.getTexture()->getSize().y * gameLogo.getScale().y) / 2);
		else
			logoPos.y = window.screenMatrix.getRealPoint(logoPosFromIni).y;

		gameLogo.setPosition(logoPos.x, logoPos.y);

		///if is a game
		continueGame = reader.Get("Main", "continue_game_text", "Continue Game");
		continueGame = sf::String::fromUtf8(continueGame.begin(), continueGame.end());

		return EXIT_OK;
	}

	int UserInterface::MainMenu::draw( Window &window )
	{
		switch (isJustOnlyColor())
		{
		case true: window.drawArea.clear(backgraundColor); break;
		case false: window.drawArea.draw(backgraundSprite); break;
		}

		window.drawArea.draw(gameLogo);

		for (size_t unit = 0; unit < buttons.size(); unit++)
			buttons[unit].drawButton(window.drawArea);

		return isMainMenuSequence();
	}

	void UserInterface::MainMenu::update(Window &window, float delta)
	{
		isMainMenuSequence(MainMenuSequnce);

		for (size_t unit = 0; unit < buttons.size(); unit++)
		{
			/// Activate buttons
			buttons[unit].isButtonUnderCursor(window.drawArea, { 0, 0 });

			/// 
			if (buttons[unit].isButtonPressed())
			{
				switch (buttons[unit].getRole())
				{
				case Play:
					isMainMenuSequence(GameSequnce);
					isAlreadyGame = true;
					break;
				case Configure: isMainMenuSequence(SettingsSequence); break;
				case Quit: isMainMenuSequence(ExitSequence); break;
				case Extra: /*isMainMenuSequence(777);*/ break;
				}
			}
		}

		if (isAlreadyGame && !isChanged)
		{
			for (size_t unit = 0; unit < buttons.size(); unit++)
			{
				if (buttons[unit].getRole() == Play)
				{
					buttons[unit].reSetText(continueGame);
				}
			}
			isChanged = true;
		}
	}
}