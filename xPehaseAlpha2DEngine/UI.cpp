#include "UserInterface.h"

namespace xphase
{
	int UserInterface::load(Window& window)
	{
		int loadStatus = EXIT_OK;

		loadStatus = mM.create(window);
		loadStatus = st.create(window);
		loadStatus = igme.create(window);

		return loadStatus;
	}
}