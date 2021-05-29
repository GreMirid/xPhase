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

	//
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
		float fps = 0;
		bool dFlag = false;
		bool drawBordersInDebugFlag = false;

	public:
		bool isDebug()					{ return dFlag; }
		void isDebug(bool d)			{ dFlag = d; }

		bool isDrawBorders()			{ return drawBordersInDebugFlag; }
		void isDrawBorders(bool d)		{ drawBordersInDebugFlag = d; }
		void isDrawCursor(bool d)		{ drawArea.setMouseCursorVisible(d); }

		std::string getPathtoGame()		{ return pathTo; }
		std::string getName()			{ return windowName; }
		float getCurrentFPS()			{ return fps; }

		//Only for Engine Loop Class
		void setCurrentFPS(float FPS)	{ fps = FPS; }

		void setWindowFPS(float fps);

		void open(const std::string& path);
	};

	//
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

	/*
	We have some problems with std::vector and sf::Textures
	So there the solution:
	Create a Global Texture Manager to load all texture to use they
	*/

	typedef std::unordered_map<std::string, sf::Texture*>::iterator TexIter;

	class TextureManager
	{
	private:
		//emo
		sf::Texture *nullTexture;

	private:
		//main mas
		std::unordered_map<std::string, sf::Texture*> g_Textures;

	public:
		int create(Window &window);

		sf::Texture* loadTexture(std::string &path_to);
 	};

	extern TextureManager m_Textures;

	//ALSO:
	//Need to create some Font for Text Global Manager
	typedef std::unordered_map<std::string, sf::Font*>::iterator FontIter;

	class FontManager
	{
	private:
		//emo
		sf::Font *nullFont;

	private:
		//main mas
		std::unordered_map<std::string, sf::Font*> g_Fonts;

	public:
		int create(Window &window);

		sf::Font* loadFont(std::string &path_to);
	};

	extern FontManager m_Font;
}