#include "Engine.h"

namespace xphase
{
	void Game::frame(double delta)
	{
		while (window.drawArea.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.drawArea.close();

			//TASK:
			/// bind some "e" and "escape" keys to eteract with world
			switch (statusFlag)
			{
			case MainMenuSequnce: /* do staff */ break;
			case GameSequnce: gameFrameAction(); break;
			case SettingsSequence: /* do staff */ break;
			}
		}

		switch (statusFlag)
		{
		case LoadingSequnce: loadingFrame(delta); break;
		case MainMenuSequnce: mainMenuFrame(delta); break;
		case GameSequnce: gameFrame(delta); break;
		case SettingsSequence: settingsFrame(delta); break;
		case ExitSequence: endingFrame(delta); break;
		}
	}
}