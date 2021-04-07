#pragma once

//
#include "Player.h"
#include "World.h"

namespace xphase
{
	//
	static Player player;
	static World world;

	//
	static void initObjects()
	{
		player.create();
		world.create();
	}
}