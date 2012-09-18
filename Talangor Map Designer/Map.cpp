#include "Map.h"
#include "Shape.h"
#include <stdio.h>


Map::Map(char* filePath) : changesSaved(true)
{
	path = new char[1000];
	mapName = new char[100];
	comment = new char[2000];
	strcpy(path , filePath);
	loadMap();
}

Map::Map(float version , MapType type , float defCOF , char* filePath , char* name , int np) : V(version) , mapType(type) , COF(defCOF) , np(np) , changesSaved(false)
{
	path = new char[1000];
	mapName = new char[100];
	comment = new char[2000];
	strcpy(mapName , name);
	strcpy(path , filePath);
	comment = NULL;
}

bool Map::loadMap(void)
{
	FILE* mapFile = fopen(path , "rb");
	int a = ftell(mapFile);
	//Loading ...
	ignoreCommentLines(mapFile);
	a = ftell(mapFile);
	//Version.
	fscanf(mapFile , "%f\n" , &V);
	ignoreCommentLines(mapFile);
	a = ftell(mapFile);
	//Map name.
	fgets(mapName , 100 , mapFile);
	ignoreCommentLines(mapFile);
	a = ftell(mapFile);
	//Creator's comment.
	fgets(comment , 1000 , mapFile);
	ignoreCommentLines(mapFile);
	a = ftell(mapFile);
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
	!comment ? (comment = new char , strcpy(comment , "No Comment")) : (comment);
	//Check the path.
	char* fileName = (strcmp(path , DEFAULT_PATH) == 0 ? mapName : path);
	FILE* mapFile = fopen(fileName , "w");
	//Saving ...
	putComment(mapFile , "Map created by Talangor Map Designer , cretaed by RUaCow team.\n");
	//Version.
	fprintf(mapFile , "%f\n" , V);
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
		//Reading shapes inside this shape.
		ignoreCommentLines(file);
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
	fprintf(file , "%s%s" , "@" , cm);
}

void Map::ignoreCommentLines(FILE* file)
{
	char buf[256];
	bool ignoring = true;
	while(ignoring)
		fgetc(file) == '@' ? (fgets(buf , 256 , file) , printf("Comment ignored : %s\n" , buf)) : (ignoring = false , fseek(file , ftell(file) - 1 , SEEK_SET));
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