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

		UI.misc.update(window, player);

		bool notAGame = player.isOnTrigger() || UI.inGameMenu.update(window, player, delta);

		if (notAGame)
		{
			if (player.isOnTrigger()) UI.dialogInterface.update(window, player);
			else setStatus(UI.inGameMenu.buttonsWasPressed());
		}
		else
		{
			world.update(window, delta, player);
			player.update(window, delta);
		}

		window.isDrawCursor(notAGame);

		world.draw(window, player);
		player.draw(window);
		world.drawSceneLayers(window, player);
		UI.draw(window);

		window.drawArea.display();
	}
}