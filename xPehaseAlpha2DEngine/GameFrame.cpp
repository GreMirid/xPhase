#include "Engine.h"

namespace xphase
{
	void Game::gameFrame(double delta)
	{
		setScene(GameSequnce);

		window.drawArea.setView(window.camera);

		window.drawArea.clear();

		world.update(window, delta, player);
		player.update(window, delta);
		
		world.draw(window, player);

		player.draw(window);

		window.drawArea.display();
	}
}