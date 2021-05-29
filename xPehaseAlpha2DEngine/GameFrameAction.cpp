#include "Engine.h"

namespace xphase
{
	void Game::gameFrameAction()
	{
		switch (window.isDebug())
		{
		case true:
			//Show borders of 
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::O))
				window.isDrawBorders(true);
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::L))
				window.isDrawBorders(false);
			break;
		}

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
		{
			if (UI.igme.isGameMenuSequence())
				UI.igme.isGameMenuSequence(false);
			else
				UI.igme.isGameMenuSequence(true);
		}
	}
}