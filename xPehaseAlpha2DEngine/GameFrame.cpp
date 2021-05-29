#include "Engine.h"

namespace xphase
{
	void Game::gameFrame(double delta)
	{
		setScene(GameSequnce);

		//Move Camera to Player
		window.camera.setCenter(player.getPosCen().x, player.getPosCen().y);
		window.drawArea.setView(window.camera);

		window.drawArea.clear();

		bool notAGame = UI.igme.update(window, player, delta);

		switch (notAGame)
		{
		case true:
			setStatus(UI.igme.buttonsWasPressed());
			break;
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