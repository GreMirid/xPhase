
#include "World.h"

namespace xphase
{
	int Collision::create(vec2f &pos, vec2f &size)
	{
		setSize(size);
		setPos(pos);

		//visual
		visual.setPointCount(4);
		visual.setPoint(0, sf::Vector2f(0, 0));
		visual.setPoint(1, sf::Vector2f(size.x, 0));
		visual.setPoint(2, sf::Vector2f(size.x, size.y));
		visual.setPoint(3, sf::Vector2f(0, size.y));

		visual.setOutlineColor(sf::Color::Red);

		visual.setFillColor(sf::Color(0, 0, 0, 0));
		visual.setOutlineThickness(4);
		visual.setPosition(pos.x, pos.y);

		return EXIT_OK;
	}

	void Collision::update(Player &player, float delta)
	{

	}
}