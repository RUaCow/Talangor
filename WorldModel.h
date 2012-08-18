/**************************************************************
	WorldModel.h
	Author : Erfan Loghmani	
	Purpose : Contains WorldModel datas and update it after each cycle.
	Date : 8 / 17 / 2012
**************************************************************/
#ifndef _WORLDMODEL_H
#define _WORLDMODEL_H
#include "Ball.h"
#include "Random.h"
//#include "Map.h"
#include <vector>
#include <iostream>

class WorldModel{
	int n;
	std::vector<Ball> balls;
	float minDis;
	//Map levelMap;
public:
	//WorldModel();
	WorldModel(int = 3 , float = 0.5/* , Map mLevelMap = Map()*/);
	~WorldModel(){}
	void speedCalc();
	void update();
};

#endif //_WORLDMODEL_H
