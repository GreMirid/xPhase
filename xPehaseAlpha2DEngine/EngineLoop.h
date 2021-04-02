
#include "Core.h"

namespace xphase
{
	class EngineLoop
	{
	private:
		float startFrameTime = 0, endFrameTime = 0;
		bool isWindowOpen = false;
	public:
		virtual void openWindow()
		{
			isWindowOpen = true;
		}
		virtual void frame(int delta);
		virtual void loop()
		{
			while (isWindowOpen)
			{
				float delta = endFrameTime - startFrameTime;

				startFrameTime = getTime();

				frame(delta); //do staff

				endFrameTime = getTime();
			}
		};
	};
}
