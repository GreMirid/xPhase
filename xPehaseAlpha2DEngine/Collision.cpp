
#include "World.h"

namespace xphase
{
	int Collision::create(vec2f &pos, vec2f &size)
	{
		setPos(pos);

		setSize(size);

		return EXIT_OK;
	}

	void Collision::update(Player &player, float delta)
	{

	}
}