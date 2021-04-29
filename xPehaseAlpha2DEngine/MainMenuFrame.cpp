#include "Engine.h"

namespace xphase
{
	void Game::mainMenuFrame(double delta)
	{
		setScene(MainMenuSequnce);

		window.drawArea.clear();

		UI.mM.update(window, delta);

		setStatus(UI.mM.draw(window));

		window.drawArea.display();
	}
}