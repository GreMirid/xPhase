
#include "World.h"

namespace xphase
{
	int Layer::create(vec2f &pos, vec2f &size, const std::string &path_to_texture)
	{
		setSize(size);
		setPos(pos);

		texture.loadFromFile(path_to_texture);
		sprite.setTexture(texture);

		return EXIT_OK;
	}

	void Layer::draw(Window &window)
	{
		window.drawArea.draw(sprite);
	}
}