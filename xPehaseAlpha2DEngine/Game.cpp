#include "Engine.h"

namespace xphase
{
	Game::Game(bool debug, const std::string& filePath)
	{
		//TASK:
		///Create Window from params in ini file and params from command line
		window.isDebug(debug);

		openWindow(filePath);

		m_Window = &window;

		//Load Standarts
		m_Textures.create(window);
		m_Font.create(window);

		m_gameLogic.create(this);

		render();
	}

	void Game::loadModules()
	{
		UI.load(window);
		dialogScripts.load(window);
	}

	void Game::initObjects()
	{
		player.create(window);
		world.create(window);
	}

	void Game::start()
	{
		loadModules();
		initObjects();
	}
}