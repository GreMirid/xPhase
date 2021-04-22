#include "Engine.h"

namespace xphase
{
	void Game::mainMenuFrame(double delta)
	{
		window.drawArea.clear(sf::Color(0, 0, 0));

		window.drawArea.display();
	}
}