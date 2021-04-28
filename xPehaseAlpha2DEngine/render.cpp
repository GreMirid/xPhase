
#include "Engine.h"

namespace xphase
{
	void Game::render()
	{
		//TASK:
		/// Just prepare a game to start.
		ld.create(window);

		setStatus(LoadingSequnce);

		loop();
	}
}