#pragma once

#include "Vector2.h"
#include <vector>

namespace xphase
{
	class ScreenMatrix
	{
	private:
		struct matPoint
		{
			vec2f screenPoint;
		};

	private:
		const vec2f matSize = {1280, 720};
		std::vector<matPoint> matrix;
		vec2f screenSize, matScale;

	public:
		void create(const vec2f& size)
		{
			screenSize = size;
			matScale = { (screenSize.x / matSize.x), (screenSize.y / matSize.y) };

			for (float y = 0; y < matSize.y; y++)
			{
				for (float x = 0; x < matSize.x; x++)
				{
					matPoint tempPoint = { x * matScale.x, y * matScale.y };

					matrix.emplace_back(tempPoint);
				}
			}
		};

		vec2f& getRealPoint(const vec2f& point)
		{
			// " Point X + ( Matrix Size X * Point Y ) " - it's how to get a member of line massive by x and y
			return matrix[ int( point.x + ( matSize.x * point.y ) ) ].screenPoint;
		}

		vec2f& getRealScale()
		{
			return matScale;
		}

		vec2f& getRealScreenSize()
		{
			return screenSize;
		}

	};
}