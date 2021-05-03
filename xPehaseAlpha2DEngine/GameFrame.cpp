#include "Engine.h"

namespace xphase
{
	void Game::gameFrame(double delta)
	{
		setScene(GameSequnce);

		window.drawArea.clear(sf::Color::White);

		player.update(window, delta);
		world.update(delta, player.getLocation());
		
		player.draw(window);

		window.drawArea.display();
	}
}