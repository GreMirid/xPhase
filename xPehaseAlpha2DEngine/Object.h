#pragma once

#include "Core.h"

namespace xphase
{
	class Object
	{
	public:
		virtual int create()						{ return EXIT_NULL; }
		virtual void destroy()						{ delete this; }

		virtual void update(double delta)			{ };

	public:
		//Getter
		virtual vec2f getPos()						{ return pos; }
		virtual vec2f getSize()						{ return size; }
		virtual vec2f getPosCen()					{ return posCen; }
		virtual vec2f getScale()					{ return scale; }
		virtual bool isEnabled()					{ return enableFlag; }

		//Setter
		virtual void isEnabled(bool en)				{ enableFlag = en; }
		virtual void setSize(const vec2f& sizE)		{ size = sizE; }
		virtual void setScale(const vec2f& scalE)	{ scale = scalE; }
		virtual void setPos(const vec2f& poS)
		{
			pos = poS; posCen = { pos.x + (size.x / 2), pos.y + (size.y / 2) };
		}
		virtual void setCenPos(const vec2f& poScen)
		{
			posCen = poScen; pos = { posCen.x - (size.x / 2), posCen.y - (size.y / 2) };
		}
		
	private:
		bool enableFlag = true;

		vec2f pos;
		vec2f size;
		vec2f posCen;
		vec2f scale;
	};
}