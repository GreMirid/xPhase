
#include "Engine.h"

void itParametrExist(bool &param, char* str, const char* nameParam)
{
	if (strcmp(str, nameParam) == 0) param = true;
}

int main(int argc, char** argv)
{	
	//TASK:
	/// Get params from exec path and do changes in execution code
	bool debug = false;

	for (int count = 0; count < argc; count++)
	{
		itParametrExist(debug, argv[count], "/debug");
	}

	std::string path = argv[0];

	//
	xphase::createGame(debug, path);

	return xphase::EXIT_OK;
}