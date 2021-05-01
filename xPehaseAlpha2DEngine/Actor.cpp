#include "Actor.h"

namespace xphase
{
	void Actor::move(int direction, float delta, float move)
	{
		float gameDT = speedOfActor * delta;

		vec2f currentPos = getPosCen();

		//character move machina
		switch (direction)
		{
		case Up:		setCenPos({ currentPos.x, currentPos.y - move + gameDT }); break;
		case Down:		setCenPos({ currentPos.x, currentPos.y + move + gameDT }); break;
		case Left:		setCenPos({ currentPos.x - move + gameDT, currentPos.y }); break;
		case Right:		setCenPos({ currentPos.x - move + gameDT, currentPos.y }); break;
		case LeftUp:	setCenPos({ currentPos.x - move + gameDT, currentPos.y - move + gameDT }); break;
		case UpRight:	setCenPos({ currentPos.x + move + gameDT, currentPos.y - move + gameDT }); break;
		case LeftDown:	setCenPos({ currentPos.x - move + gameDT, currentPos.y + move + gameDT }); break;
		case DownRight:	setCenPos({ currentPos.x + move + gameDT, currentPos.y + move + gameDT }); break;
		}

		//sprite chages machina
		switch ((frameDelay == delayConst))
		{
		case true:
			frameDelay = 0;
			switch (spriteStage == 2)
			{
			case true: spriteStage = 0; break; case false: spriteStage++; break;
			}
			break;

		case false: frameDelay++; break;
		}

		actorSprite.setPosition(getPos().x, getPos().y);

		actorSprite.setTextureRect(getRectForCharacter(direction, spriteStage));
	}

	void Actor::calculatePointsForAtlas()
	{
		vec2f sizeOfCharacter = getSize();

		for (int direction = Idle; direction < DownRight + 1; direction++)
		{
			std::vector<vec2f> localPos;

			vec2f posAt;

			if (direction == Idle)
			{
				posAt = { sizeOfCharacter.x * 3, sizeOfCharacter.x * 3 };
				localPos.emplace_back(posAt); spritesCoords.emplace_back(localPos);
				continue;
			}

			vec2f dirTo = { sizeOfCharacter.x * 3, sizeOfCharacter.x * 3 };

			for (int pos = 0; pos < 3; pos++)
			{
				switch (direction)
				{
				case Up:	dirTo.y -= sizeOfCharacter.y; break;
				case Down:	dirTo.y += sizeOfCharacter.y; break;
				case Left:	dirTo.x -= sizeOfCharacter.x; break;
				case Right:	dirTo.x += sizeOfCharacter.x; break;
				case LeftUp:
					dirTo.y -= sizeOfCharacter.y;
					dirTo.x -= sizeOfCharacter.x;
					break;
				case UpRight:
					dirTo.y -= sizeOfCharacter.y;
					dirTo.x += sizeOfCharacter.x;
					break;
				case LeftDown:
					dirTo.y += sizeOfCharacter.y;
					dirTo.x -= sizeOfCharacter.x;
					break;
				case DownRight:
					dirTo.y += sizeOfCharacter.y;
					dirTo.x += sizeOfCharacter.x;
					break;
				}

				posAt = { dirTo.x, dirTo.y };

				localPos.emplace_back(posAt);
			}

			spritesCoords.emplace_back(localPos);
		}
	}

	sf::IntRect Actor::getRectForCharacter(int direction, int stage)
	{
		return
			sf::IntRect
		(
			spritesCoords[direction][stage].x,
			spritesCoords[direction][stage].y,
			getSize().x,
			getSize().y
		);
	}
}