#include "Player.h"

namespace xphase
{
	int Player::create(Window &window)
	{
		debug = window.isDebug();

		//TASK:
		/// Load standart phrases from config.ini
		INIReader rd(window.getPathtoGame() + TO_CFG + "config.ini");

		doorText = rd.Get("Texts", "door", "");
		doorText = sf::String::fromUtf8(doorText.begin(), doorText.end());

		triggerText = rd.Get("Texts", "trigger", "");
		triggerText = sf::String::fromUtf8(triggerText.begin(), triggerText.end());

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

		/// SET SCALE
		float scale = reader.GetInteger("Set", "scale", 1);

		setActorScale({ scale * window.screenMatrix.getMatrixScale().x,  scale * window.screenMatrix.getMatrixScale().y });

		/// 
		setActorSpeed
		(
			reader.GetReal("Set", "speed", 0.0f) * 
			(
				(window.screenMatrix.getMatrixScale().x + window.screenMatrix.getMatrixScale().y) / 2
			)
		);

		/// TEXT
		std::string font_path = window.getPathtoGame() + TO_RES + reader.Get("Text", "font_path", "");

		sf::String txt = reader.GetString("Text", "text", "");
		txt = sf::String::fromUtf8(txt.begin(), txt.end());

		sf::Color textColor = sf::Color
		(
			reader.GetInteger("Text", "color_r", 0),
			reader.GetInteger("Text", "color_g", 0),
			reader.GetInteger("Text", "color_b", 0)
		);

		setTextData
		(
			txt,
			*m_Font.loadFont(font_path),
			textColor,
			reader.GetInteger("Text","character_size", 0) * ((window.screenMatrix.getMatrixScale().x + window.screenMatrix.getMatrixScale().y) / 2)
		);
		
		/// 
		setAngle(-((getSize().y * getScale().y) - reader.GetInteger("Main", "angle", 0)));

		return EXIT_OK;
	}

	void Player::update(Window &window, float delta)
	{
		up = sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !blockUpFlag;
		down = sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !blockDownFlag;
		left = sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !blockLeftFlag;
		right = sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !blockRightFlag;

		itMoveFlag = up || down || left || right;

		switch (itMoveFlag)
		{
		case true:

			//keys for using
			if (left & up) move(LeftUp, delta, 1);
			else if (up & right) move(UpRight, delta, 1);
			else if (left & down) move(LeftDown, delta, 1);
			else if (down & right) move(DownRight, delta, 1);
			else if (left & right) resetToZeroFrame();
			else if (up & down) resetToZeroFrame();
			else if (up) move(Up, delta, 1);
			else if (down) move(Down, delta, 1);
			else if (left) move(Left, delta, 1);
			else if (right) move(Right, delta, 1);

			break;

		case false:
			//if it in colission
			switch ((blockUpFlag && blockDownFlag && blockLeftFlag && blockRightFlag))
			{
			case true:
				move(Down, delta, 1);
				break;
			case false:
				//set idle frame (anti-cyclopus)
				resetToZeroFrame();

				for(int limmitter = 0; (blockUpFlag || blockDownFlag || blockLeftFlag || blockRightFlag) && (limmitter < 100); limmitter++)
				{
					//if it in only in all, minwhile it not in all, where it will be do nothing
					if ((blockRightFlag && blockUpFlag) || (blockUpFlag && blockLeftFlag)) move(Down, delta, 0.001);
					if ((blockRightFlag && blockDownFlag) || (blockDownFlag && blockLeftFlag)) move(Up, delta, 0.001);
					if ((blockDownFlag && blockRightFlag) || (blockRightFlag && blockUpFlag)) move(Left, delta, 0.001);
					if ((blockDownFlag && blockLeftFlag) || (blockLeftFlag && blockUpFlag)) move(Right, delta, 0.001);
				}
				break;
			}
			break;
		}

		//Move With Text
		updateText();

		//Calculate collission
		updateDub();
	}

	void Player::draw(Window &window)
	{
		window.drawArea.draw(getActorSprite());
		window.drawArea.draw(text);
	}

	void Player::setText(sf::String &intext)
	{
		text.setString
		(
			(debug? "x:" + std::to_string(int(getPosCen().x)) + " y:" + std::to_string(int(getPosCen().y)) + (intext == ""? "": "\n"): "")
			+ intext
		);
	}

	void Player::updateText()
	{
		text.setPosition(( getPos().x + (getSize().x * getScale().x) / 2) - text.getLocalBounds().width / 2, getPos().y - (text.getLocalBounds().height + 3));
	}

	void Player::updateDub()
	{
		dub.x = getPos().x + (getSize().x * getScale().x);
		dub.y = getPos().y + (getSize().y * getScale().y);
	}

	void Player::setTextData(sf::String &intext, sf::Font &infont, sf::Color &color, int characterSize)
	{
		text.setString(intext);
		text.setCharacterSize(characterSize);
		text.setFont(infont);
		text.setFillColor(color);
		text.setPosition(0, 0);
	}
}