#include "Engine.h"

namespace xphase
{
	void Game::gameFrameAction()
	{
		if (window.isDebug())
		{
			//Show borders of 
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::O))
				window.isDrawBorders(true);
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::L))
				window.isDrawBorders(false);
		}

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
		{
			if (UI.inGameMenu.isGameMenuSequence())
				UI.inGameMenu.isGameMenuSequence(false);
			else
				UI.inGameMenu.isGameMenuSequence(true);
		}
	}
}