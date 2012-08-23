#include "Manager.h"
#include "GuiEvent.h"

Manager::Manager(): wm(3 , 0.5){

}

Manager::~Manager(){
}

void Manager::run(){
	while(1){
		const Vector2Df zero(0, 0);
		pair<Vector2Df , Vector2Df> mouseR = /*ui.mouseRelease()*/ make_pair(zero, zero);

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

		GuiEvent event = ui.update();
		if(event.quitEvent)
			break;
	}
}
