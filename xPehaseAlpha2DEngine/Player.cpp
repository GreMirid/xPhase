#include "Player.h"

namespace xphase
{
	int Player::create(Window &window)
	{
		//TASK:
		/// Load from ini params and past it here
		INIReader reader(window.getPathtoGame() + TO_CFG + "player.ini");

		if (reader.ParseError() != 0) return EXIT_ERROR;

		setLocation(reader.GetInteger("Main", "first_location", 0));

		setSize
		(
			{
				float(reader.GetInteger("Main", "size_x", 0)),
				float(reader.GetInteger("Main", "size_y", 0))
			}
		);

		/// CALCULATE ATLAS
		setPathToAtlas(window.getPathtoGame() + TO_RES + reader.Get("Main", "atlas", ""));

		calculatePointsForAtlas();

		/// SET IMAGE FROM PATH
		setSprite();

		/// SET NEED POS AND SIZE IN ATLAS
		setActorRect(0, 0);

		/// SET POSITION
		vec2f playerPos = {0, 0};
		vec2f playerPosFromIni = { reader.GetInteger("Spawn", "spawn_coords_x", 0) , reader.GetInteger("Spawn", "spawn_coords_y", 0) };

		/// x
		if (reader.GetString("Spawn", "spawn_coords_x", "") == "SC_A")
			playerPos.x = (window.screenMatrix.getRealScreenSize().x / 2) - (getSize().x / 2);
		else
			playerPos.x = window.screenMatrix.getRealPoint(playerPosFromIni).x;

		/// y
		if (reader.GetString("Spawn", "spawn_coords_y", "") == "SC_A")
			playerPos.y = (window.screenMatrix.getRealScreenSize().y / 2) - (getSize().y / 2);
		else
			playerPos.y = window.screenMatrix.getRealPoint(playerPosFromIni).y;

		setActorCenPos(playerPos);

		float scale = reader.GetInteger("Set", "scale", 1);

		setActorScale({ scale * window.screenMatrix.getMatrixScale().x,  scale * window.screenMatrix.getMatrixScale().y });

		setActorSpeed(reader.GetReal("Set", "speed", 0.0f) * ((window.screenMatrix.getMatrixScale().x + window.screenMatrix.getMatrixScale().y) / 2) );

		return EXIT_OK;
	}

	void Player::update(Window &window, float delta)
	{
		up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

		itMoveFlag = up || down || left || right;

		switch (itMoveFlag)
		{
		case true:

			//keys for using
			if (left & up) move(LeftUp, delta, 1);
			else if (up & right) move(UpRight, delta, 1);
			else if (left & down) move(LeftDown, delta, 1);
			else if (down & right) move(DownRight, delta, 1);
			else if (up) move(Up, delta, 1);
			else if (down) move(Down, delta, 1);
			else if (left) move(Left, delta, 1);
			else if (right) move(Right, delta, 1);

			break;
		case false: resetToZeroFrame(); break;
		}
	}

	void Player::draw(Window &window)
	{
		window.drawArea.draw(actorSprite);
	}
}