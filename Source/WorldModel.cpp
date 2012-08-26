#include "WorldModel.h"
using namespace std;
WorldModel::WorldModel(int mN , float mMinDis/* , Map mLevelMap*/): maxCord(1.0) , G(9.8) , CUE_MASS(1.0f){
	time = 0;
	dt = 0.02;
	n = mN;
	minDis2Lines = 0.3;
	minDis = mMinDis;
	COF = 0.1f;
	Random r;
	for(int i = 0 ; i < n ; i++){
		bool isGood = false;
		Vector2Df tmp;
		while(isGood == false){
			tmp = Vector2Df(r.Gauss(0 , 2) , r.Gauss(0 , 2));
			isGood = true;
			if(tmp.x() > maxCord || tmp.y() > maxCord || tmp.x() < -maxCord || tmp.y() < -maxCord)
				isGood = false;
			if(i >= 2)
				for(int j = 0 ; j < i ; j++)
					for(int k = 0 ; k < i ; k++){
						float rate = ((balls[k].pos - balls[j].pos) * (balls[k].pos - tmp)) / 
							((balls[k].pos - balls[j].pos).getLength() * (balls[k].pos - tmp).getLength());
						float thetaByRate = acos(rate);
						if(j > k && sin(thetaByRate) * (balls[k].pos - tmp).getLength() < minDis2Lines)
							isGood = false;
					}
			for(int j = 0 ; j < i ; j++){
				float diss = (tmp - balls[j].pos).getLength();
				if(diss < minDis)
					isGood = false;
			}
		}
		Ball newBall(i , 0.01 , 50 , tmp);
		balls.push_back(newBall);
	}
}

bool WorldModel::isStoped(int i){
	float epsilon = 0.0001;
	return (((balls[i].velocity.x() < epsilon && balls[i].velocity.x() >= 0) || (balls[i].velocity.x() > -epsilon && balls[i].velocity.x() < 0)) && ((balls[i].velocity.y()  < epsilon && balls[i].velocity.y() >= 0) || (balls[i].velocity.y() > -epsilon && balls[i].velocity.y() < 0)));
}
//This function will calculate the speed of ball for the 'time + dt'.
void WorldModel::speedCalc()
{
	for(int i = 0 ; i < n ; i++)
	{
		if(!isStoped(i)){
			float frictionAcceleration = G * COF;
			float xFactor = balls.at(i).velocity.getNormalizedVector().getX();
			float yFactor = balls.at(i).velocity.getNormalizedVector().getY();
			Vector2Df frictionAccelerationVector(frictionAcceleration * xFactor , frictionAcceleration * yFactor);
			if((frictionAccelerationVector.getX() * dt > balls[i].velocity.getX() && xFactor > 0) || ((frictionAccelerationVector.getX() * dt < balls[i].velocity.getX()) && xFactor < 0))
				balls[i].velocity.x() = 0;
			else
				balls[i].velocity.x() -= frictionAccelerationVector.getX() * dt;
			if((frictionAccelerationVector.getY() * dt > balls[i].velocity.getY() && yFactor > 0) || ((frictionAccelerationVector.getY() * dt < balls[i].velocity.getY()) && yFactor < 0))
				balls[i].velocity.y() = 0;
			else
				balls[i].velocity.y() -= frictionAccelerationVector.getY() * dt;
		}
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

//This will detect any collision between the balls and process them.
void WorldModel::collisionDetection(){
	for(int i = 0 ; i < (int)balls.size() ; i++)
		for(int j = 0 ; j < (int)balls.size() ; j++)
			if(i > j){
				Vector2Df iNextPos = balls[i].pos + speedAt(i , time + dt) * dt;
				Vector2Df jNextPos = balls[j].pos + speedAt(j , time + dt) * dt;
				if((balls[i].pos - balls[j].pos).getLength() < balls[i].radius + balls[j].radius && 
						(iNextPos - jNextPos).getLength() < (balls[i].pos - balls[j].pos).getLength())
					calcAfterCollisionVelocity(i , j);
			}
}
void WorldModel::update(){
	time += dt;
	speedCalc();
	for(int i = 0 ; i < (int)balls.size() ; i++){
		balls[i].pos.x() += balls[i].velocity.x() * dt;
		balls[i].pos.y() += balls[i].velocity.y() * dt;
	}
}

int WorldModel::insideWichBall(Vector2Df in){
	int retVal = -1;
	for(int i = 0 ; i < (int)balls.size() ; i++){
		if((in - balls[i].pos).getLength() < balls[i].radius)
			retVal = i;
	}
	return retVal;
}

//This will affect the player's move into the game.
void WorldModel::addMove(int i , Vector2Df cueVelocity)
{
	balls.at(i).velocity = (CUE_MASS * cueVelocity + balls.at(i).mass * balls.at(i).velocity) / balls.at(i).mass;
}
