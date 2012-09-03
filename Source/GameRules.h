#ifndef _GAMERULES_H
#define _GAMERULES_H

#include "Player.h"
#include "WorldModel.h"
#include "Ball.h"
#include "GuiEvent.h"
#include <vector>

class GameRules{
protected:
	bool canPlay;
	int whichTurn;
	std::vector<Player> players;
public:
	GameRules(int n = 1);
	virtual int getPrevTurn() const;
	virtual bool turnPlay(const WorldModel& wm , const GuiEvent& ge) = 0;
	virtual bool addPoint(const WorldModel& wm) = 0;
	virtual bool winning() = 0;
};

#endif //_GAMERULLES_H
