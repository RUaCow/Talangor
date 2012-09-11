#include "Map.h"
#include "Shape.h"
#include <stdio.h>


Map::Map(char* filePath) : path(filePath)
{
	loadMap();
}

Map::Map(float version , MapType type , float defCOF , char* mapName , int np , char* filePath) : V(version) , mapType(type) , COF(defCOF) , mapName(mapName) , np(np) , path(filePath)
{
	//:D nothing here ...
}
bool Map::loadMap(void)
{
	FILE* mapFile = fopen(path , "r");
	//Loading ...
	fclose(mapFile);
}

bool Map::saveMap(void)
{
	FILE* mapFile = fopen(path , "w");
	//Saving ...
	fclose(mapFile);
}

void Map::addShape(Shape new_shape)
{
	shapes.push_back(new_shape);
}

const MapType Map::getMapType(void) const
{
	return mapType;
}

const char* Map::getMapName(void) const
{
	return mapName;
}

const float Map::getMapVersion(void) const
{
	return V;
}