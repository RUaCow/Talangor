#ifndef _PLAYER_H
#define _PLAYER_H

struct Player{
	unsigned int id;
	int lastBallTouched;
	int points;
public:
	Player(){}
	Player(unsigned int mId , int mLastBallTouched , int mPoints){
		id = mId;
		lastBallTouched = mLastBallTouched;
		points = mPoints;
	}
};

#endif //_PLAYER_H
