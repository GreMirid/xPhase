#include "Core.h"

namespace xphase
{
	void EngineLoop::openWindow()
	{
		//do staff
		isWindowOpen = true;
	}

	void EngineLoop::frame(float delta)
	{
		//do staff
	}

	void EngineLoop::loop()
	{
		while (isWindowOpen)
		{
			float delta = endFrameTime - startFrameTime;

			//startFrameTime = getTime();

			frame(delta); //do staff

			//endFrameTime = getTime();
		}
	}

	void EngineLoop::set()
	{
		//do staff
	}
}