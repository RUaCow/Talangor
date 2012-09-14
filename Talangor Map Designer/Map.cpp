#include "Map.h"
#include "Shape.h"
#include <stdio.h>


Map::Map(char* filePath) : path(filePath) , changesSaved(true)
{
	loadMap();
}

Map::Map(float version , MapType type , float defCOF , char* filePath , char* mapName , int np) : V(version) , mapType(type) , COF(defCOF) , mapName(mapName) , np(np) , path(filePath) , changesSaved(false)
{
	//:D nothing here ...
}
bool Map::loadMap(void)
{
	FILE* mapFile = fopen(path , "r");
	//Loading ...
	fclose(mapFile);
	return true;
}

bool Map::saveMap(void)
{
	//Check if comment is initialized.
	!comment ? strcpy(comment , "") : comment;
	//Check the path.
	char* fileName = path == DEFAULT_PATH ? mapName : path;
	FILE* mapFile = fopen(fileName , "w");
	//Saving ...
	putComment(mapFile , "Map created by Talangor Map Designer , cretaed by RUaCow team.\n");
	//Map name.
	printf("%s\n" , mapName);
	//Creator's comment
	printf("%s\n" , comment);
	//Map type.
	printf("%d\n" , (int)mapType);
	//Players limit or number.
	printf("%d\n" , np);
	//Default COF.
	printf("%f\n" , COF);
	//Number of shapes in the map.
	printf("%d\n" , (int)shapes.size());
	//Shapes.
	writeShapesInfo(mapFile , &shapes);
	//finished!
	closeTMF(mapFile);
	fclose(mapFile);
	//Setting save status.
	changesSaved = true;
	return true;
}

void Map::writeShapesInfo(FILE* file , vector<Shape>* shs)
{
	!shs ? shs = &this->shapes : shs;
	for(int i = 0 ; i < (int)shs->size() ; i++)
	{
		Shape tmp = shs->at(i);
		fprintf(file , "%d %f %d " , (int)tmp.shapes.size() , tmp.COF , (int)tmp.points.size());
		for(int j = 0 ; j < (int)tmp.points.size() ; j++)
			fprintf(file , "%f %f " , tmp.points.at(j).x , tmp.points.at(j).y);
		fprintf(file , "\n");
		writeShapesInfo(file , &tmp.shapes);
	}
}

void Map::closeTMF(FILE* file)
{
	fprintf(file , "eotmf");
	fclose(file);
}

void Map::putComment(FILE* file , char* cm)
{
	fprintf(file , "%s%s\n" , "@" , cm);
}

void Map::addShape(Shape new_shape)
{
	shapes.push_back(new_shape);
	//Setting save status.
	changesSaved = false;
}

void Map::changeName(char* newName)
{
	strcpy(mapName , newName);
	//Setting save status.
	changesSaved = false;
}

void Map::changeVersion(float version)
{
	V = version;
	//Setting save status.
	changesSaved = false;
}

void Map::setComment(char* comment)
{
	strcpy(this->comment , comment);
	//Setting save status.
	changesSaved = false;
}

void Map::changeCOF(float defCOF)
{
	COF = defCOF;
	//Setting save status.
	changesSaved = false;
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