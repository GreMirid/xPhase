#include "World.h"

namespace xphase
{
	int Scene::create(vec2f cenpos, vec2f scale, vec2f size, const std::string &path)
	{
		//TASK:
		/// USE CONTEINER READER FOR LOAD FILE AND PAST ALL OBJECT IN CLASS SCENE

		setScale(scale);

		pathToTexture = path;

		texture.loadFromFile(pathToTexture);

		sprite.setTexture(texture);
		sprite.setScale(scale.x, scale.y);

		setSize({ size.x * scale.x, size.y * scale.y });

		setCenPos(cenpos);

		sprite.setPosition(getPos().x, getPos().y);

		return EXIT_OK;
	}

	void Scene::update(Window &window, double delta, Player &player)
	{
		player.setBlockedUp(player.getPos().y < getPos().y + player.getAngle());
		player.setBlockedDown(player.getPos().y > getPos().y + (getSize().y - player.getSize().y));

		player.setBlockedLeft(player.getPos().x < getPos().x + player.getAngle());
		player.setBlockedRight(player.getPos().x > getPos().x + getScale().x + (getSize().x - player.getSize().x));

		for (size_t objects = 0; objects < collisions.size(); objects++)
		{
			if (collisions[objects].isEnabled())
				collisions[objects].update(player, delta);
		}
	}

	void Scene::draw(Window &window)
	{
		window.drawArea.draw(sprite);
	}

	void Scene::drawLayers(Window &window)
	{
		for (size_t unit = 0; unit < layers.size(); unit++)
		{
			layers[unit].draw(window);
		}
	}

	void Scene::addDoor(vec2f &pos, int to_door, int to_location)
	{
		Door tempd;

		tempd.create(pos, to_door, to_location);

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