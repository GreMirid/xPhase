
#include "Object.h"

namespace xphase
{
	class Entity : public Object
	{
	public:
		int create()
		{
			return EXIT_OK;
		}
	};
}