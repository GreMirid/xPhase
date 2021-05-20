#include "Engine.h"

namespace xphase
{
	void Game::gameFrameAction()
	{
		switch (window.isDebug())
		{
		case true:
			//Show borders of 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
				window.isDrawBorders(true);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
				window.isDrawBorders(false);
			break;
		}
	}
}