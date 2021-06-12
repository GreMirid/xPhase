#pragma once

#include "Module.h"

namespace xphase
{
	//Code for Triggers
	class Scripts : public Module
	{
	private:
		std::vector<std::string> existedFilesIn;
	public:
		int load(Window &window, std::string &path_to_file);


	};
}