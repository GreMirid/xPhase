#pragma once

//
#include "Player.h"
#include "World.h"

//
#include "Scripts.h"
#include "UserInterface.h"
#include "Scenario.h"

namespace xphase
{
	void createGame(bool debug, const std::string& filePath = "platform");

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

	private:
		class LoadingResources
		{
		private:
			sf::Font font; sf::Text loaingText; sf::ConvexShape panel;

		public:
			void create(const vec2f &screen, const std::string &path);
			void draw(sf::RenderWindow &window);

		} /* Create a object of loading graphics */ ld;

	private:
		//Modules
		Scripts scripts;
		UserInterface UI;
		Scenario characters;

		//Objects
		Player player;
		World world;
	};
}