#include "Engine.h"

namespace xphase
{
	Game::Game(const char initPath[127])
	{
		//������:
		///����������� �������� ���� �� ��������� ���������� � ini ����� 
		auto init = initPath;

		///��������� ���� � �����������.
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