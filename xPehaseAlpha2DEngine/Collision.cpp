
#include "World.h"

namespace xphase
{
	int Collision::create(vec2f &pos, vec2f &size)
	{
		setSize(size);
		setPos(pos);

		//dub
		dub.x = getPos().x + getSize().x;
		dub.y = getPos().y + getSize().y;

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
		//some boolean math
		promoAngleSize = getSize().y + player.getAngle();
		promoAnglePos = getPos().y + player.getAngle();

		upSide = ((player.getPos().y < (getPos().y + promoAngleSize)) && (player.getPos().y > promoAnglePos));
		downSide = ((player.getDub().y > getPos().y) && (player.getDub().y < dub.y));
		leftSide = ((player.getDub().x > getPos().x) && (player.getDub().x < dub.x));
		rightSide = ((player.getPos().x < dub.x) && (player.getPos().x > getPos().x));

		vertical = 
			(
				((getPos().x < player.getPos().x) & (dub.x > player.getPos().x))
				||
				((getPos().x < player.getDub().x) & (dub.x > player.getDub().x))
			);


		horizontal = 
			(
				((getPos().y < player.getDub().y) && (player.getDub().y < dub.y))
				||
				((promoAnglePos < player.getPos().y) && (player.getPos().y < (getPos().y + promoAngleSize)))
				||
				((player.getPosCen().y > getPos().y) && (player.getPosCen().y < (getPos().y + promoAngleSize)))
			);

		/*
			PROMO ANGLE SiZE = COL SIZE Y + PLAYER ANGLE;
			PROMO ANGLE POS = COL POS Y + PLAYER ANGLE;

			DUB POS X = COL POS X + COL SIZE X;
			DUB POS Y = COL POS Y + COL SIZE Y;

			UP SIDE = ((PLAYER POS Y < (COL POS Y + PROMO ANGLE SiZE)) && (PLAYER POS Y > PROMO ANGLE POS));
			DOWN SIDE = ((DUB PLAYER Y > COL POS Y) && (DUB PLAYER Y < DUB POS Y));
			LEFT SIDE = ((DUB PLAYER X > COL POS X) && DUB PLAYER X < DUB POS X);
			RIGHT SIDE = ((PLAYER POS X < DUB POS X) && (PLAYER POS X > COL POS X));
		*/


		player.setBlockedUp
		(
			vertical && upSide || player.getAlreadyBlockedUp()
		);

		player.setBlockedDown
		(
			vertical && downSide || player.getAlreadyBlockedDown()
		);

		player.setBlockedLeft
		(
			horizontal && leftSide || player.getAlreadyBlockedLeft()
		);

		player.setBlockedRight
		(
			horizontal && rightSide || player.getAlreadyBlockedRight()
		);
	}
}