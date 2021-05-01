#pragma once

#include "Object.h"

namespace xphase
{
	class Actor : public Object
	{
	public:
		enum MoveDirection
		{
			Idle,
			Up, Down, Left, Right,
			LeftUp, UpRight, LeftDown, DownRight
		};

	private:
		std::string pathToAtlas;
		std::vector<std::vector<vec2f>> spritesCoords;

	private:
		float pseudoCameraAngle = 0.0f,
			speedOfActor = 0.002f;

		short spriteStage = 0,
			frameDelay = 0,
			delayConst = 30;

		sf::Texture actorTexture;
		sf::Sprite actorSprite;

	public:
		virtual int create() { return EXIT_OK; }

		void setAngle(float angle)				{ pseudoCameraAngle = angle; }
		void setSpeed(float speed)				{ speedOfActor = speed; }
		void setDelay(short delay)				{ delayConst = delay; }

		void setPathToAtlas(std::string path)	{ pathToAtlas = path; }

		float getAngle()						{ return pseudoCameraAngle; }
		float getSpeed()						{ return speedOfActor; }
		float getDelay()						{ return delayConst; }

		virtual void move(int direction, float delta, float move);

	public:
		void calculatePointsForAtlas();
		sf::IntRect getRectForCharacter(int direction, int stage);
	};
}