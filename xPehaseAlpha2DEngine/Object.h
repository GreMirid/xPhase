#pragma once

#include "Core.h"

//#include <iostream>

namespace xphase
{
	class Object
	{
	public:
		virtual int create()						{ return EXIT_NULL; }
		virtual void destroy()						{ delete this; }

		virtual void update(double delta)			{ /*std::cout << "Object ";*/ };

		virtual void enable()						{ isEnable = true; }
		virtual void disable()						{ isEnable = false; }

	public:
		//Getter
		virtual vec2f getPos()						{ return pos; }
		virtual vec2f getSize()						{ return size; }
		virtual vec2f getPosCen()					{ return posCen; }
		virtual bool isEnabled()					{ return isEnable; }

		//Setter
		virtual void setSize(const vec2f& sizE)		{ size = sizE; }
		virtual void setPos(const vec2f& poS)
		{
			pos = poS; posCen = { pos.x + (size.x / 2), pos.y + (size.y / 2) };
		}
		virtual void setCenPos(const vec2f& poScen)
		{
			posCen = poScen; pos = { posCen.x - (size.x / 2), posCen.y - (size.y / 2) };
		}
		
	private:
		bool isEnable = true;

		vec2f pos;
		vec2f size;
		vec2f posCen;
	};
}