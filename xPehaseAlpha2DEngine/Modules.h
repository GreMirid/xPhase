#pragma once

//
#include "Scripts.h"
#include "UserInterface.h"
#include "Scenario.h"

namespace xphase
{
	//
	static Scripts scripts;
	static UserInterface UI;
	static Scenario characters;

	//
	static void loadModules()
	{
		scripts.load();
		UI.load();
		characters.load();
	}
}