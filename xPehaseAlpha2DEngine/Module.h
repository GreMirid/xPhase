#pragma once

#include "Core.h"

namespace xphase
{
	class Module
	{
	public:
		virtual int load()		{ return EXIT_NULL; }
		virtual void unload()	{ delete this; }
	};
}