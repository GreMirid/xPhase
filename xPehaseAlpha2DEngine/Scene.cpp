#include "World.h"

namespace xphase
{
	int Scene::create(vec2f cenpos, vec2f scale, const std::string &path)
	{
		//TASK:
		/// USE CONTEINER READER FOR LOAD FILE AND PAST ALL OBJECT IN CLASS SCENE
		pathToTexture = path;

		//FIX:
		/// In std::vector, sf::Texture lost his memory adress and texture is not drawning
		/// Solution: don't write and texture and sprite in Scene class
		/// Write this in World class

		sf::Texture sceneTexture;

		if (!sceneTexture.loadFromFile(pathToTexture)) return EXIT_ERROR;

		setScale(scale);
		setSize({ sceneTexture.getSize().x * scale.x, sceneTexture.getSize().y * scale.y });
		setCenPos(cenpos);

		return EXIT_OK;
	}

	void Scene::update(Window &window, double delta, Player &player)
	{
		player.setBlockedUp(player.getPos().y < getPos().y + player.getAngle());
		player.setBlockedDown(player.getPos().y > (getPos().y + getSize().y) - (player.getSize().y * player.getScale().y));

		player.setBlockedLeft(player.getPos().x < getPos().x);
		player.setBlockedRight(player.getPos().x > (getPos().x + getSize().x) - (player.getSize().x * player.getScale().x));

		/*
		COLISSIONS OF SCENE
		UP (PLAYER POS Y < POS SCENE Y + PLAYER ANGLE)
		DOWN (PLAYER POS Y > (POS SCENE Y + SCENE SIZE Y) - PLAYER SIZE Y)
		LEFT (PLAYER POS X < POS SCENE X)
		RIGHT (PLAYER POS X > (POS SCENE X + SCENE SIZE X) - PLAYER SIZE X)
		*/

		for (size_t unit = 0; unit < collisions.size(); unit++)
		{
			if (collisions[unit].isEnabled())
				collisions[unit].update(player, delta);
		}
	}

	void Scene::draw(Window &window)
	{
		switch (window.isDrawBorders())
		{
		case true:
			for (size_t unit = 0; unit < doors.size(); unit++)
				window.drawArea.draw(doors[unit].visual);

			for (size_t unit = 0; unit < triggers.size(); unit++)
				window.drawArea.draw(triggers[unit].visual);

			for (size_t unit = 0; unit < collisions.size(); unit++)
				window.drawArea.draw(collisions[unit].visual);
			break;
		}
	}

	void Scene::drawLayers(Window &window)
	{
		for (size_t unit = 0; unit < layers.size(); unit++)
		{
			layers[unit].draw(window);
		}
	}

	void Scene::addDoor(vec2f &pos, int to_door, int to_location, float scale)
	{
		Door tempd;

		tempd.create(pos, to_door, to_location, scale);

		doors.emplace_back(tempd);
	}

	void Scene::addTrigger(vec2f &pos, vec2f &size, int type)
	{
		Trigger tempt;

		tempt.create(pos, size, type);

		triggers.emplace_back(tempt);
	}

	void Scene::addCollision(vec2f &pos, vec2f &size)
	{
		Collision tempc;

		tempc.create(pos, size);

		collisions.emplace_back(tempc);
	}

	void Scene::addLayer(vec2f &pos, vec2f &scale, const std::string &path_to_texture)
	{
		Layer templ;

		templ.create(pos, scale, path_to_texture);

		layers.emplace_back(templ);
	}

	void Scene::clear()
	{
		doors.clear();
		triggers.clear();
		collisions.clear();
		layers.clear();

		setPos({ 0, 0 });
		setSize({ 0, 0 });
		setScale({ 0, 0});

		pathToTexture = "";
	}
}