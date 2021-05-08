#include "Core.h"

namespace xphase
{
	void Window::open(const std::string& path)
	{
		//TASK:
		/// Get a name of exec file and put this in name of window:
		pathTo.assign(path, 0, path.size() - 4);

		short namCount = -5;

		for (size_t letter = path.size(); letter > 0; letter--)
		{
			if (path[letter] == '\\')
			{
				windowName.assign(path, letter + 1, namCount);
				break;
			}
			namCount++;
		}

		//TASK:
		///In ini file select need params and past it here
		INIReader reader( pathTo + TO_CFG + "config.ini" );

		vec2f res = { 1024, 480 };

		std::string sobj = reader.Get("Game", "Resolution", "Dev"); 

		//why sw-case don't work with std::string?
		if (sobj == "Dev") { res = { 1280, 720 }; }
		else if (sobj == "User_1") { res = { 1024, 480 }; }
		else if (sobj == "User_2") { res = { 1366, 768 }; }
		else if (sobj == "User_3") { res = { 1920, 1080 }; }

		screenMatrix.create(res);

		camera.setSize(res.x, res.y);
		camera.setCenter(res.x / 2,  res.y / 2);

		drawArea.create(sf::VideoMode(res.x , res.y), isDebug() ? windowName + " Debug Mode" : windowName, windStyle);
		drawArea.setFramerateLimit(120);
		drawArea.setVerticalSyncEnabled(reader.GetBoolean("Game", "Vsync", true));
	}
}