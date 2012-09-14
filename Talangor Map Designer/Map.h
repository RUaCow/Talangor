/*Map for TMD*/
#ifndef MaP_h
#define MaP_h
#include <vector>
#define DEFAULT_PATH ""


class Shape;


enum MapType
{
	//One player mode with a goal to made.
	goal = 0 ,
	//Two player mode
	unlimited = 1 , //Means they play until someone can't do a legal move.It's a temporary name.
	//CTF!!!
	CTF = 2 //Two teams.Like the goal mode but here they have to capture flags (goal 1) and retrun to their base (goal 2).
};


class Map
{
	friend class Designer;
	//The version that the map was creted for.
	float V;
	//The name of the map.
	char* mapName;
	//Comment of the creator.
	char* comment;
	//The address of the file.
	char* path;
	//The type of the map.
	MapType mapType;
	//Number of players or the limit of the players in some types like CTF.No limit = -1
	int np;
	//Default COF.It will be -1 if the default areas are holes!
	float COF;
	//Contents of the map : shapes.
	std::vector<Shape> shapes;
	//This indicates whether the changes have been saved to file or not.
	bool changesSaved;

	/*IO*/
	//This will load form file.
	bool loadMap(void);
	//This will save to file.
	bool saveMap(void);
	//This will put a comment line in the map file.
	void putComment(FILE* file , char* cm);
	//This will write shapes information into file.
	void writeShapesInfo(FILE* file , std::vector<Shape>* shs = NULL);
	//This will close the map file.
	void closeTMF(FILE* file);

	/*FUNCTIONS*/
	//This will add a shape into the map.
	void addShape(Shape new_shape);
	//This will change the map name.
	void changeName(char* newName);
	//This will change the version.
	void changeVersion(float version);
	//This will set the map comment.
	void setComment(char* comment);
	//This will change the default COF.
	void changeCOF(float defCOF);

public:
	//constructors:
	//This will load a map to change it.
	Map(char* filePath);
	//For a completely new map.
	Map(float version , MapType type , float defCOF = -1 , char* filePath = DEFAULT_PATH , char* mapName = "untitled" , int np = -1);

	//Get map type.
	const MapType getMapType(void) const;

	//Get map name.
	const char* getMapName(void) const;

	//Get map version.
	const float getMapVersion(void) const;
};

#endif