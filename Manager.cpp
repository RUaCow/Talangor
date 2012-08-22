#include "Manager.h"

Manager::Manager(): wm(3 , 0.5){

}

Manager::~Manager(){
}

void Manager::run(){
	while(1){
		ui.clear();
		ui.draw(wm);
		ui.update();
	}
}
