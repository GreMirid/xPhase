#include "Engine.h"

namespace xphase
{
	void Game::frame(double delta)
	{
		while (window.drawArea.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.drawArea.close();

			//TASK:
			/// bind keys for debug mode
			switch (window.isDebug())
			{
			case true:
				break;
			}

			//TASK:
			/// bind some "e" and "escape" keys to eteract with world
			switch (statusFlag)
			{
			case MainMenuSequnce:
				break;
			case GameSequnce:
				break;
			}
		}

		switch (statusFlag)
		{
		case LoadingSequnce: loadingFrame(delta); break;
		case MainMenuSequnce: mainMenuFrame(delta); break;
		case GameSequnce: gameFrame(delta); break;
		case ExitSequence: endingFrame(delta); break;
		}
	}
}