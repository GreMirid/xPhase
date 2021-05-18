#include "Engine.h"

namespace xphase
{
	void Game::LoadingResources::create(Window &window)
	{
		font.loadFromFile(window.getPathtoGame() + TO_RES + "fonts\\mainfont.ttf");

		loaingText.setFont(font);

		loaingText.setFillColor(sf::Color(255, 255, 255));
		loaingText.setCharacterSize(20);
		loaingText.setPosition((window.screenMatrix.getRealScreenSize().x / 2) - 33, (window.screenMatrix.getRealScreenSize().y / 2) - 13);

		loaingText.setString(L"Loading");

		panel.setPointCount(4);

		panel.setPoint(0, sf::Vector2f(0, 0));
		panel.setPoint(1, sf::Vector2f(100, 0));
		panel.setPoint(2, sf::Vector2f(100, 40));
		panel.setPoint(3, sf::Vector2f(0, 40));

		panel.setOutlineColor(sf::Color(50, 50, 50, 200));

		panel.setFillColor(sf::Color::Black);

		panel.setOutlineThickness(5);

		panel.setPosition((window.screenMatrix.getRealScreenSize().x / 2) - 50, (window.screenMatrix.getRealScreenSize().y / 2) - 20);
	}

	void Game::LoadingResources::draw(sf::RenderWindow & window)
	{
		window.draw(panel);
		window.draw(loaingText);
	}
}