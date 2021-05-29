#include "Engine.h"

namespace xphase
{
	void Game::endingFrame(double delta)
	{
		window.drawArea.setView(window.camera);
		window.camera.setCenter(window.screenMatrix.getRealScreenSizeButHalf().x, window.screenMatrix.getRealScreenSizeButHalf().y);

		window.drawArea.close();
	}
}