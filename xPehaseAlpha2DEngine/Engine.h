#pragma once

//
#include "World.h"

//
#include "Scripts.h"
#include "UserInterface.h"

namespace xphase
{
	int createGame(bool debug, const std::string& filePath = "platform");

	class Game : public EngineLoop
	{
	public:
		Game(bool debug, const std::string& filePath);

	private:
		void start();
		void render();

	private:
		void loadModules();
		void initObjects();

	private:
		void frame(double delta);

	private:
		void loadingFrame(double delta);
		void mainMenuFrame(double delta);
		void gameFrame(double delta);
		void endingFrame(double delta);
		void settingsFrame(double delta);

	private:
		void gameFrameAction();

	private:
		//Create a object of loading graphics
		class LoadingResources
		{
		private:
			sf::Text loaingText; sf::ConvexShape panel;

		public:
			void create(Window &window);
			void draw(sf::RenderWindow &window);

		} ld;

	private:
		//Modules
		UserInterface UI;

		//Objects
		Player player;
		World world;
	};
}