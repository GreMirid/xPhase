
//Engine
#include "Modules.h"
#include "Objects.h"

namespace xphase
{
	void createGame();

	class Game
	{
	public:
		Game(const char initPath[127] = "game.ini");

	private:
		void start();
		void render();
	};
}