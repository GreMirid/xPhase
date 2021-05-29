#include "Engine.h"

namespace xphase
{
	void Game::mainMenuFrame(double delta)
	{
		window.isDrawCursor(true);

		window.drawArea.setView(window.camera);
		window.camera.setCenter(window.screenMatrix.getRealScreenSizeButHalf().x, window.screenMatrix.getRealScreenSizeButHalf().y);

		setScene(MainMenuSequnce);

		window.drawArea.clear();

		UI.mM.update(window, delta);

		setStatus(UI.mM.draw(window));

		window.drawArea.display();
	}
}