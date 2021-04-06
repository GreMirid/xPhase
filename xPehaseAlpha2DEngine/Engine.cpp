#include "Engine.h"

namespace xphase
{
	void createGame(const std::string& filePath)
	{
		//Game is the object.
		Game game( "./" + filePath + '/' + "config.ini");
	}
}