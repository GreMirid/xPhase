
#include "Engine.h"

namespace xphase
{
	void Game::render()
	{
		//TASK:
		/// Just prepare a game to start.
		setStatus(LoadingSequnce);

		ld.create(window.screenMatrix.getRealScreenSize());

		loop();
	}
}