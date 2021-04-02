
#include "Player.h"
#include "World.h"

#pragma once

namespace xphase
{
	static Player player;
	static World world;

	static void initObjects()
	{
		player.create();
		world.create();
	}
}