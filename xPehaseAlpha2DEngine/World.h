#pragma once

#include "Player.h"

namespace xphase
{
	//DOOR FOR SCENE OBJECT CLASS
	class Door : Object
	{
	public:
		sf::ConvexShape visual;

	private:
		int toDoor = 0, toLocation = 0;

	public:
		int create(vec2f &pos, int to_door, int to_location, float scale);
		int update(Player &player);
	};

	//TRIGGER FOR SCENE OBJECT CLASS
	class Trigger : Object
	{
	public:
		sf::ConvexShape visual;

	public:
		enum typeUse
		{
			ONCE,
			CHARACTER,
			EMPTY
		};
	private:
		int type = EMPTY;

	public:
		int create(vec2f &pos, vec2f &size, int type);
		void update(Player &player, float delta);
	};

	//COLISIION FOR SCENE OBJECT CLASS
	class Collision : public Object
	{
	public:
		sf::ConvexShape visual;

	private:
		float promoAngleSize = 0,
			promoAnglePos = 0;

		bool upSide = 0,
			downSide = 0,
			leftSide = 0,
			rightSide = 0;
		
		bool vertical = false,
			horizontal = false;

		vec2f dub = { 0, 0 };

	public:
		int create(vec2f &pos, vec2f &size);
		void update(Player &player, float delta);
	};

	//LAYER FOR SCENE OBJECT CLASS
	class Layer : public Object
	{
	private:
		//it's not will load
		sf::Texture texture;

	public:
		sf::Sprite sprite;

	public:
		int create(vec2f &pos, vec2f &scale, const std::string &path_to_texture);
		void draw(Window &window);
	};

	//SCENE OBJECT CLASS FOR WORLD CLASS
	class Scene : public Object
	{
	private:
		std::vector<Door> doors;
		std::vector<Trigger> triggers;
		std::vector<Collision> collisions;
		std::vector<Layer> layers;

	private:
		std::string pathToTexture = "";

	public:
		int create(vec2f cenpos, vec2f scale, const std::string &path);

		void update(Window &window, double delta, Player &player);

		void draw(Window &window);

		void drawLayers(Window &window);

	public:
		std::string &getPathToTexture() { return pathToTexture; }

	public:
		void addDoor(vec2f &pos, int to_door, int to_location, float scale);
		void addTrigger(vec2f &pos, vec2f &size, int type);
		void addCollision(vec2f &pos, vec2f &size);
		void addLayer(vec2f &pos, vec2f &scale, const std::string &path_to_texture);

	public:
		void clear();
	};

	//MAIN WORLD CLASS
	class World
	{
	private:
		std::vector<Scene> scenes;

	public:
		int create(Window &window);

		void update(Window &window, double delta, Player &player);

		void draw(Window &window, Player &player);

	private:
		sf::Texture sceneTexture;
		sf::Sprite sceneSprite;

	public:
		void reSetScene(int player_location);
	};
}