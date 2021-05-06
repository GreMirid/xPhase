
#include "VarTrash.h"

namespace xphase
{
	float fast_sqrt(float x)
	{
		float r = x;
		unsigned int *i = (unsigned int*)&r;

		*i = 0x5f375a86 - (*i >> 1);

		return (x * r * (1.5f - 0.5f * x * r * r));
	}
}