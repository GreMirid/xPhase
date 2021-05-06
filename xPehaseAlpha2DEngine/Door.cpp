
#include "World.h"

namespace xphase
{
	int Door::create(vec2f &pos, int to_door, int to_location)
	{
		setPos(pos);

		setSize({ 100, 100 });

		toDoor = to_door;
		toLocation = to_location;

		return EXIT_OK;
	}

	void Door::update(Player &player)
	{

	}
}