#pragma once

//
#include <string>
#include <set>

//
#include "Vector2.h"
#include "Returns.h"

//TASK:
/// Implement a ConteinerReader Class

//
#include "SFML/Graphics.hpp"

//
namespace xphase
{
	//Functions and Classes for Game itself

	class Window
	{
	public:
		sf::RenderWindow drawArea;

	private:
		char windStyle = sf::Style::Close | sf::Style::Titlebar;

	public:
		void open(const std::string& path)
		{
			//TASK:
			///In ini file select need params and past it here
			std::string pathToIni = "./" + path + "/gamedata.ini";

			drawArea.create(sf::VideoMode(1280, 720), path, windStyle);
			drawArea.setFramerateLimit(120);
			drawArea.setVerticalSyncEnabled(true);
		}
	};

	class EngineLoop
	{
	public:
		//
		double startFrameTime = 0, endFrameTime = 0;
		bool isWindowOpen = false;

		//
		Window window;

		//
		bool itReverse = false;
		int color = 0;

		//
		virtual void openWindow(const std::string& path);
		virtual void frame(double delta);
		virtual void loop();
		
		//
		virtual void set();
	};

}