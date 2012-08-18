#include "WorldModel.h"
using namespace std;
WorldModel::WorldModel(int mN , float mMinDis/* , Map mLevelMap*/){
	n = mN;
	Random r;
	for(int i = 0 ; i < n ; i++){
		bool isGood = false;
		Vector2Df tmp;
		while(isGood == false){
			tmp = Vector2Df(r.Gauss() , r.Gauss());
			isGood = true;
			for(int j = 0 ; j < i ; j++){
				float diss = (tmp - balls[j].pos).getLength();
				if(diss < mMinDis)
					isGood = false;
			}
		}
		Ball newBall(i , 5 , 10 , tmp);
		balls.push_back(newBall);
	}
}

void WorldModel::speedCalc(){
}

void WorldModel::update(){
}
