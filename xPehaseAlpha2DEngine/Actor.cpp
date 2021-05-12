#include "Actor.h"

namespace xphase
{
	void Actor::setActorPos(const vec2f &pos)
	{
		setPos(pos);

		actorSprite.setPosition(pos.x, pos.y);
	}

	void Actor::setActorCenPos(const vec2f &pos)
	{
		setCenPos(pos);

		actorSprite.setPosition(getPos().x, getPos().y);
	}

	void Actor::setActorRect(int direction, int spriteStage)
	{
		actorSprite.setTextureRect(getRectForCharacter(direction, spriteStage));
	}

	void Actor::setActorSpeed(float speed)
	{
		speedOfActor = speed;
	}

	void Actor::setActorScale(const vec2f &scale)
	{
		setScale(scale);

		actorSprite.setScale(scale.x, scale.y);
	}

	void Actor::setSprite()
	{
		//Load file
		actorTexture.loadFromFile(pathToAtlas);

		actorSprite.setTexture(actorTexture);
	}

	sf::Sprite &Actor::getActorSprite()
	{
		return actorSprite;
	}

	void Actor::move(int direction, float delta, float move)
	{
		float gameDT = speedOfActor * delta;

		vec2f currentPos = getPosCen();

		//character move machina
		switch (direction)
		{
		case Up:		setCenPos({ currentPos.x, currentPos.y - (move + gameDT) }); break;
		case Down:		setCenPos({ currentPos.x, currentPos.y + (move + gameDT) }); break;
		case Left:		setCenPos({ currentPos.x - (move + gameDT), currentPos.y }); break;
		case Right:		setCenPos({ currentPos.x + (move + gameDT), currentPos.y }); break;
		case LeftUp:	setCenPos({ currentPos.x - (move + gameDT), currentPos.y - (move + gameDT) }); break;
		case UpRight:	setCenPos({ currentPos.x + (move + gameDT), currentPos.y - (move + gameDT) }); break;
		case LeftDown:	setCenPos({ currentPos.x - (move + gameDT), currentPos.y + (move + gameDT) }); break;
		case DownRight:	setCenPos({ currentPos.x + (move + gameDT), currentPos.y + (move + gameDT) }); break;
		}

		setActorPos(getPos());

		//sprite chages machina
		switch ((frameDelay == delayConst))
		{
		case true:
			frameDelay = 0;
			switch ((spriteStage == 2))
			{
			case true: spriteStage = 0; break; case false: spriteStage++; break;
			}
			break;

		case false: frameDelay++; break;
		}

		setActorRect(direction, spriteStage);
	}

	void Actor::calculatePointsForAtlas()
	{

		for (int direction = Idle; direction < DownRight + 1; direction++)
		{
			std::vector<vec2f> localPos;

			vec2f posAt;

			if (direction == Idle)
			{
				posAt = { getSize().x * 3, getSize().y * 3 };
				localPos.emplace_back(posAt); spritesCoords.emplace_back(localPos);
				continue;
			}

			vec2f dirTo = { getSize().x * 3, getSize().y * 3 };

			for (int pos = 0; pos < 3; pos++)
			{
				switch (direction)
				{
				case Up:	dirTo.y -= getSize().y; break;
				case Down:	dirTo.y += getSize().y; break;
				case Left:	dirTo.x -= getSize().x; break;
				case Right:	dirTo.x += getSize().x; break;
				case LeftUp:
					dirTo.y -= getSize().y;
					dirTo.x -= getSize().x;
					break;
				case UpRight:
					dirTo.y -= getSize().y;
					dirTo.x += getSize().x;
					break;
				case LeftDown:
					dirTo.y += getSize().y;
					dirTo.x -= getSize().x;
					break;
				case DownRight:
					dirTo.y += getSize().y;
					dirTo.x += getSize().x;
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
	void Actor::resetToZeroFrame()
	{
		frameDelay = 0;
		spriteStage = 0;
		setActorRect(0, 0);
	}
}