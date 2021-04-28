#pragma once

namespace xphase
{
	//for functions
	enum Returns
	{
		EXIT_NULL,
		EXIT_OK,
		EXIT_WARNING,
		EXIT_ERROR
	};

	//for game
	enum statuses
	{
		StartingSequnce,
		LoadingSequnce,
		MainMenuSequnce,
		GameSequnce,
		ExitSequence
	};

	//for buttons
	enum roles
	{
		DoNotExec,
		Play,
		Configure,
		Quit,
		Extra
	};
}