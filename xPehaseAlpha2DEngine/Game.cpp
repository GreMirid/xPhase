#include "Engine.h"

namespace xphase
{
	Game::Game(const char initPath[127])
	{
		//ЗАДАЧА:
		///Реализовать создание окна по указанным параметрам в ini файле 
		auto init = initPath;

		///Запустить игру с параметрами.
		start();
	}

	void Game::start()
	{
		//Load Engine data to RAM and VRAM
		loadModules();

		//Load Game data to RAM and VRAM
		initObjects();

		//and create Engine Loop
		render();
	}
}