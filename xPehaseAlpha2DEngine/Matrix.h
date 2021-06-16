#pragma once

#include "Vector2.h"
//#include <vector>

namespace xphase
{
	class ScreenMatrix
	{
	private:
		vec2f matSize = {1280, 720},
			screenSize,
			matScale;

		//struct matPoint { vec2f screenPoint; };
		//std::vector<matPoint> matrix;

	public:
		void create(const vec2f& size);

		/*vec2f& getRealPoint(const vec2f& point) {
		// " Point X + ( Matrix Size X * Point Y ) " - it's how to get a member of line massive by x and y
		return matrix[ int( point.x + ( matSize.x * point.y ) ) ].screenPoint; }*/

		float getTotalMatrixScale();

		vec2f getRealPoint(const vec2f& point);

		vec2f& getMatrixScale()		{ return matScale; }
		vec2f& getMatrixSize()		{ return matSize; }
		vec2f& getRealScreenSize()	{ return screenSize; }

		vec2f getRealScreenSizeButHalf();
	};
}