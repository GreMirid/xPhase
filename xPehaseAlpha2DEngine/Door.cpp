
#include "World.h"

namespace xphase
{
	int Door::create(vec2f &pos, int to_door, int to_location, float scale)
	{
		setSize({ 100 * scale, 100 * scale });

		setScale({ scale, scale });

		setPos(pos);

		toDoor = to_door;
		toLocation = to_location;

		//visual
		visual.setPointCount(4);
		visual.setPoint(0, sf::Vector2f(0, 0));
		visual.setPoint(1, sf::Vector2f(getSize().x, 0));
		visual.setPoint(2, sf::Vector2f(getSize().x, getSize().y));
		visual.setPoint(3, sf::Vector2f(0, getSize().y));

		visual.setOutlineColor(sf::Color::Green);

		visual.setFillColor(sf::Color(0, 0, 0, 0));
		visual.setOutlineThickness(4);
		visual.setPosition(pos.x, pos.y);

		return EXIT_OK;
	}

	vec2f Door::update(Player &player)
	{
		switch
			(
				(
					(player.getPosCen().x + player.getSize().x > getPos().x) && (player.getPosCen().x + player.getSize().x < getPos().x + getSize().x)
				)
					&&
				(
					(player.getPosCen().y > getPos().y) && (player.getPosCen().y < getPos().y + getSize().y)
				)
			)
		{
		case true:

			switch ((sf::Keyboard::isKeyPressed(sf::Keyboard::E)))
			{
			case true: return { float(toDoor), float(toLocation) }; break;
			default: break;
			}
		
			break;
		default: break;
		}
		return { NoZero, 0 };
	}
}