#ifndef SdL_gUi_H
#define SdL_gUi_H

#define SCREEN_Height 600
#define SCREEN_Width 800

struct SDL_Surface;


class SDL_GUI
{
	SDL_Surface* screen;

	//This draws grid on the screen.
	void drawGrid(void);

public:
	SDL_GUI(void);
};


#endif