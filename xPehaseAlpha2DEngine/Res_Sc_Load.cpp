#include "Engine.h"

namespace xphase
{
	void Game::LoadingResources::create(const vec2f& screen)
	{
		font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

		loaingText.setFont(font);
		loaingText.setFillColor(sf::Color(255, 255, 255));
		loaingText.setCharacterSize(20);
		loaingText.setPosition((screen.x / 2) - 35, (screen.y / 2) - 10);
		loaingText.setString(L"Loading");

		panel.setPointCount(4);
		panel.setPoint(0, sf::Vector2f(0, 0));
		panel.setPoint(1, sf::Vector2f(100, 0));
		panel.setPoint(2, sf::Vector2f(100, 40));
		panel.setPoint(3, sf::Vector2f(0, 40));

		panel.setPosition((screen.x / 2) - 50, (screen.y / 2) - 20);

		panel.setFillColor(sf::Color(45, 45, 45, 125));
	}
}