
//Engine
#include "Modules.h"
#include "Objects.h"

#include "EngineLoop.h"

namespace xphase
{
	void createGame();	

	class Game : public EngineLoop
	{
	public:
		Game(const char* initPath = "game.ini");

	private:
		void start();
		void render();
	};
}