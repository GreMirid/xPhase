#include "Engine.h"

namespace xphase
{
	void Game::gameFrame(double delta)
	{
		setScene(GameSequnce);

		window.drawArea.clear();

		player.update(delta);
		world.update(delta, player.getLocation());

		window.drawArea.display();
	}
}