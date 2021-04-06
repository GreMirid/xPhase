#pragma once

#include "Object.h"

namespace xphase
{
	class Player : public Object
	{
	public:
		int create()
		{
			return EXIT_OK;
		}
	};
}