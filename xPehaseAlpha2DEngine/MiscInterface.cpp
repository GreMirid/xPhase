#include "UserInterface.h"

namespace xphase
{
	int UserInterface::MiscIntarface::create(Window &window)
	{
		INIReader reader(window.getPathtoGame() + TO_CFG + "config.ini");

		//load from file
		std::string fontPath = window.getPathtoGame() + TO_RES + reader.Get("Font", "path", "fonts/mainfont.ttf");

		int letterSize = reader.GetInteger("Text", "character_size", 20) * window.screenMatrix.getTotalMatrixScale();

		sf::Color textColor = sf::Color
		(
			reader.GetInteger("Text", "r", 0),
			reader.GetInteger("Text", "g", 0),
			reader.GetInteger("Text", "b", 0)
		);

		//past it
		fpsCounter.setFillColor(textColor);
		fpsCounter.setFont(*m_Font.loadFont(fontPath));
		fpsCounter.setCharacterSize(letterSize);

		return EXIT_OK;
	}

	void UserInterface::MiscIntarface::update(Window &window, Player &player)
	{
		fpsCounter.setString(std::to_string(int(window.getCurrentFPS())) + " FPS");

		fpsCounter.setPosition
		(
			((player.getPosCen().x - window.screenMatrix.getRealScreenSizeButHalf().x) + window.screenMatrix.getRealScreenSize().x) - fpsCounter.getLocalBounds().width,
			player.getPosCen().y - window.screenMatrix.getRealScreenSizeButHalf().y
		);
	}

	void UserInterface::MiscIntarface::draw(Window &window)
	{
		window.drawArea.draw(fpsCounter);
	}
}