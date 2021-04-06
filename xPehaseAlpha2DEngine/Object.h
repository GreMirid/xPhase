#pragma once

#include "Core.h"

namespace xphase
{
	class Object
	{
	public:
		virtual int create()						{ return EXIT_NULL; }
		virtual void destroy()						{ delete this; }

	public:
		//Getter
		virtual vec2f getPos()						{ return pos; }
		virtual vec2f getSize()						{ return size; }
		virtual vec2f getPosCen()					{ return posCen; }

		//Setter
		virtual void setSize(const vec2f& sizE)		{ size = sizE; }
		virtual void setPos(const vec2f& poS)
		{
			pos = poS; posCen = { pos.x + (size.x / 2) , pos.y + (size.y / 2) };
		}
		
	private:
		vec2f pos;
		vec2f size;
		vec2f posCen;
	};
}