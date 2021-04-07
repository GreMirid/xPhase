#pragma once

#include "Module.h"

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