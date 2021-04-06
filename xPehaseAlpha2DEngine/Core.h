#pragma once

//
#include <string>

//
#include "Vector2.h"
#include "Returns.h"

//
#

//
namespace xphase
{
	//Functions and Classes for Game itself

	class EngineLoop
	{
	public:
		//
		float startFrameTime = 0, endFrameTime = 0;
		bool isWindowOpen = false;

		//
		virtual void openWindow();
		virtual void frame(float delta);
		virtual void loop();
		
		//
		virtual void set();
	};

}