#include "WorldModel.h"
#include "Gui.h"
#include <iostream>
using namespace std;
int main(){
	cerr << "Arman is directing ...\n";
	WorldModel m(3 , 0.5);
	GUI ui;
	while(true) {
		ui.clear();
		ui.draw(m);
		ui.update();
	}
	return 0;
}
