#include "Core.h"

namespace xphase
{
	int FontManager::create(Window &window)
	{
		nullFont = new sf::Font();

		INIReader reader(window.getPathtoGame() + TO_CFG + "config.ini");

		std::string path = window.getPathtoGame() + TO_RES + reader.Get("Font", "path", "font/mainfont.ttf");

		if (!nullFont->loadFromFile(path)) return EXIT_ERROR;

		else return EXIT_OK;
	}

	sf::Font* FontManager::loadFont(std::string &path_to)
	{
		//Load Texture
		sf::Font* font = new sf::Font();

		if (!font->loadFromFile(path_to)) return nullFont;

		//Check on created file
		for (FontIter it = g_Fonts.begin(); it != g_Fonts.end(); it++)
		{
			if (it->first == path_to) return it->second;
		}

		//Insert in map
		g_Fonts[path_to] = font;

		//REturn Adress
		return g_Fonts[path_to];
	};

	FontManager m_Font;
}