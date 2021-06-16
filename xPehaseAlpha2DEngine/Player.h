#pragma once

#include "Actor.h"

namespace xphase
{
	class Player : public Actor
	{
	private:
		int location = 0,
			onTriggerNumber = 0;
		bool itMoveFlag = false,
			isOnTriggerFlag = false;

		//pos + size coords
		vec2f dub = {0, 0};

	private:
		bool up, down, left, right,
			blockUpFlag = false,
			blockDownFlag = false,
			blockLeftFlag = false,
			blockRightFlag = false,
			debug;

	private:
		sf::Text text;

		sf::String doorText, triggerText, 
			emptyText = "";

	public:
		int create(Window &window);

		void update(Window &window, float delta);

		void draw(Window &window);

		//Getter
		int getLocation()					{ return location; }
		vec2f &getDub()						{ return dub; }
		sf::String &isDoor()				{ return doorText; }
		sf::String &isTrigger()				{ return triggerText; }
		sf::String &cleanText()				{ return emptyText; }
		bool isOnTrigger()					{ return isOnTriggerFlag; }
		int isOnTriggerNumber()				{ return onTriggerNumber; }

		//Setter
		void setLocation(int loc)			{ location = loc; }
		void setText(sf::String &intext);
		void isOnTrigger(bool var)			{ isOnTriggerFlag = var; }
		void isOnTriggerNumber(int var)		{ onTriggerNumber = var; }

	public:
		void setBlockedUp(bool block)		{ blockUpFlag = block; }
		void setBlockedDown(bool block)		{ blockDownFlag = block; }
		void setBlockedLeft(bool block)		{ blockLeftFlag = block; }
		void setBlockedRight(bool block)	{ blockRightFlag = block; }

		bool getAlreadyBlockedUp()			{ return blockUpFlag; }
		bool getAlreadyBlockedDown()		{ return blockDownFlag; }
		bool getAlreadyBlockedLeft()		{ return blockLeftFlag; }
		bool getAlreadyBlockedRight()		{ return blockRightFlag; }

	private:
		void updateText();
		void updateDub();
		void setTextData(sf::String &intext, sf::Font &infont, sf::Color &color, int characterSize);
	};
}