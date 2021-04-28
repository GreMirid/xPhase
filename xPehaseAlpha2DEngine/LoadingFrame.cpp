#include "Engine.h"

namespace xphase
{
	void Game::loadingFrame(double delta)
	{
		window.drawArea.clear(sf::Color(0, 0, 0));

		ld.draw(window.drawArea);

		window.drawArea.display();

		start(); /// Create a game with Params.

		setStatus(MainMenuSequnce); // TO MAIN MENU 
	}
}