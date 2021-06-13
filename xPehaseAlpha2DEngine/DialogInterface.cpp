#include "UserInterface.h"

namespace xphase
{
	int UserInterface::DialogInterface::create(Window &window)
	{
		return EXIT_OK;
	}

	void UserInterface::DialogInterface::update(Window &window, Player &player)
	{
		// If it cannot need a dialog now
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			player.isOnTrigger(false);
		}
	}

	void UserInterface::DialogInterface::draw(Window &window)
	{
		if (isDialog())
		{
			window.drawArea.draw(dialogBar);
			window.drawArea.draw(dialogText);

			if (isButtonsShow())
			{
				//draw buttons
			}
		}
	}

	void UserInterface::DialogInterface::setButtons(std::vector<sf::String> buttonsText)
	{
		//task:
		/// create buttons for intarface with answers by "role 0 - 4"
	}
}