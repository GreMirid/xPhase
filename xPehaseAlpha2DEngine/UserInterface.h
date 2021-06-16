#pragma once

#include "Module.h"
#include "Player.h"

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
		vec2f &getSize() { return size; }

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
			sf::Sprite backgraundSprite;
			sf::Sprite gameLogo;
			sf::String continueGame;

			bool snglClrFlag = false,
				isAlreadyGame = false,
				isChanged = false;
			int mmsqsFlag = MainMenuSequnce;

		private:
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
			void isMainMenuSequence(int flag)		{ mmsqsFlag = flag; }

		} mM;

		class Settings
		{
		private:
			int statFlag = SettingsSequence;
			int from = 0;
			Button button;

		public:
			int create(Window &window);
			int draw(Window &window);

			void update(int status, Window &window, float delta);

		} st;

		class GameMenu
		{
		private:
			sf::ConvexShape menuDraw;
			sf::Text text;
			Button buttons[3];
			
			vec2f size,
				needPoint,
				nowPoint;

			bool isGameMenuSequenceFlag = false,
				isNotEndAnimation = false;

		public:
			int create(Window &window);
			bool update(Window &window, Player &player, float delta);

			void draw(Window &window);

			bool isGameMenuSequence()			{ return isGameMenuSequenceFlag; }
			void isGameMenuSequence(bool var)	{ isGameMenuSequenceFlag = var; }

			int buttonsWasPressed();

		private:
			void animation(float delta);
		} igme;


		class DialogInterface
		{
		private:
			sf::ConvexShape
				dialogBar,
				nameBar;
			sf::Text
				dialogText,
				nameText;

			sf::String endDialogText,
				buttonEndDialogText;

			Button buttons[4];

			bool isDialogFlag = false,
				isButtonsShowFlag = false,
				isEndOfDialogFlag = false,
				itWillShowFlag = true;

			short buttonsToShowCount = 0,
				answerNumber = 5;

		public:
			int create(Window &window);
			void update(Window &window, Player &player);
			void draw(Window &window);

			void hide(Player &player);

			//set
			void isDialog(bool var)			{ isDialogFlag = var; }
			void isEndOfDialog(bool var)	{ isEndOfDialogFlag = var; }
			void isButtonsShow(bool var)	{ isButtonsShowFlag = var; }

			//get
			bool isDialog()					{ return isDialogFlag; }
			bool isButtonsShow()			{ return isButtonsShowFlag; }
			bool isEndOfDialog()			{ return isEndOfDialogFlag; }
			short buttonWasPressed()		{ return answerNumber; }

			void setButtons(std::vector<sf::String> &buttonsText);
			void setText(sf::String &text);
			void setName(sf::String &text);

		private:
			void calculatePos(Window &window, const vec2f &nowZeroPos);

		} dialogInterface;

		class MiscIntarface
		{
		private:
			sf::Text fpsCounter;
		public:
			int create(Window &window);
			void update(Window &window, Player &player);
			void draw(Window &window);
		} misc;

		class HelperObject
		{
		private:
			sf::Sprite helper;

			bool isShown = false;

			enum helpers
			{
				MovementHelper,
				ActionHelper
			};

			std::string
				movementhelper,
				actionHelper;

		public:
			int create(Window &window);
			void update(Player &player);
			void draw(Window &window);

			//TASK:
			///Just create this to children mode

			void setCustomHelper(std::string &path);

			bool isShow() { return isShown; }
			void show() { isShown = true; }
			void hide() { isShown = false; }
		} helper;

		int load(Window& window);
		void draw(Window& window);
	};
}