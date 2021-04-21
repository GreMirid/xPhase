#include "Core.h"

namespace xphase
{
	void Window::open(const std::string& name)
	{
		windowName = name; //set name

		//TASK:
		///In ini file select need params and past it here
		INIReader reader("./" + name + "/config.ini");

		vec2f res = { 1024, 480 };

		std::string sobj = reader.Get("Game", "Resolution", "Dev"); 

		//std::map cumming soon
		//why sw-case don't work with std::string?
		if (sobj == "Dev") { res = { 1280, 720 }; }
		else if (sobj == "User_1") { res = { 1024, 480 }; }
		else if (sobj == "User_2") { res = { 1366, 768 }; }
		else if (sobj == "User_3") { res = { 1920, 1080 }; }

		screenMatrix.create(res);

		drawArea.create(sf::VideoMode(res.x , res.y), isDebug() ? name + " Debug Mode" : name, windStyle);
		drawArea.setFramerateLimit(120);
		drawArea.setVerticalSyncEnabled(reader.GetBoolean("Game", "Vsync", true));

	}
}