

//ME&SFML&OTHER
#include "Vector2.h"

#pragma once

namespace xphase
{
	//Functions and Classes

	//
	class EngineLoop
	{
	private:
		float startFrameTime = 0, endFrameTime = 0;
		bool isWindowOpen = false;
	public:
		virtual void openWindow()
		{
			isWindowOpen = true;
		}
		virtual void frame(float delta) {};
		virtual void loop()
		{
			while (isWindowOpen)
			{
				float delta = endFrameTime - startFrameTime;

				//startFrameTime = getTime();

				frame(delta); //do staff

				//endFrameTime = getTime();
			}
		};
	};
}