#pragma once

#include <iostream>
#include <fstream>

#include <vector>
#include <string>

#define WSTRMAS std::vector<std::wstring>

#define TO_CFG "\\cfg\\"
#define TO_RES "\\res\\"
#define TO_SCRIPTS "\\scripts\\"

namespace xphase
{
	class ConteinerReader
	{
	private:
		enum Types
		{
			CHARACTER,
			SCENE,
			DIALOGSCRIPT,
			SCRIPT,
			PLAYERCONFIG
		};

		const std::string characterPath = "characters";
		const std::string scenesPath = "scenes";
		const std::string dialogScriptPath = "dialog_script";
		const std::string scriptPath = "script";
		const std::string playerConfigPath = "player_config";

		const std::string textEnd = ".txt";
		const std::string dataEnd = ".dat";

		WSTRMAS moduleFiles;

	public:
		ConteinerReader(const std::string &game, char type);

		std::wstring getLoadedFile(const size_t& index);
		size_t getNumberFilesInConteiner();

		WSTRMAS separateData(std::wstring data, wchar_t separator);

		std::string toString(const std::wstring& data);
		int toInt(const std::wstring& data);
	};
}