#include "World.h"

namespace xphase
{
	int World::create(Window &window)
	{
		//TASK:
		/// Get data from conteiner and write to RAM
		/// Is data info about scenes and this objects

		ConteinerReader reader(window.getPathtoGame(), ConteinerReader::SCENE);

		Scene tempScene;

		std::wstring temp = L"";
		std::vector<std::wstring> tempRawData, tempRawMassive;

		vec2f sizeScene, scaleScene, cenPos = { 0, 0 };

		for (size_t f = 0; f < reader.getNumberFilesInConteiner(); f++)
		{
			tempScene.clear();
			temp = L"";

			temp = reader.getLoadedFile(f);

			size_t filesize = temp.size();

			if (temp[0] == '@')
			{
				size_t pos = 1;
				for (; pos < filesize; pos++)
					if (temp[pos] == ':') break; //add namescene here

				tempRawData = reader.separateData(temp.substr(pos, filesize), ':');
				for (size_t unit = 1; unit < tempRawData.size(); unit++)
				{
					tempRawMassive = reader.separateData(tempRawData[unit], '\'');

					//CREATE FUNCTION
					if (tempRawMassive[0].substr(0, 4) == L"main")
					{
						/// erase name
						tempRawMassive.erase(tempRawMassive.begin());

						scaleScene =
						{
							toFlFrmWS(tempRawMassive[3]) * window.screenMatrix.getMatrixScale().x,
							toFlFrmWS(tempRawMassive[4]) * window.screenMatrix.getMatrixScale().y
						};

						sizeScene =
						{
							toFlFrmWS(tempRawMassive[1]),
							toFlFrmWS(tempRawMassive[2])
						};

						cenPos =
						{
							window.screenMatrix.getRealScreenSize().x / 2,
							window.screenMatrix.getRealScreenSize().y / 2
						};

						std::string path_to_texture = window.getPathtoGame() + TO_RES + toString(tempRawMassive[0]);

						tempScene.create(cenPos, scaleScene, sizeScene, path_to_texture);
					}

					//ADD DOOR FUNCTION
					if (tempRawMassive[0].substr(0, 4) == L"door")
					{
						/// erase name
						tempRawMassive.erase(tempRawMassive.begin());

						vec2f pos = window.screenMatrix.getRealPoint
						(
							{
								toFlFrmWS(tempRawMassive[0]),
								toFlFrmWS(tempRawMassive[1])
							}
						);

						tempScene.addDoor(pos, toIFrmWS(tempRawMassive[2]), toIFrmWS(tempRawMassive[3]));
					}

					//ADD COLLISION FUNCTION
					if (tempRawMassive[0].substr(0, 10) == L"collission")
					{
						/// erase name
						tempRawMassive.erase(tempRawMassive.begin());

						vec2f pos = window.screenMatrix.getRealPoint
						(
							{
								toFlFrmWS(tempRawMassive[0]),
								toFlFrmWS(tempRawMassive[1])
							}
						);

						vec2f size =
						{
							toFlFrmWS(tempRawMassive[2]) * window.screenMatrix.getMatrixScale().x,
							toFlFrmWS(tempRawMassive[3]) * window.screenMatrix.getMatrixScale().y
						};

						tempScene.addCollision(pos, size);
					}

					//ADD TRIGGER FUNCTION
					if (tempRawMassive[0].substr(0, 7) == L"trigger")
					{
						/// erase name
						tempRawMassive.erase(tempRawMassive.begin());

						vec2f pos = window.screenMatrix.getRealPoint
						(
							{
								toFlFrmWS(tempRawMassive[0]),
								toFlFrmWS(tempRawMassive[1])
							}
						);

						vec2f size =
						{
							toFlFrmWS(tempRawMassive[2]) * window.screenMatrix.getMatrixScale().x,
							toFlFrmWS(tempRawMassive[3]) * window.screenMatrix.getMatrixScale().y
						};

						tempScene.addTrigger(pos, size, toIFrmWS(tempRawMassive[4]));
					}

					//ADD LAYER FUNCTION
					if (tempRawMassive[0].substr(0, 5) == L"layer")
					{
						/// erase name
						tempRawMassive.erase(tempRawMassive.begin());

						vec2f pos = window.screenMatrix.getRealPoint
						(
							{
								toFlFrmWS(tempRawMassive[0]),
								toFlFrmWS(tempRawMassive[1])
							}
						);

						vec2f scale = 
						{
							toFlFrmWS(tempRawMassive[2]) * window.screenMatrix.getMatrixScale().x,
							toFlFrmWS(tempRawMassive[3]) * window.screenMatrix.getMatrixScale().y
						};

						tempScene.addLayer(pos, scale, toString(tempRawMassive[4]));
					}
				}
				scenes.emplace_back(tempScene);
			}
		}

		//TASK:
		/// Load file from first scene of path in and draw it

		return EXIT_OK;
	}

	void World::update(Window &window, double delta, Player &player)
	{
		scenes[player.getLocation()].update(window, delta, player);
	}

	void World::draw(Window &window, Player &player)
	{
		scenes[player.getLocation()].draw(window);
	}

	void World::reSetScene(int player_location)
	{
		//empty
	}
}