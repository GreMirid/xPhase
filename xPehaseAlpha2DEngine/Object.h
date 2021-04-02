
#include "Core.h"

namespace xphase
{
	class Object
	{
	public:
		virtual int create()
		{
			countObjects++;
			return 0;
		};
		virtual void destroy()
		{
			delete this;
		};

	public:
		//Getter
		virtual v2f getPos()
		{
			return pos;
		};
		virtual v2f getSize()
		{
			return size;
		};
		virtual v2f getPosCen()
		{
			return posCen;
		};
		//Setter
		virtual void setPos(const v2f& poS)
		{
			pos = poS;
		}
		virtual void setSize(const v2f& sizE)
		{
			size = sizE;
		}
		virtual void setCenPos(const v2f& cenPos)
		{
			posCen = cenPos;
		}

	public:
		int getObjectsCount()
		{
			return countObjects;
		}
		
	private:
		v2f pos;
		v2f size;
		v2f posCen;
		static int countObjects;
	};

	int Object::countObjects = 0;

}