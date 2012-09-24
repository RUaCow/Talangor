#ifndef SdL_gUi_H
#define SdL_gUi_H

#define SCREEN_Height 600
#define SCREEN_Width 800
#include <vector>
#include "Converter.h"



class Shape;
class Map;
struct SDL_Surface;


class SDL_GUI
{
	SDL_Surface* screen;

	Converter converter;

	//This draws grid on the screen.
	void drawGrid(void);
	//This will draw the shapes of the map.
	void drawShapes(std::vector<Shape> shapes);
	//This will clear the screen.
	void clear(void);
public:
	//constructor
	SDL_GUI(void);

	//This will draw the map.
	void drawMap(const Map map);
};


#endif