#ifndef MaP_h
#define MaP_h
#include <vector>


class Shape;


//Erfan this is temporary.We'll talk about names FACE_TO_FACE!!!;)
enum MapType
{
	//One player mode with a goal to made.
	OnePlayer = 0 , //(destination)????
	//Two player mode
	TwoPlayer = 1
};


class Map
{
	friend class WorldModel;
	//The version that the map was creted for.
	float V;
	//The name of the map.
	char* mapName;
	//The type of the map.
	MapType mapType;
	//Default COF.It will be -1 if the default areas are holes!
	float COF;
	//Contents of the map : shapes.
	std::vector<Shape> shapes;


	//This will load form file.
	bool loadMap(char* filePath);

public:
	Map(char* filePath);

	//Get map type.
	MapType getMapType(void);

	//Get map name.
	char* getMapName(void);

	//Get map version.
	float getMapVersion(void);
};


#endif