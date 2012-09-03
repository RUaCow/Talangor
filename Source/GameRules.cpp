#include "GameRules.h"
GameRules::GameRules(int n){
	canPlay = true;
	whichTurn = 0;
	for(int i = 0 ; i < n ; i ++){
		Player tmp(i , -1 , 0);
		players.push_back(tmp);
	}
}

int GameRules::getPrevTurn() const{
	return (whichTurn - 1) % players.size();
}
