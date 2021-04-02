#include "Core.h"

#pragma once

namespace xphase
{
	class Module
	{
	public:
		virtual int load()
		{
			return 0;
		};
		virtual void unload()
		{
			delete this;
		};
	};
}