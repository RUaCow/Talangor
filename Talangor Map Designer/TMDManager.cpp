#include "TMDManager.h"
#include "Map.h"
#include "SDL_GUI.h"


TMDManager::TMDManager(void)
{
	printf("Welcome to Talangor Map Designer V %s.Please select:\n1 :\tLoad a map\n2 :\tCreate a new map\n" , "0.1");
	int mode;
	scanf("%d" , &mode);
	if(mode == 1)
	{
		printf("Please enter the file path:\n");
		char* filePath = new char[1000];
		scanf("%s" , filePath);
		map = new Map(filePath);
	}
	else if(mode == 2)
	{
		printf("Please select your map type:\n0 :\tGoal\n1 :\tUnlimited\n2 :\tCTF\n");
		int mapType;
		scanf("%d" , &mapType);
		map = new Map(0.1f , (MapType)mapType);
		map->saveMap();
	}
}

TMDManager::~TMDManager(void)
{
}