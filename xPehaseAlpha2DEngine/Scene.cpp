#include "World.h"

namespace xphase
{
	int Scene::create()
	{
		return EXIT_OK;
	}

	void Scene::update(double delta)
	{
		for (size_t objects = 0; objects < collisions.size(); objects++)
		{
			if (collisions[objects].isEnabled())
				collisions[objects].update(delta);
		}
	}
}