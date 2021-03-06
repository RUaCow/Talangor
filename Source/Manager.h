/**************************************************************
	Manager.h
	Author : Erfan Loghmani	
	Purpose : Manages everything!
	Date : 8 / 22 / 2012
**************************************************************/
#ifndef _MANAGER_H
#define _MANAGER_H

#include "WorldModel.h"
#include "Gui.h"
#include "Vector2D.h"
#include "GameRules.h"
#include "PointGain.h"
class Manager{
	WorldModel wm;
	GUI ui;
	GameRules *gr;
public:
	Manager();
	~Manager();
	void run();
};

#endif //_MANAGER_H
