#ifndef _GAMERULES_H
#define _GAMERULES_H

#include "Player.h"
#include "WorldModel.h"
#include "Ball.h"
#include "GuiEvent.h"
#include <vector>

class GameRules{
	bool canPlay;
	bool didMakeCollision;
	int whichTurn;
	std::vector<Player> players;
	bool diffPositive(float a, float b);
public:
	GameRules();
	GameRules(int n);
	int getPrevTurn() const;
	bool turnPlay(const WorldModel& wm , const GuiEvent& ge);
	bool addPoint(const WorldModel& wm);
	bool winning();
};

#endif //_GAMERULLES_H
