#include "Engine.h"

namespace xphase
{
	void Game::settingsFrame(double delta)
	{
		window.drawArea.clear();

		window.isDrawCursor(true);

		UI.st.update(fromScene, window, delta);

		setStatus(UI.st.draw(window));

		window.drawArea.display();
	}
}