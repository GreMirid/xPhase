
#include "World.h"

namespace xphase
{
	int Layer::create(vec2f &pos, vec2f &size, std::string &path_to_texture)
	{
		setSize(size);
		setPos(pos);

		sprite.setTexture
		(
			*m_Textures.loadTexture(path_to_texture)
		);

		return EXIT_OK;
	}

	void Layer::draw(Window &window)
	{
		window.drawArea.draw(sprite);
	}
}