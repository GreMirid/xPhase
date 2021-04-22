#pragma once

#include "Modules.h"
#include "Objects.h"

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
		void loadingFrame(double delta);
		void mainMenuFrame(double delta);
		void gameFrame(double delta);
		void endingFrame(double delta);

	private:
		class LoadingResources
		{
		public:
			sf::Font font; sf::Text loaingText; sf::ConvexShape panel;
			void create(const vec2f& screen);
		} ld;

	private:
		void frame(double delta);
	};
}