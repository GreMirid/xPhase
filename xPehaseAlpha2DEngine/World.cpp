#include "World.h"

namespace xphase
{
	//Loader for Texture

	int World::create(Window &window)
	{
		//TASK:
		/// Get data from conteiner and write to RAM
		/// Is data info about scenes and this objects

		ConteinerReader reader(window.getPathtoGame(), ConteinerReader::SCENE);

		Scene tempScene;

		std::wstring temp = L"";
		std::vector<std::wstring> tempRawData, tempRawMassive;

		vec2f scaleScene, cenPos = { 0, 0 };

		float scaleCubicObject = (window.screenMatrix.getMatrixScale().x + window.screenMatrix.getMatrixScale().y) / 2;

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
							toFlFrmWS(tempRawMassive[1]) * window.screenMatrix.getMatrixScale().x,
							toFlFrmWS(tempRawMassive[2]) * window.screenMatrix.getMatrixScale().y
						};

						cenPos =
						{
							window.screenMatrix.getRealScreenSize().x / 2,
							window.screenMatrix.getRealScreenSize().y / 2
						};

						std::string path_to_texture = window.getPathtoGame() + TO_RES + toString(tempRawMassive[0]);

						tempScene.create(cenPos, scaleScene, path_to_texture);
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

						tempScene.addDoor(pos, toIFrmWS(tempRawMassive[2]), toIFrmWS(tempRawMassive[3]), scaleCubicObject);
					}

					//ADD COLLISION FUNCTION
					if (tempRawMassive[0].substr(0, 9) == L"collision")
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

						std::string path = toString(tempRawMassive[4]);

						tempScene.addLayer(pos, scale, path);
					}
				}
				scenes.emplace_back(tempScene);
			}
		}

		//TASK:
		/// Load file from first scene of path in and draw it
		reSetScene(0);

		return EXIT_OK;
	}

	void World::update(Window &window, double delta, Player &player)
	{
		scenes[player.getLocation()].update(window, delta, player);
		doorUpdate(player);
	}

	void World::doorUpdate(Player &player)
	{
		for (size_t unit = 0; unit < scenes[player.getLocation()].doors.size(); unit++)
		{
			vec2f someval = scenes[player.getLocation()].doors[unit].update(player);

			if (someval.x != NoZero) //Some NULL to Use In This
			{
				// Set Scene to
				player.setLocation(someval.x);

				//Set Door to
				player.setActorCenPos
				(
					{
						scenes[someval.x].doors[someval.y].getPos().x + scenes[someval.x].doors[someval.y].getSize().x / 4,
						scenes[someval.x].doors[someval.y].getPos().y +
						(scenes[someval.x].doors[someval.y].getSize().x - (player.getSize().y * player.getScale().y))
					}
				);

				reSetScene(someval.x);

				break;
			}
		}
	}

	void World::draw(Window &window, Player &player)
	{
		window.drawArea.draw(sceneSprite);

		scenes[player.getLocation()].draw(window);
	}

	void World::reSetScene(int player_location)
	{
		sceneSprite.setTexture
		(
			*m_Textures.loadTexture(scenes[player_location].getPathToTexture())
		);

		sceneSprite.setScale
		(
			scenes[player_location].getScale().x,
			scenes[player_location].getScale().y
		);

		sceneSprite.setPosition
		(
			scenes[player_location].getPos().x,
			scenes[player_location].getPos().y
		);
	}
}