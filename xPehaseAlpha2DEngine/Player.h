#pragma once

#include "Object.h"

namespace xphase
{
	class Player : public Object
	{
	private:
		int location = 0;

	public:
		int create()
		{
			//TASK:
			/// Read a conteiner file and past all data to there
			return EXIT_OK;
		}
		
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