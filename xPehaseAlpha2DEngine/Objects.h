
#include "Player.h"
#include "World.h"

namespace xphase
{
	Player player;
	World world;

	void initObjects()
	{
		player.create();
		world.create();
	}
}