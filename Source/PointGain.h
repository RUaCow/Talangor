#ifndef _POINTGAIN_H
#define _POINTGAIN_H

#include "Player.h"
#include "WorldModel.h"
#include "Ball.h"
#include "GuiEvent.h"
#include "GameRules.h"
#include <vector>

class PointGain: public GameRules{
	bool didMakeCollision;
	bool diffPositive(float a, float b);
public:
	PointGain(int n = 1);
	bool turnPlay(const WorldModel& wm , const GuiEvent& ge);
	bool addPoint(const WorldModel& wm);
	bool winning();
};

#endif //_POINTGAIN_H
