#include "Core.h"

#include <map>

namespace xphase
{
	//Set DrawArea Framerate Limit
	void Window::setWindowFPS(float fps)
	{
		drawArea.setFramerateLimit(fps);
	}

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

		vec2f res = { 1280, 720 };

		std::string sobj = reader.Get("Game", "Resolution", "Dev"); 

		res = resolutions[sobj];
		screenMatrix.create(res);

		camera.setSize(res.x, res.y);
		camera.setCenter(res.x / 2,  res.y / 2);

		if (reader.GetBoolean("Game", "Fullscreen", false))
			windStyle = sf::Style::Fullscreen;

		drawArea.create(sf::VideoMode(res.x , res.y), isDebug() ? windowName + " Debug Mode" : windowName, windStyle);
		drawArea.setVerticalSyncEnabled(reader.GetBoolean("Game", "Vsync", true));
		setWindowFPS(75);
		isDrawCursor(false);
	}

	Window *m_Window;
}