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

	void Game::initObjects()
	{
		player.create();
		world.create();
	}

	void Game::loadModules()
	{
		scripts.load();
		UI.load(window);
		characters.load();
	}

	void Game::start()
	{
		loadModules(); initObjects();
	}
}