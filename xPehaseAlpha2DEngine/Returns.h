#pragma once

namespace xphase
{
	//for functions
	enum Returns
	{
		//Exit of function
		EXIT_NULL,
		//Exit of function was success
		EXIT_OK,
		//Exit of function was with problems
		EXIT_WARNING,
		//Exit of function was unsuccess
		EXIT_ERROR,
		//Null but is not zero
		NoZero = 30303030
	};

	//for game
	enum statuses
	{
		StartingSequnce,
		LoadingSequnce,
		MainMenuSequnce,
		GameSequnce,
		SettingsSequence,
		ExitSequence
	};

	//for buttons
	enum roles
	{
		DoNotExec,
		Play,
		Configure,
		Quit,
		Extra,
		toMainMenu
	};
}