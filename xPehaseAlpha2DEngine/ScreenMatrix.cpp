#include "Matrix.h"

namespace xphase
{
	void ScreenMatrix::create(const vec2f& size)
	{
		screenSize = size;
		matScale = { (screenSize.x / matSize.x), (screenSize.y / matSize.y) };

		/*for (float y = 0; y < matSize.y; y++) { for (float x = 0; x < matSize.x; x++) {
		matPoint tempPoint = { x * matScale.x, y * matScale.y }; matrix.emplace_back(tempPoint); } }*/
	}

	vec2f ScreenMatrix::getRealPoint(const vec2f& point)
	{
		return { point.x * matScale.x, point.y * matScale.y };
	}

	vec2f ScreenMatrix::getRealScreenSizeButHalf()
	{
		return { screenSize.x / 2, screenSize.y / 2 };
	}
}