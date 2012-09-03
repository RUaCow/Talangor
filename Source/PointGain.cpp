#include "PointGain.h"

PointGain::PointGain(int n){
	didMakeCollision = false;
}

bool PointGain::diffPositive(float a, float b){
	return ((a >= 0 && b < 0) || (b >= 0 && a < 0));
}

bool PointGain::turnPlay(const WorldModel& wm , const GuiEvent& ge){
	if(canPlay){
		int ball = wm.insideWhichBall(ge.clickStart);
		if(ball != -1 && ball != players[getPrevTurn()].lastBallTouched){
			players[whichTurn].lastBallTouched = ball;
			canPlay = false;
		}
		return true;
	}
	return false;
}

bool PointGain::addPoint(const WorldModel& wm){
	if(!canPlay){
		if(wm.hasCollision()){
			didMakeCollision = true;
		}
		const Ball tmp = wm.getBall(players[whichTurn].lastBallTouched);
		for(int i = 0 ; i < wm.getN() ; i++)
			if(i != players[whichTurn].lastBallTouched)
				for(int j = 0 ; j < wm.getN() ; j++)
					if(j > i && j != players[whichTurn].lastBallTouched){
						float dNow = determinant((wm.getBall(i).getPos() - tmp.getPos()) ,(wm.getBall(j).getPos() - tmp.getPos()));
						float dBefore = determinant((wm.getBall(i).getPos() - tmp.getPrePos()) , (wm.getBall(j).getPos() - tmp.getPrePos()));
						if((diffPositive(dNow , dBefore) && diffPositive(wm.getBall(i).getPos().x() - tmp.getPos().x() , wm.getBall(j).getPos().x() - tmp.getPos().x()) && diffPositive(wm.getBall(i).getPos().y() - tmp.getPos().y() , wm.getBall(j).getPos().y() - tmp.getPos().y())) && !didMakeCollision){
							canPlay = true;
							players[whichTurn].points ++;
							whichTurn = (whichTurn + 1) % players.size();
							return true;
						}
						if((diffPositive(dNow , dBefore) && !didMakeCollision)){
							canPlay = true;
							whichTurn = (whichTurn + 1) % players.size();
							return false;
						}
					}
		if(wm.isStoped(players[whichTurn].lastBallTouched)){
			canPlay = true;
			whichTurn = (whichTurn + 1) % players.size();
			didMakeCollision = false;
			return false;
		}
	}
	return false;
}

bool PointGain::winning(){
	if(players[getPrevTurn()].points >= 5){
		return true;
	}
	return false;
}
