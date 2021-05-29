#include "Engine.h"

namespace xphase
{
	void Game::gameFrame(double delta)
	{
		setScene(GameSequnce);

		window.drawArea.setView(window.camera);

		window.drawArea.clear();

		bool notAGame = UI.igme.update(window, player, delta);

		switch (notAGame)
		{
		case false:
			world.update(window, delta, player);
			player.update(window, delta);
			break;
		}

		window.isDrawCursor(notAGame);

		world.draw(window, player);

		player.draw(window);

		UI.igme.draw(window);

		window.drawArea.display();
	}
}