#include "UserInterface.h"

namespace xphase
{
	int UserInterface::load(Window& window)
	{
		//task:
		/// set to mas of Interface components
		int loadStatus = EXIT_OK;

		/// to cycle
		loadStatus = mM.create(window);
		loadStatus = st.create(window);
		loadStatus = igme.create(window);
		loadStatus = dialogInterface.create(window);

		return loadStatus;
	}
}