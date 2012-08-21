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

//This function will calculate the speed of ball for the 'time + dt'.
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

//This function will be called whenever a collision happens.
void WorldModel::calcAfterCollisionVelocity(int n1 , int n2)
{
	//Balls' masses
	float b1Mass = balls.at(n1).mass , b2Mass = balls.at(n2).mass;

	//Balls' positions
	float b1X = balls.at(n1).pos.getX() , b1Y = balls.at(n1).pos.getY();
	float b2X = balls.at(n2).pos.getX() , b2Y = balls.at(n2).pos.getY();

	//Before collision velocity vector of balls.
	Vector2Df b1VelocityVector = balls.at(n1).velocity;
	Vector2Df b2VelocityVector = balls.at(n2).velocity;

	//Normal vector to the collision surface.
	Vector2Df normalVector(b1X- b2X , b1Y - b2Y);
	//Unit vector of normal vector.
	Vector2Df unitNormalVector = normalVector.getNormalizedVector();

	//Unit vector of tangent vector to the collision surface.
	Vector2Df unitTangentVector = unitNormalVector.getPrependicularVector();

	//Balls' scalar velocities in unit normal vector.
	float b1Velocity_normalVector = b1VelocityVector * unitNormalVector;
	float b2Velocity_normalVector = b2VelocityVector * unitNormalVector;
	
	//Balls' scalar velocities in unit tangent vector.
	float b1Velocity_tangentVector = b1VelocityVector * unitTangentVector;
	float b2Velocity_tangentVector = b2VelocityVector * unitTangentVector;

	//Balls' after collison velocities in unit normal vector.
	float b1NewVelocity_normalVector = (b1Velocity_normalVector * (b1Mass - b2Mass) + 2 * b2Mass * b2Velocity_normalVector) / (b1Mass + b2Mass);
	float b2NewVelocity_normalVector = (b2Velocity_normalVector * (b2Mass - b1Mass) + 2 * b1Mass * b1Velocity_normalVector) / (b1Mass + b2Mass);
	
	/*Balls' after collison velocities in unit tangent vector will
	remain the same because there is no force acting in that direction.*/

	//Velocity vectors along the normal vector.
	Vector2Df b1NewVelocityVector_normalVector = b1NewVelocity_normalVector * unitNormalVector;
	Vector2Df b2NewVelocityVector_normalVector = b2NewVelocity_normalVector * unitNormalVector;

	//Velocity vectors along the tangent vector.
	Vector2Df b1VelocityVector_tangentVector = b1Velocity_tangentVector * unitTangentVector;
	Vector2Df b2VelocityVector_tangentVector = b2Velocity_tangentVector * unitTangentVector;

	//New balls' velocities vectors.
	Vector2Df b1NewVelocityVector = b1NewVelocityVector_normalVector + b1VelocityVector_tangentVector;
	Vector2Df b2NewVelocityVector = b2NewVelocityVector_normalVector + b2VelocityVector_tangentVector;

	//Setting balls' velocities!!!!!POOOOOOOOFFF...
	balls.at(n1).velocity = b1NewVelocityVector , balls.at(n2).velocity = b2NewVelocityVector;

	//Wooooooooooooow!!It's finished!!!!YEEEEEEEEEEEEEEEEEEESssssSSSsssSSSsssSSS:D
}

//This function will give the speed of a specified ball in specific time.
Vector2Df WorldModel::speedAt(int n , float t)
{
	if(balls.at(n).velocity.getLength() == 0)
		return Vector2Df(0.0f , 0.0f);

	float deltaT = t - time;
	float frictionAcceleration = G * COF;
	float xFactor = balls.at(n).velocity.getNormalizedVector().getX();
	float yFactor = balls.at(n).velocity.getNormalizedVector().getY();

	Vector2Df frictionAccelerationVector(frictionAcceleration * xFactor , frictionAcceleration * yFactor);

	return (balls.at(n).velocity - frictionAccelerationVector * deltaT);
}


void WorldModel::update(){
	time += dt;
	speedCalc();
	for(int i = 0 ; i < n ; i++){
		balls[i].pos.X() += balls[i].velocity.X() * dt;
		balls[i].pos.Y() += balls[i].velocity.Y() * dt;
	}
}
