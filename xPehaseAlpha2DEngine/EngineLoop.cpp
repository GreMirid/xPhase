#include "Core.h"

namespace xphase
{
	void EngineLoop::openWindow()
	{
		window.open();

		//do staff
		isWindowOpen = true;
	}

	void EngineLoop::frame(float delta)
	{
		window.drawArea.clear(sf::Color(color, color, color, 255));

		if (itReverse)
		{
			color--; if (color <= 0) itReverse = false;
		}
		else
		{
			color++; if (color >= 255) itReverse = true;
		}

		window.drawArea.display();
	}

	void EngineLoop::loop()
	{
		sf::Clock clock;
		
		while (window.drawArea.isOpen())
		{
			float delta = endFrameTime - startFrameTime;

			startFrameTime = clock.getElapsedTime().asMicroseconds();

			//sfml 
			sf::Event event;
			while (window.drawArea.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) window.drawArea.close();
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
		//do staff
	}
}