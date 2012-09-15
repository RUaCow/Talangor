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
	ignoreCommentLines(mapFile);
	//Map name.
	fscanf(mapFile , "%s\n" , &mapName);
	ignoreCommentLines(mapFile);
	//Creator's comment.
	fscanf(mapFile , "%s\n" , &comment);
	ignoreCommentLines(mapFile);
	//Map type.
	fscanf(mapFile , "%d\n" , (int*)&mapType);
	ignoreCommentLines(mapFile);
	//Players limit or number.
	fscanf(mapFile , "%d\n" , &np);
	ignoreCommentLines(mapFile);
	//Default COF.
	fscanf(mapFile , "%f\n" , &COF);
	ignoreCommentLines(mapFile);
	//Number of shapes in the map.
	int sn;
	fscanf(mapFile , "%d\n" , &sn);
	ignoreCommentLines(mapFile);
	//Reading shapes.
	readShapesInfo(sn , mapFile);
	ignoreCommentLines(mapFile);
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
	fprintf(mapFile , "%s\n" , mapName);
	//Creator's comment
	fprintf(mapFile , "%s\n" , comment);
	//Map type.
	fprintf(mapFile , "%d\n" , (int)mapType);
	//Players limit or number.
	fprintf(mapFile , "%d\n" , np);
	//Default COF.
	fprintf(mapFile , "%f\n" , COF);
	//Number of shapes in the map.
	fprintf(mapFile , "%d\n" , (int)shapes.size());
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
			fprintf(file , "%f %f " , tmp.points.at(j).x() , tmp.points.at(j).y());
		fprintf(file , "\n");
		writeShapesInfo(file , &tmp.shapes);
	}
}

void Map::readShapesInfo(int n , FILE* file , vector<Shape>* shs)
{
	//Checking if this is first time calling this function.
	!shs ? shs = &this->shapes : shs;
	for(int i = 0 ; i < n ; i++)
	{
		int sn/*number of shapes inside this shape*/ , num_points;
		float sCOF;
		fscanf(file , "%d %f %d " , &sn , &sCOF , &num_points);
		vector<Vector2Df> points;
		//Adding points of the shapes.
		for(int j = 0 ; j < num_points ; j++)
		{
			float X , Y;
			fscanf(file , "%f %f " , &X , &Y);
			points.push_back(Vector2Df(X , Y));
		}
		fscanf(file , "\n");
		//Creating the shape.
		Shape sh(i , points , sCOF);
		//Adding the shapes.
		shs->push_back(sh);
		readShapesInfo(sn , file , &shs->at(i).shapes);
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

void Map::ignoreCommentLines(FILE* file)
{
	char buf[256];
	bool ignoring = true;
	while(ignoring)
		fgetc(file) == '@' ? fgets(buf , 256 , file) , ignoring = true : fseek(file , -1 , SEEK_CUR) , ignoring = false;
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