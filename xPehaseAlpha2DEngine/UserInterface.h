#pragma once

#include "Module.h"

namespace xphase
{
	class UserInterface : public Module
	{
	public:
		int load()
		{
			//HOW TO MAKE ANOTHER RESOLUTION TO UI WHEN YOU PLAYING IN GAME

			return EXIT_OK;
		}
	};
}