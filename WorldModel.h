/**************************************************************
	WorldModel.h
	Author : Erfan Loghmani	
	Purpose : Contains WorldModel datas and update it after each cycle.
	Date : 8 / 17 / 2012
**************************************************************/
#ifndef _WORLDMODEL_H
#define _WORLDMODEL_H
#include "Ball.h"
#include "Map.h"
#include <vector>

class WorldModel{
	vector<Ball> balls;
	Map levelMap;
public:
	//WorldModel();
	WorldModel(Map mLevelMap = Map());
	~WorldModel();
	void speedCalc();
	void update();	
};

#endif //_WORLDMODEL
_
