#include "Engine.h"

namespace xphase
{
	void createGame(bool debug, const std::string& filePath)
	{
		/// Game is the object.
		Game game(debug, filePath);
	}
}