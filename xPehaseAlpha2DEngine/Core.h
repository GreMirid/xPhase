#pragma once

//
#include <string>

//
#include "Vector2.h"
#include "Returns.h"

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
		int windStyle = sf::Style::Close | sf::Style::Titlebar;

	public:
		void open()
		{
			//TASK:
			///In ini file select need params and past it here
			drawArea.create(sf::VideoMode(1280, 720), "TestWindow", windStyle);
			drawArea.setFramerateLimit(120);
		}
	};

	class EngineLoop
	{
	public:
		//
		float startFrameTime = 0, endFrameTime = 0;
		bool isWindowOpen = false;

		//
		Window window;

		//
		bool itReverse = false;
		int color = 0;

		//
		virtual void openWindow();
		virtual void frame(float delta);
		virtual void loop();
		
		//
		virtual void set();
	};

}