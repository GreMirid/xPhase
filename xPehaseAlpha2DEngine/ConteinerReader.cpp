 
#include "ConteinerReader.h"

ConteinerReader::ConteinerReader(const char& type)
{
	setlocale(0, "ru");

	std::ifstream headerFile;
	std::wifstream tempFile;

	std::string path = sc;

	switch (type)
	{
	case CHARACTER:
		path += characterPath;
		break;
	case SCENE:
		path += scenesPath;
		break;
	case DIALOGSCRIPT:
		path += dialogScriptPath;
		break;
	case SCRIPT:
		path += scriptPath;
		break;
	case PLAYERCONFIG:
		path += playerConfigPath;
		break;
	}

	//TASK:

	/// JUST READ THE DIRECTORY AND READ FILES IN EXCO

	headerFile.open(path + dataEnd);

	std::string tempPath = "";
	std::wstring tempFile_S = L"";

	while (getline(headerFile, tempPath, ';'))
	{
		std::cout << tempPath << "\n";

		tempFile.open(path + '/' + tempPath + dataEnd);

		if (!tempFile.is_open()) continue; //if it do dosen't open, it just skip

		tempFile.imbue(std::locale(".1251"));

		//it's just way better than std::getline(tempFile, tempFile_S);
		tempFile_S.assign(std::istreambuf_iterator<wchar_t>(tempFile), std::istreambuf_iterator<wchar_t>());

		std::wcout << tempFile.is_open() << L", Inside: " << tempFile_S << "\n";

		for (int i = 0; i < tempFile_S.length();)
			if (tempFile_S[i] == '\n' || tempFile_S[i] + tempFile_S[i + 1] == ' ' + ' ') tempFile_S.erase(i, 1); else i++;

		moduleFiles.emplace_back(tempFile_S);

		tempFile_S = L""; tempFile.close();
	}
	headerFile.close();
}

std::wstring ConteinerReader::getLoadedFile(const size_t& index)
{
	return moduleFiles[index];
}

size_t ConteinerReader::getNumberFilesInConteiner()
{
	return moduleFiles.size();
}

WSTRMAS ConteinerReader::separateData(std::wstring data, const wchar_t& separator)
{
	WSTRMAS TempMas;

	std::wstring tempLine = L"";
	size_t pos = 0;

	while ((pos = data.find(separator)) != std::string::npos)
	{
		tempLine = data.substr(0, pos);

		TempMas.emplace_back(tempLine);

		data.erase(0, pos + 1);
	}

	//There is to past last empty element 
	TempMas.emplace_back(L"");

	return TempMas;
}

std::string ConteinerReader::toString(const std::wstring& data)
{
	const std::string toreturn(data.begin(), data.end());
	return toreturn;
}

int ConteinerReader::toInt(const std::wstring& data)
{
	return std::stoi(data);
}