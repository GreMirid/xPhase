#pragma once

#include "Actor.h"

namespace xphase
{
	class Player : public Actor
	{
	private:
		int location = 0;

	public:
		//Getter
		int getLocation()
		{
			return location;
		}

		//Setter
		void setLocation(int loc)
		{
			location = loc;
		}
	};
}