#include "UserInterface.h"

namespace xphase
{
	void Button::set(const vec2f& pos_, const vec2f& size_, int flag)
	{
		buttonBody.setPointCount(4);

		buttonBody.setPoint(0, sf::Vector2f(0, 0));
		buttonBody.setPoint(1, sf::Vector2f(size_.x, 0));
		buttonBody.setPoint(2, sf::Vector2f(size_.x, size_.y));
		buttonBody.setPoint(3, sf::Vector2f(0, size_.y));

		buttonBody.setFillColor(backgraundColor);

		buttonBody.setPosition(pos_.x, pos_.y);

		pc = { size_.x / 2, size_.y / 2 }; pos = pos_; size = size_; roleFlag = flag;
	}

	void Button::setColors(const sf::Color& backColor, bool light)
	{
		const char difference = 22; //just for dark colors

		backgraundColor = backColor;

		sf::Color bColor = backgraundColor;

		switch (light)
		{
		case true:
			bColor.r += difference;
			bColor.g += difference;
			bColor.b += difference;

			selectedColor.r = bColor.r;
			selectedColor.g = bColor.g;
			selectedColor.b = bColor.b;

			bColor.r += difference;
			bColor.g += difference;
			bColor.b += difference;

			pressedColor.r = bColor.r;
			pressedColor.g = bColor.g;
			pressedColor.b = bColor.b;
			break;

		case false:
			bColor.r -= difference;
			bColor.g -= difference;
			bColor.b -= difference;

			selectedColor = bColor;

			bColor.r -= difference;
			bColor.g -= difference;
			bColor.b -= difference;

			pressedColor = bColor;
			break;
		}
	}

	void Button::setText(std::string& text, sf::Font& txtFnt, sf::Color& txtClr, int letterSize)
	{
		buttonText.setFont(txtFnt);

		buttonText.setFillColor(txtClr);
		buttonText.setCharacterSize(letterSize);

		buttonText.setPosition(pos.x + 5, (pc.y + pos.y) - (letterSize / 1.5f));

		buttonText.setString(text);
	}

	void Button::drawButton(sf::RenderWindow& window)
	{
		window.draw(buttonBody);
		window.draw(buttonText);
	}

	void Button::setPosition(const vec2f& pos_)
	{
		vec2f pos = pos_;
		buttonBody.setPosition(pos.x, pos.y);
		buttonText.setPosition(pos.x + 5, (pc.y + pos.y) - (buttonText.getCharacterSize() / 1.5f));
	}

	void Button::isButtonUnderCursor(const sf::RenderWindow& window, const vec2f& nowZeroPosition)
	{
		if ((((sf::Mouse::getPosition(window).x + nowZeroPosition.x) > buttonBody.getPosition().x) && (sf::Mouse::getPosition(window).x + nowZeroPosition.x < (buttonBody.getPosition().x + size.x))) && ((sf::Mouse::getPosition(window).y + nowZeroPosition.y > buttonBody.getPosition().y) && (sf::Mouse::getPosition(window).y + nowZeroPosition.y < (buttonBody.getPosition().y + size.y))))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) isButtonPressed();
			else buttonBody.setFillColor(selectedColor);
		}
		else
		{
			buttonBody.setFillColor(backgraundColor);
			itButtonPressed = false;
		}
	}

	void Button::isButtonPressed()
	{
		buttonBody.setFillColor(pressedColor);
		itButtonPressed = true;
	}
}