


#include "Scripts.h"
#include "UserInterface.h"
#include "Scenario.h"

#pragma once

namespace xphase
{
	static Scripts scripts;
	static UserInterface UI;
	static Scenario characters;

	static void loadModules()
	{
		scripts.load();
		UI.load();
		characters.load();
	}
}