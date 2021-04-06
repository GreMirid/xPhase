
#include "Module.h"

#pragma once

namespace xphase
{
	class Scenario : public Module
	{
	public:
		int load()
		{
			return EXIT_OK;
		}
	};
}