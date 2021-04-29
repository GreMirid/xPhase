#pragma once

#include "Module.h"

namespace xphase
{
	class Button
	{
	private:
		bool itButtonPressed = false;
		int roleFlag = DoNotExec;
		vec2f pc, pos, size;

		sf::Color backgraundColor, selectedColor, pressedColor;
		sf::ConvexShape buttonBody;
		sf::Text buttonText;

	public:
		//create
		void set(const vec2f& pos_, const vec2f& size_, int flag);
		void setColors(const sf::Color& backColor, bool light);
		void setText(sf::String& text, sf::Font& font, sf::Color& textColor, int letterSize);

		//sets
		void setPosition(const vec2f& pos_);
		void reSetText(sf::String& text);

		void drawButton(sf::RenderWindow& window);

		void isButtonUnderCursor(const sf::RenderWindow& window, const vec2f& nowZeroPosition);

		//TASK:
		/// Create getter
		int getRole();

		void isButtonPressed(bool boolean);
		bool isButtonPressed();

	private:
		void ButtonPressed();
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

		class Settings
		{
		private:
			int statFlag = SettingsSequence;
			int from = 0;
			sf::Font font;
			Button button;

		public:
			int create(Window &window);
			int draw(Window &window);

			void update(int status, Window &window, float delta);

		} st;

		int load(Window& window);
	};
}