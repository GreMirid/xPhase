#include "Engine.h"

namespace xphase
{
	void Game::frame(double delta)
	{
		window.drawArea.clear(sf::Color(0,0,0));

		player.update(delta);
		world.update(delta, player.getLocation());

		window.drawArea.display();
	}
}