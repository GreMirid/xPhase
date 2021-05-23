
#include "World.h"

namespace xphase
{
	int Layer::create(vec2f &pos, vec2f &scale, std::string &path_to_texture)
	{
		setScale(scale);
		setPos(pos);

		sprite.setScale(scale.x, scale.y);
		sprite.setPosition(pos.x, pos.y);

		sprite.setTexture( *m_Textures.loadTexture(path_to_texture) );

		return EXIT_OK;
	}

	void Layer::draw(Window &window)
	{
		window.drawArea.draw(sprite);
	}
}