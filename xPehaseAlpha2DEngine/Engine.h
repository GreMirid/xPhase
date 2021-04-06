#pragma once

#include "Modules.h"
#include "Objects.h"

namespace xphase
{
	void createGame(const std::string& filePath = "platform");

	class Game : public EngineLoop
	{
	public:
		Game(const std::string& filePath);

	private:
		void start();
		void render();
	};
}