#include "Core.h"

#pragma once

namespace xphase
{
	class Object
	{
	public:
		virtual int create()
		{
			return 0;
		}
		virtual void destroy()		{ delete this; }

	public:
		//Getter
		virtual vec2f getPos()		{ return pos; }
		virtual vec2f getSize()		{ return size; }
		virtual vec2f getPosCen()	{ return posCen; }

		//Setter
		virtual void setPos(const vec2f& poS)		{ pos = poS; }
		virtual void setSize(const vec2f& sizE)		{ size = sizE; }
		virtual void setCenPos(const vec2f& cenPos) { posCen = cenPos; }

		
	private:
		vec2f pos;
		vec2f size;
		vec2f posCen;
	};
}