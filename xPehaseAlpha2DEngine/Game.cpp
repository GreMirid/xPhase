#include "Engine.h"

namespace xphase
{
	Game::Game(bool debug, const std::string& filePath)
	{
		//TASK:
		///Create Window from params in ini file and params from command line
		window.isDebug(debug);

		openWindow(filePath);

		render();
	}

	void Game::start()
	{
		loadModules();

		initObjects();
	}
}