#include "Engine.h"

namespace xphase
{
	void Game::loadingFrame(double delta)
	{
		window.drawArea.clear();

		ld.draw(window.drawArea);

		window.drawArea.display();

		start(); /// Create a game with Params.

		setStatus(MainMenuSequnce); // TO MAIN MENU 
	}
}