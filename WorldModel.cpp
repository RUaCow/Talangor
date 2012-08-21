#include "WorldModel.h"
using namespace std;
WorldModel::WorldModel(int mN , float mMinDis/* , Map mLevelMap*/):G(9.8){
	time = 0;
	dt = 0.02;
	n = mN;
	minDis = mMinDis;
	COF = 0.2f;
	Random r;
	for(int i = 0 ; i < n ; i++){
		bool isGood = false;
		Vector2Df tmp;
		while(isGood == false){
			tmp = Vector2Df(r.Gauss() , r.Gauss());
			isGood = true;
			for(int j = 0 ; j < i ; j++){
				float diss = (tmp - balls[j].pos).getLength();
				if(diss < minDis)
					isGood = false;
			}
		}
		Ball newBall(i , 5 , 10 , tmp);
		balls.push_back(newBall);
	}
}

void WorldModel::speedCalc()
{
	for(int i = 0 ; i < n ; i++)
	{
		float frictionAcceleration = G * COF;
		float xFactor = balls.at(n).velocity.getNormalizedVector().getX();
		float yFactor = balls.at(n).velocity.getNormalizedVector().getY();

		Vector2Df frictionAccelerationVector(frictionAcceleration * xFactor , frictionAcceleration * yFactor);

		balls.at(n).velocity -= frictionAccelerationVector * dt;
	}
}

void WorldModel::update(){
	time += dt;
	speedCalc();
	for(int i = 0 ; i < n ; i++){
		balls[i].pos.X() += balls[i].velocity.X() * dt;
		balls[i].pos.Y() += balls[i].velocity.Y() * dt;
	}
}
