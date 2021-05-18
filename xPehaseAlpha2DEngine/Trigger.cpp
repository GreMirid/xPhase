
#include "World.h"

namespace xphase
{
	int Trigger::create(vec2f &pos, vec2f &size, int t)
	{
		setSize(size);
		setPos(pos);

		type = t;

		//visual
		visual.setPointCount(4);
		visual.setPoint(0, sf::Vector2f(0, 0));
		visual.setPoint(1, sf::Vector2f(size.x, 0));
		visual.setPoint(2, sf::Vector2f(size.x, size.y));
		visual.setPoint(3, sf::Vector2f(0, size.y));

		visual.setOutlineColor(sf::Color::Yellow);

		visual.setFillColor(sf::Color(0, 0, 0, 0));
		visual.setOutlineThickness(4);
		visual.setPosition(pos.x, pos.y);

		return EXIT_OK;
	}

	void Trigger::update(Player &player, float delta)
	{
		
	}
}