#pragma once

#include "Object.h"

namespace xphase
{
	class Door : Object
	{
	private:
		int toDoor = 0;
	};

	class Trigger : Object
	{
	public:
		enum typeUse
		{
			ONCE,
			CHARACTER,
			EMPTY
		};
	private:
		int type = EMPTY;
		int characterNum;

	public:
		void setType() {}
	};

	class Collision : public Object
	{
	public:
		int create() { return EXIT_OK; }
	};

	class Layer : public Object
	{
	private:
		sf::Texture texture;
	
	public:
		sf::Sprite sprite;

	public:
		int create() { return EXIT_OK; }
	};

	class Scene : public Object
	{
	private:
		//All objects
		std::vector<Door> doors;
		std::vector<Trigger> triggers;
		std::vector<Collision> collisions;
		std::vector<Layer> layers;

	private:
		std::string pathToTexture = "";

	public:
		int create();
		void update(double delta);
	};

	class World
	{
	private:
		std::vector<Scene> scenes;

	private:
		sf::Texture scTexture;
		sf::Sprite scSprite;

	public:
		int create();
		void update(double delta, int playerLocation);
	};
}