#include "Map.h"
#include "Shape.h"
using namespace std;


Map::Map(char* filePath)
{
	loadMap(filePath);
}

bool Map::loadMap(char* filePath)
{
	//returns false if the version of the map is newer than the game.
	return true;
}

MapType Map::getMapType(void)
{
	return mapType;
}

char* Map::getMapName(void)
{
	return mapName;
}

float Map::getMapVersion(void)
{
	return V;
}