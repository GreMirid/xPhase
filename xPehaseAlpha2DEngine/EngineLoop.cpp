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
		while (window.drawArea.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.drawArea.close();
		}

		window.drawArea.clear(sf::Color(color, color, color));

		switch (itReverse)
		{
		case true: color--; if (color <= 0) itReverse = false; break;

		case false: color++; if (color >= 255) itReverse = true; break;
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

			frame(delta); //do staff

			endFrameTime = clock.getElapsedTime().asMicroseconds();

			//write fps count in varible to display it
			window.setCurrentFPS(1 / (float)clock.getElapsedTime().asSeconds());

			clock.restart();
		}

		isWindowOpen = window.drawArea.isOpen();
	}

	void EngineLoop::set()
	{
		///
	}

	void EngineLoop::setStatus(int status)
	{
		statusFlag = status;
	}

	void EngineLoop::setScene(int scene)
	{
		fromScene = scene;
	}
}