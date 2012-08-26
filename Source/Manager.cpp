#include "Manager.h"
#include "GuiEvent.h"

Manager::Manager(): wm(3 , 0.5){

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
			int wb = wm.insideWichBall(clickS);
			if(wb != -1)
				wm.addMove(wb , clickS - clickE);
		}
		if(event.quitEvent)
			break;
	}
}
