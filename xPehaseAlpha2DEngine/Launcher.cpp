
#include "Engine.h"

void itParametrExist(bool &param, char* str, const char* nameParam)
{
	if (strcmp(str, '/' + nameParam) == 0) param = true;
}

int main(int argc, char** argv)
{	
	//TASK:
	/// Get params from exec path and do changes in execution code
	bool debug = false;

	for (int count = 0; count < argc; count++)
	{
		itParametrExist(debug, argv[count], "debug");
	}

	//TASK:
	/// Get a name of exec file and put this in name of window:
	std::string name, path = argv[0];
	short namCount = -5;

	for (size_t letter = path.size();  letter > 0; letter--)
	{
		if (path[letter] == '\\')
		{
			name.assign(path, letter + 1, namCount); break;
		}
		namCount++;
	}

	xphase::createGame(debug, name);

	return xphase::EXIT_OK;
}