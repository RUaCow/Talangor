#include "Manager.h"

Manager::Manager(): wm(3 , 0.5){

}

Manager::~Manager(){
}

void Manager::run(){
	while(1){
		pair<Vector2Df , Vector2Df> mouseR = ui.mouseRelease();
		//test
		/*static bool ali = true;
		if(ali)
			mouseR.first = wm.balls[0].pos;
		ali = false;*/
		int wb = wm.insideWichBall(mouseR.first);
		if(wb != -1)
			wm.addMove(wb , mouseR.first - mouseR.second);
		wm.update();
		ui.clear();
		ui.draw(wm);
		ui.update();
	}
}
