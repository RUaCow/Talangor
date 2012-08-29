#include "Manager.h"
#include <iostream>
using namespace std;



#pragma comment(lib , "SDL.lib")
#pragma comment(lib , "SDLmain.lib")
#pragma comment(lib , "SDL_gfx.lib")



int main(int argc , char* argv[]){
	Manager m;
	m.run();
	return 0;
}
