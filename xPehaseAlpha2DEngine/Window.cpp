#include "Core.h"

namespace xphase
{
	void Window::open(const std::string& name)
	{
		windowName = name; //set name

		//TASK:
		///In ini file select need params and past it here
		std::string pathToIni = "./" + name + "/config.ini";

		//do staff

		drawArea.create(sf::VideoMode(1280, 720), isDebug() ? name + " Debug Mode" : name, windStyle);
		drawArea.setFramerateLimit(120);
		drawArea.setVerticalSyncEnabled(true);
	}
}