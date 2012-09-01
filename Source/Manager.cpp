#include "Manager.h"
#include "GuiEvent.h"

Manager::Manager(): wm(3 , 0.5){
	//As you know GameType is an int inside Map so here whene we initial the wm and we have Map we can choose how to new GameRules
	//Till know that we have 2 GameTypes we encode theme as this:
	//0 = PointGain (for 2 players and ...)
	//1 = destination (for solo)
	gr = new PointGain();
}

Manager::~Manager(){
}

void Manager::run(){
	while(1){
		wm.update();

		ui.clear();
		ui.draw(wm);

		GuiEvent event = ui.update();
		if(event.click){
			Vector2Df clickS = event.clickStart;
			Vector2Df clickE = event.clickEnd;
			bool canPlay = gr->turnPlay(wm , event);
			if(canPlay){
				int wb = wm.insideWhichBall(clickS);
				if(wb != -1)
					wm.addMove(wb , clickS - clickE);
			}
		}
		if(gr->addPoint(wm)){
			//Show it :D
		}
		if(gr->winning()){
			//Show it too :P
		}
		if(event.quitEvent)
			break;
	}
}
