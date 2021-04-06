#pragma once

#include "Object.h"

namespace xphase
{
	class Door : Object
	{

	};

	class Trigger : Object
	{

	};

	class Collision : public Object
	{

	};

	class Layer : public Object
	{

	};

	class Scene : public Object
	{

	};

	class World
	{
	public:
		int create()
		{
			return EXIT_OK;
		}
	};
}