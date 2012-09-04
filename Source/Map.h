#ifndef MaP_h
#define MaP_h
#include <vector>


class Shape;


//Erfan this is temporary.We'll talk about names FACE_TO_FACE!!!;)
enum MapType
{
	//One player mode with a goal to made.
	goal = 0 , //(destination)????
	//Two player mode
	unlimited = 1 , //Means they play until someone can't do a legal move.It's a temporary name.
	//CTF!!! (Use your imagination ... I don't know what I'm typing!)
	CTF = 2 //Two teams.Like the goal mode but here they have to capture flags (goal 1) and retrun to their base (goal 2).
};


class Map
{
	friend class WorldModel;
	//The version that the map was creted for.
	float V;
	//The name of the map.
	char* mapName;
	//Comment of the creator.
	char* comment;
	//The type of the map.
	MapType mapType;
	//Number of players or the limit of the players in some types like CTF.
	int np;
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