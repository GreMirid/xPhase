#pragma once

#include "Module.h"

namespace xphase
{
	class UserInterface : public Module
	{
	public:
		int load()
		{
			return EXIT_OK;
		}
	};
}