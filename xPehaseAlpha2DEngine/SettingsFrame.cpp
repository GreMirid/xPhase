#include "Engine.h"

namespace xphase
{
	void Game::settingsFrame(double delta)
	{
		window.drawArea.clear();

		window.drawArea.setView(window.camera);
		window.camera.setCenter(window.screenMatrix.getRealScreenSizeButHalf().x, window.screenMatrix.getRealScreenSizeButHalf().y);

		window.isDrawCursor(true);

		UI.st.update(fromScene, window, delta);

		setStatus(UI.st.draw(window));

		window.drawArea.display();
	}
}