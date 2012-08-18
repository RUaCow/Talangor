/**************************************************************
	File:		Random.h
	Author: 	Erfan Loghmani
	Purpose: 	generate random numbers.
	Date: 		8 / 18 / 2012
	Source:		http://www1.gantep.edu.tr/~bingul/simulation/detSim/Random.h.html
**************************************************************/
#ifndef _RANDOM_H
#define _RANDOM_H

#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
class Random{
	int RandMax;
public:
	Random(){
		srand(time(NULL));
		RandMax = (1 << 20);
	}
	float Flat(float min = 0.0 , float max = 1.0){
		return (min + (max - min) * rand() / RandMax);
	}
	float Gauss(float mean = 0.0 , float sigma = 1.0){
		float x , y , z;
		while(1){
			x = 2 * Flat() - 1.0;
			y = 2 * Flat() - 1.0;
			z = x * x + y * y;
			if(z <= 1.0)
				break;
		}
		return (mean + sigma * x * sqrt(-2.0 * log(z) / z));
	}
};
#endif //_RANDOM_H
