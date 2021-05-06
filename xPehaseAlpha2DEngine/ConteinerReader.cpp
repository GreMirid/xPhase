 #include "ConteinerReader.h"

namespace xphase
{
	ConteinerReader::ConteinerReader(const std::string &pathToGameFolder, char type)
	{
		std::ifstream headerFile;
		std::wifstream tempFile;

		std::string path = pathToGameFolder + TO_SCRIPTS;

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
		}

		//TASK:
		/// JUST READ THE DIRECTORY AND READ FILES IN EXCO

		headerFile.open(path + dataEnd);

		std::string tempPath = "";
		std::wstring tempFile_S = L"";

		while (getline(headerFile, tempPath, ';'))
		{
			std::cout << tempPath << "\n";

			tempFile.open(path + '\\' + tempPath + dataEnd);

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

	WSTRMAS ConteinerReader::separateData(std::wstring data, wchar_t separator)
	{
		WSTRMAS tempMas;

		std::wstring tempLine = L"";
		size_t pos = 0;

		while ((pos = data.find(separator)) != std::string::npos)
		{
			tempLine = data.substr(0, pos);

			tempMas.emplace_back(tempLine);

			data.erase(0, pos + 1);
		}

		//There is to past last empty element 
		tempMas.emplace_back(L"");

		return tempMas;
	}

	std::string toString(const std::wstring& data)
	{
		const std::string toreturn(data.begin(), data.end());
		return toreturn;
	}

	std::wstring toWstring(std::string& data, const std::locale& loc)
	{
		std::vector<wchar_t> buf(data.size());
		std::use_facet<std::ctype<wchar_t>>(loc).widen(data.data(), data.data() + data.size(), buf.data());
		return std::wstring(buf.data(), buf.size());
	}

	int toIFrmWS(const std::wstring& data)
	{
		return std::stoi(data);
	}

	float toFlFrmWS(const std::wstring& data)
	{
		return std::atof(toString(data).c_str());
	}
}