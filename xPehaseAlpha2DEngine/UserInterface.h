#pragma once

#include "Module.h"

namespace xphase
{
	class Button
	{
	public:
		bool itButtonPressed = false;
		vec2f pc, pos, size;

		sf::Color backgraundColor, selectedColor, pressedColor;
		sf::ConvexShape buttonBody;
		sf::Text buttonText;
		
		std::function<void(void)> func;

		void set(const vec2f& pos_, const vec2f& size_);
		void setColors(const sf::Color& backColor);
		void setText(const std::wstring& text, const sf::Font& font, const sf::Color& textColor, const char& letterSize);
		void setPosition(const vec2f& pos_);

		//TASK:
		/// Create getter

		void isButtonUnderCursor(const sf::RenderWindow& window, const vec2f& nowZeroPosition, const bool& rej);
		void isButtonPressed(const bool& rej);

		void drawButton(sf::RenderWindow& window);
	};

	class UserInterface : public Module
	{
	public:
		//TASK:
		/// Create a main menu screen
		class MainMenu
		{
		private:
			sf::Color backgraundColor;

			sf::Texture backgraundTexture;
			sf::Sprite backgraundSprite;

			bool snglClrFlag = false;
			int mmsqsFlag = 2;

		private:
			std::vector<Button> buttons;

		public:
			int create(Window& window);

			int draw(Window& window);

		public:
			bool isJustOnlyColor()					{ return snglClrFlag; }
			void isJustOnlyColor(bool boolean)		{ snglClrFlag = boolean; }

			int isMainMenuSequence()				{ return mmsqsFlag; }
			void isMainMenuSequence(int flag)	{ mmsqsFlag = flag; }

		} mM /*moo moo*/;

		int load(Window& window)
		{
			mM.create(window);

			return EXIT_OK;
		}
	};
}