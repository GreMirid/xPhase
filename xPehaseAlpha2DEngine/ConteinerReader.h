#pragma once

#include <iostream>
#include <fstream>
#include <locale>

#include <vector>
#include <string>

#include <unordered_map>

#define WSTRMAS std::vector<std::wstring>

#define TO_CFG "\\cfg\\"
#define TO_RES "\\res\\"
#define TO_SCRIPTS "\\scripts\\"

namespace xphase
{
	class ConteinerReader
	{
	public:
		enum Types
		{
			CHARACTER,
			SCENE,
			DIALOGSCRIPT,
			SCRIPT
		};

	private:
		const std::string characterPath = "characters";
		const std::string scenesPath = "scenes";
		const std::string dialogScriptPath = "dialog_script";
		const std::string scriptPath = "script";

		const std::string textEnd = ".txt";
		const std::string dataEnd = ".dat";

		WSTRMAS moduleFiles;

	public:
		ConteinerReader(const std::string &game, char type);

		std::wstring getLoadedFile(const size_t& index);
		size_t getNumberFilesInConteiner();

		WSTRMAS separateData(std::wstring data, wchar_t separator);
	};

	//From std::wstring to std::string
	std::string toString(const std::wstring& data);

	//From std::string to std::wstring
	std::wstring toWstring(std::string& data, const std::locale& loc = std::locale());

	//From std::wstring to int
	int toIFrmWS(const std::wstring& data);

	//From std::wstring to Float
	float toFlFrmWS(const std::wstring& data);
}