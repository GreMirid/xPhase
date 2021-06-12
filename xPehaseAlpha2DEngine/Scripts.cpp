#include "Scripts.h"

namespace xphase
{
	int Scripts::load(Window &window, std::string &path_to_file)
	{
		//TASK:
		/// Read all scripts and wite to RAM to use.

		std::string to = window.getPathtoGame() + TO_SCRIPTS + path_to_file;

		std::ifstream need; need.open(to);

		//std::vector<const char32_t[]> lines_in_file;

		
		//sscanf(buff, "%s = %s");


		return EXIT_OK;
	}
}