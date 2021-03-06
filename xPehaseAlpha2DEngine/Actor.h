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
			speedOfActor = 0.002f,
			delayConst = 0.2f,
			frameDelay = 0;

		short spriteStage = 0;

	public:
		sf::Sprite actorSprite;

	public:
		virtual int create() { return EXIT_OK; }

		void setAngle(float angle)				{ pseudoCameraAngle = angle; }
		void setSpeed(float speed)				{ speedOfActor = speed; }
		void setDelay(short delay)				{ delayConst = delay; }

		virtual void setActorPos(const vec2f &pos);
		virtual void setActorCenPos(const vec2f &pos);
		virtual void setActorRect(int direction, int spriteStage);
		virtual void setActorSpeed(float speed);
		virtual void setActorScale(const vec2f &scale);

		void setPathToAtlas(std::string path)	{ pathToAtlas = path; }

		virtual void setSprite();

		float getAngle()						{ return pseudoCameraAngle; }
		float getSpeed()						{ return speedOfActor; }
		float getDelay()						{ return delayConst; }

		sf::Sprite &getActorSprite();

		virtual void move(int direction, float delta, float move);
		virtual void animate(Window &window, int direction);

	public:
		void calculatePointsForAtlas();
		sf::IntRect getRectForCharacter(int direction, int stage);
		void resetToZeroFrame();
	};
}