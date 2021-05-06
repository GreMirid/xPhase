#pragma once

#include "Actor.h"

namespace xphase
{
	class Player : public Actor
	{
	private:
		int location = 0;
		bool itMoveFlag = false;

	private:
		bool up, down, left, right,
			blockUpFlag = false,
			blockDownFlag = false,
			blockLeftFlag = false,
			blockRightFlag = false;

	private:
		sf::Font font;
		sf::Text text;

	public:
		int create(Window &window);

		void update(Window & window, float delta);

		void draw(Window &window);

		//Getter
		int getLocation()					{ return location; }

		//Setter
		void setLocation(int loc)			{ location = loc; }
		void setText(sf::String &intext);

	public:
		void setBlockedUp(bool block)		{ blockUpFlag = block; }
		void setBlockedDown(bool block)		{ blockDownFlag = block; }
		void setBlockedLeft(bool block)		{ blockLeftFlag = block; }
		void setBlockedRight(bool block)	{ blockRightFlag = block; }

	private:
		void updateText();
		void setTextData(sf::String &intext, sf::Font &infont, sf::Color &color, int characterSize);
	};
}