#include "Engine.h"

namespace xphase
{
	int createGame(bool debug, const std::string& filePath)
	{
		Game game(debug, filePath);

		return EXIT_OK;
	}
}