#pragma once

#include "Module.h"

namespace xphase
{
	class Button
	{
	public:
		bool itButtonPressed = false;
		int roleFlag = DoNotExec;
		vec2f pc, pos, size;

		sf::Color backgraundColor, selectedColor, pressedColor;
		sf::ConvexShape buttonBody;
		sf::Text buttonText;

		void set(const vec2f& pos_, const vec2f& size_, int flag);
		void setColors(const sf::Color& backColor, bool light);
		void setText(std::string& text, sf::Font& font, sf::Color& textColor, int letterSize);
		void setPosition(const vec2f& pos_);

		void drawButton(sf::RenderWindow& window);

		//TASK:
		/// Create getter

		void isButtonUnderCursor(const sf::RenderWindow& window, const vec2f& nowZeroPosition);
		void isButtonPressed();
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
			int mmsqsFlag = MainMenuSequnce;

		private:
			sf::Font fontB;
			sf::Color colorB;
			std::string buttonNum = "";
			int role = DoNotExec;

		private:
			std::vector<Button> buttons;

		public:
			int create(Window& window);

			int draw(Window& window);

			void update(Window& window, float delta);

		public:
			bool isJustOnlyColor()					{ return snglClrFlag; }
			void isJustOnlyColor(bool boolean)		{ snglClrFlag = boolean; }

			int isMainMenuSequence()				{ return mmsqsFlag; }
			void isMainMenuSequence(int flag)	{ mmsqsFlag = flag; }

		} mM;

		int load(Window& window)
		{
			mM.create(window);

			return EXIT_OK;
		}
	};
}