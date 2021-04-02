#include "Engine.h"

namespace xphase
{
	Game::Game(const char* initPath)
	{
		//TASK:
		///Create Window from params in ini file 
		
		//auto init = initPath;

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