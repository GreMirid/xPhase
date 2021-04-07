#include "Engine.h"

namespace xphase
{
	void Game::frame(double delta)
	{
		window.drawArea.clear(sf::Color(0,0,0));

		world.update(delta, player.getLoction());

		window.drawArea.display();
	}
}