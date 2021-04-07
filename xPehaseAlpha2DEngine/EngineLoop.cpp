#include "Core.h"

namespace xphase
{
	void EngineLoop::openWindow(const std::string& path)
	{
		window.open(path);

		isWindowOpen = true;
	}

	//Placeholder Frame
	void EngineLoop::frame(double delta)
	{
		window.drawArea.clear(sf::Color(color, color, color));

		switch (itReverse)
		{
		case true:
			color--;
			if (color <= 0) itReverse = false;
			break;

		case false:
			color++;
			if (color >= 255) itReverse = true;
			break;
		}

		window.drawArea.display();
	}

	void EngineLoop::loop()
	{
		sf::Clock clock;
		
		while (window.drawArea.isOpen())
		{
			double delta = endFrameTime - startFrameTime;

			startFrameTime = clock.getElapsedTime().asMicroseconds();

			//sfml: i'm need some "event" object to interact with your window.
			sf::Event event;
			while (window.drawArea.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) window.drawArea.close();

				//TASK:
				/// bind some "e" and "escape" keys to eteract with world

			}

			//do staff

			frame(delta);

			endFrameTime = clock.getElapsedTime().asMicroseconds();

			clock.restart();
		}

		isWindowOpen = window.drawArea.isOpen();
	}

	void EngineLoop::set()
	{
		//do staff (just emtpty function for joke ahahah)
	}
}