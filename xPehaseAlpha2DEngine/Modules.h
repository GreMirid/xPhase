
#include "Scripts.h"
#include "UserInterface.h"
#include "Scenario.h"

namespace xphase
{
	Scripts scripts;
	UserInterface UI;
	Scenario characters;

	void loadModules()
	{
		scripts.load();
		UI.load();
		characters.load();
	}
}