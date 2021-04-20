#include "Core.h"

namespace xphase
{
	void Window::open(const std::string& path)
	{
		//TASK:
		///In ini file select need params and past it here
		std::string pathToIni = "./" + path + "/gamedata.ini";

		//do staff

		std::string dp;

		isDebug() ? dp = path + " Debug" : dp = path;

		drawArea.create(sf::VideoMode(1280, 720), dp, windStyle);
		drawArea.setFramerateLimit(120);
		drawArea.setVerticalSyncEnabled(true);
	}
}