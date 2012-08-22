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
#include <cmath>
class WorldModel{
	int n;
	const float maxCord;
	std::vector<Ball> balls;
	float minDis;
	//min Disstance of each ball from the lines
	float minDis2Lines;
	float time;
	float dt;
	//Coefficient of Friction (COF)
	float COF;
	//Gravity Acceleration
	const float G;
	void collisionDitection();
	//Map levelMap;
public:
	//WorldModel();
	WorldModel(int = 3 , float = 0.5/* , Map mLevelMap = Map()*/);
	~WorldModel(){}
	void speedCalc();
	void calcAfterCollisionVelocity(int n1 , int n2);
	Vector2Df speedAt(int n , float t);
	void update();
	friend class GUI;
};

#endif //_WORLDMODEL_H
