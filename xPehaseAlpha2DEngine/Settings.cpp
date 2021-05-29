#include "UserInterface.h"

namespace xphase
{
	int UserInterface::Settings::create(Window &window)
	{
		/// PLACEHOLDER BUTTON
		INIReader reader(window.getPathtoGame() + TO_CFG + "mainmenu.ini");

		std::string path_to_font = window.getPathtoGame() + TO_RES + reader.GetString("Buttons", "buttons_font", "");

		button.setColors
		(
			sf::Color
			(
				reader.GetInteger("Buttons", "buttons_color_r", 255),
				reader.GetInteger("Buttons", "buttons_color_g", 255),
				reader.GetInteger("Buttons", "buttons_color_b", 255)
			),
			reader.GetBoolean("Buttons", "buttons_is_light", true)
		);

		button.set({0 , 0}, {230, 40}, 0);

		sf::String textB = "Back"; sf::Color colorB;

		colorB.r = reader.GetInteger("Buttons", "buttons_clr_t_r", 0);
		colorB.g = reader.GetInteger("Buttons", "buttons_clr_t_g", 0);
		colorB.b = reader.GetInteger("Buttons", "buttons_clr_t_b", 0);

		button.setText(textB, *m_Font.loadFont(path_to_font), colorB, reader.GetInteger("Buttons", "buttons_f_size", 0));

		return EXIT_OK;
	}

	int UserInterface::Settings::draw(Window &window)
	{
		button.drawButton(window.drawArea);

		return statFlag;
	}

	void UserInterface::Settings::update(int status, Window &window ,float delta)
	{
		from = status; statFlag = SettingsSequence;

		button.isButtonUnderCursor(window.drawArea, {0, 0});

		if (button.isButtonPressed()) statFlag = from;
	}
}