
#include "Core.h"

namespace xphase
{
	int TextureManager::create(Window &window)
	{
		nullTexture = new sf::Texture();

		nullTexture->setRepeated(true);

		INIReader reader(window.getPathtoGame() + TO_CFG + "config.ini");

		std::string path = window.getPathtoGame() + TO_RES + reader.Get("Texture", "path", "standart.png");

		if (!nullTexture->loadFromFile(path)) return EXIT_ERROR;

		else return EXIT_OK;
	}

	sf::Texture* TextureManager::loadTexture(std::string &path_to)
	{
		//Load Texture
		sf::Texture* texture = new sf::Texture();

		if (!texture->loadFromFile(path_to)) return nullTexture;

		//set standrt params to texture
		texture->setRepeated(true);

		//Check on created file
		for (TexIter it = g_Textures.begin(); it != g_Textures.end(); it++)
		{
			if (it->first == path_to) return it->second;
		}

		//Insert in map
		g_Textures[path_to] = texture;

		//REturn Adress
		return g_Textures[path_to];
	};

	TextureManager m_Textures;
}