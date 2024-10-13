#pragma once

#include "Core.h"

namespace xphase
{
	class Object
	{
	public:
		//Object() { create(); }
		//~Object() { destroy(); }

		virtual int create() = 0;
		virtual void destroy()						{ delete this; }

		virtual void update(double delta)			{ };

	public:
		// ...
		virtual vec2f getPos()						{ return pos; }
		virtual vec2f getSize()						{ return size; }
		virtual vec2f getPosCen()					{ return posCen; }
		virtual vec2f getScale()					{ return scale; }
		virtual vec2f getScaledSize()
		{
			return { size.x * scale.x, size.y * scale.y };
		}
		virtual bool isEnabled() { return enableFlag; }

		// ...
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
		vec2f pos;
		vec2f size;
		vec2f posCen;
		vec2f scale;

		bool enableFlag = true;
	};
}