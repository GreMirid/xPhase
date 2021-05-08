#pragma once

/*
The Inih Project
Simple INI Parser
GitHub: https://github.com/benhoyt/inih
*/
#include "INI/INIReader.h"

//
#include "VarTrash.h"
#include "Matrix.h"
#include "Returns.h"
#include "ConteinerReader.h"

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
		ScreenMatrix screenMatrix;

	public:
		sf::View camera;

	private:
		std::string windowName, pathTo;
		char windStyle = sf::Style::Close | sf::Style::Titlebar;
		bool dFlag = false;
		bool drawBordersInDebugFlag = false;

	public:
		bool isDebug()				{ return dFlag; }
		void isDebug(bool d)		{ dFlag = d; }

		bool isDrawBorders()		{ return drawBordersInDebugFlag; }
		void isDrawBorders(bool d)	{ drawBordersInDebugFlag = d; }

		std::string getPathtoGame() { return pathTo; }

		std::string getName()		{ return windowName; }

		void open(const std::string& path);
	};

	class EngineLoop
	{
	public:
		//
		int statusFlag = StartingSequnce;
		int fromScene = StartingSequnce;

		//
		double startFrameTime = 0, endFrameTime = 0;
		bool isWindowOpen = false;

		//
		Window window;

		//sfml: i'm need some "event" object to interact with your window.
		sf::Event event;

		//
		bool itReverse = false;
		int color = 0;

		//
		virtual void openWindow(const std::string& path);
		virtual void frame(double delta);
		virtual void loop();
		
		//
		virtual void set();
		virtual void setStatus(int status);
		virtual void setScene(int scene);
	};
}