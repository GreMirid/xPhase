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
		void frame(double delta);
	};
}