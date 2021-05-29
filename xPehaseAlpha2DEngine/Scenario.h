#pragma once

#include "Module.h"

namespace xphase
{
	//Load all xphase_sripts by directory
	class Scenario : public Module
	{
	public:
		int load(Window &window);
	};

	extern Scenario dialogScripts;
}