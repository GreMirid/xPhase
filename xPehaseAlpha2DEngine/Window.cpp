#include "Core.h"

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

		//why sw-case don't work with std::string?
		if (sobj == "Dev") { res = { 1280, 720 }; } //how developer uses
		else if (sobj == "640x360") { res = { 640, 360 }; } //sd
		else if (sobj == "960x540") { res = { 960, 540 }; }
		else if (sobj == "1280x720") { res = { 1280, 720 }; } //hd
		else if (sobj == "1280x1024") { res = { 1280, 720 }; } //hd 4:3
		else if (sobj == "1366x768") { res = { 1366, 768 }; } //notebook
		else if (sobj == "1600x900") { res = { 1600, 900 }; }
		else if (sobj == "1920x1080") { res = { 1920, 1080 }; } //fhd
		else if (sobj == "2048x1152") { res = { 2048, 1152 }; }
		else if (sobj == "2560x1440") { res = { 2560, 1440 }; } //2k
		else if (sobj == "2880x1620") { res = { 2880, 1620 }; }
		else if (sobj == "3200x1800") { res = { 3200, 1800 }; }
		else if (sobj == "3840x2160") { res = { 3840, 2160 }; } //4k

		screenMatrix.create(res);

		camera.setSize(res.x, res.y);
		camera.setCenter(res.x / 2,  res.y / 2);

		if (reader.GetBoolean("Game", "Fullscreen", false)) windStyle = sf::Style::Fullscreen;

		drawArea.create(sf::VideoMode(res.x , res.y), isDebug() ? windowName + " Debug Mode" : windowName, windStyle);
		drawArea.setVerticalSyncEnabled(reader.GetBoolean("Game", "Vsync", true));
		setWindowFPS(75);
		isDrawCursor(false);
	}
}