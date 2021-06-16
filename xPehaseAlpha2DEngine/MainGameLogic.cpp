#include "Engine.h"

namespace xphase
{
	void GameLogic::create(Game *game)
	{
		//TASK:
		/// On create, set own params from created game
	}

	void GameLogic::update(Game *game)
	{
		//Task:
		/// create own logic fo local game
		sf::String question = L"Вопрос";
		sf::String text = L"";

		switch (game->player.getLocation())
		{
		case 0:

			if (game->player.isOnTrigger() && game->UI.dialogInterface.buttonWasPressed() == 5)
			{
				game->UI.dialogInterface.isButtonsShow(true);

				switch (game->player.isOnTriggerNumber())
				{
				case 0: text = L"Сколько из 40 апельсинов будет, если 15 из них были проданы?"; break;
				}

				game->UI.dialogInterface.setName(question);
				game->UI.dialogInterface.setText(text);
			}
			else
			{
				game->UI.dialogInterface.hide(game->player);
			}

			break;
		}
	}

	//create one
	GameLogic m_gameLogic;
}