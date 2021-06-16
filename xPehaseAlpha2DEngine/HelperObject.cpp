#include "UserInterface.h"

namespace xphase
{
	int UserInterface::HelperObject::create(Window &window)
	{
		//TASK:
		///Create helpers.ini file
		///Load all params from this .ini file on calculate need constants

		return EXIT_OK;
	}

	void UserInterface::HelperObject::update(Player &player)
	{
		//TASK:
		///Set Position for helper
		///Logic for helper
	}

	void UserInterface::HelperObject::draw(Window &window)
	{
		if (isShow())
			window.drawArea.draw(helper);
	}
}