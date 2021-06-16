#include "UserInterface.h"

namespace xphase
{
	int UserInterface::load(Window& window)
	{
		//task:
		/// set to mas of Interface components
		int loadStatus = EXIT_NULL;

		/// to cycle
		loadStatus = mM.create(window);
		loadStatus = st.create(window);
		loadStatus = igme.create(window);
		loadStatus = dialogInterface.create(window);
		loadStatus = misc.create(window);
		loadStatus = helper.create(window);

		return loadStatus;
	}

	void UserInterface::draw(Window &window)
	{
		dialogInterface.draw(window);
		igme.draw(window);
		helper.draw(window);
		misc.draw(window);
	}
}