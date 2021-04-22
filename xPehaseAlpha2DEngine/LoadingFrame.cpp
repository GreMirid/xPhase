#include "Engine.h"

namespace xphase
{
	void Game::loadingFrame(double delta)
	{
		window.drawArea.clear(sf::Color(0, 0, 0));

		window.drawArea.draw(ld.panel);
		window.drawArea.draw(ld.loaingText);

		window.drawArea.display();

		///Create a game with Params.
		start();

		setStatus(GameSequnce); // TO MAIN MENU 
	}
}