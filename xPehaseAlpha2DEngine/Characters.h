#pragma once

#include "Actor.h"
#include "Scenario.h"

namespace xphase
{
	class Character : public Actor
	{
	private:

	public:
		int create(Window &window, std::string &path_to_script);
	};

	class Characters
	{
	private:
		std::vector<Character> characters;
	public:
		int create(Window &window);
	};

	extern Characters m_Characters;
}