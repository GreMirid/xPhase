#pragma once

#include "Module.h"

// todo: make logic to actions

namespace xphase
{
	class Scripts : public Module
	{
	private:
		std::vector<std::string> existedFilesIn;

	public:
		int load(Window &window, std::string &path_to_file);

		// void act(scene_context);
	};
}