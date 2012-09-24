#include "SDL_GUI.h"
#include <SDL\SDL_gfxPrimitives.h>
#include "Map.h"
#include "Shape.h"



using namespace std;


SDL_GUI::SDL_GUI(void) : converter(-1 , +1 , -0.75 , +0.75 , SCREEN_Width , SCREEN_Height)
{
	SDL_WM_SetCaption("Talangor Map Designer" , 0);
	screen = SDL_SetVideoMode(SCREEN_Width , SCREEN_Height , 0 , SDL_HWSURFACE | SDL_DOUBLEBUF);
}

void SDL_GUI::drawGrid(void)
{

}

void SDL_GUI::drawShapes(vector<Shape> shapes)
{
	int snum = (int)shapes.size();

	for(int i = 0 ; i < snum ; i++)
	{
		int pnum = (int)shapes[i].getPoints().size();

		//drawing the shape.
		for(int j = 0 ; j < pnum - 1 ; j++)
		{
			lineRGBA(screen , converter.C(shapes[i].getPoints()[j]).x() , converter.C(shapes[i].getPoints()[j]).y() , converter.C(shapes[i].getPoints()[j + 1]).x() , converter.C(shapes[i].getPoints()[j + 1]).y() , 255 , 255 , 255 , 255);
		}

		//closing the shape.
		lineRGBA(screen , converter.C(shapes[i].getPoints()[pnum - 1]).x() , converter.C(shapes[i].getPoints()[pnum - 1]).y() , converter.C(shapes[i].getPoints()[0]).x() , converter.C(shapes[i].getPoints()[0]).y() , 255 , 255 , 255 , 255);

		//drawing the inside shapes.
		drawShapes(shapes[i].getInsideShapes());
	}
}

void SDL_GUI::drawMap(const Map map)
{
	char* title = new char [200];
	sprintf(title , "%s - Talangor Map Designer V%s" , map.getMapName() , "0.1");
	SDL_WM_SetCaption(title , 0);

	drawShapes(map.getMapShapes());

	SDL_Flip(screen);
}

void SDL_GUI::clear(void)
{
	SDL_FillRect(screen , NULL , SDL_MapRGBA(screen->format, 0, 0, 0, 0));
}