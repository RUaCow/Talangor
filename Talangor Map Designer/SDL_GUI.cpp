#include "SDL_GUI.h"
#include <SDL\SDL_gfxPrimitives.h>


SDL_GUI::SDL_GUI(void)
{
	screen = SDL_SetVideoMode(SCREEN_Width , SCREEN_Height , 0 , SDL_HWSURFACE | SDL_DOUBLEBUF);

}