#include "Engine.h"

namespace xphase
{
	void Game::mainMenuFrame(double delta)
	{
		window.drawArea.clear();

		setStatus(UI.mM.draw(window));

		window.drawArea.display();
	}
}