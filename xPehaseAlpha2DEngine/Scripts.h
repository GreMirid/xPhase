#pragma once

#include "Module.h"

namespace xphase
{
	//Code for Triggers
	class Scripts : public Module
	{
	public:
		int load(Window &window);
	};

	extern Scripts scripts;
}