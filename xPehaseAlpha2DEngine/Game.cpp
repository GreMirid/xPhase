#include "Engine.h"

namespace xphase
{
	Game::Game(const std::string& filePath)
	{
		//TASK:
		///Create Window from params in ini file 
		openWindow(filePath);

		///Create a game with Params.
		start();
	}

	void Game::start()
	{
		loadModules();

		initObjects();

		render();
	}
}