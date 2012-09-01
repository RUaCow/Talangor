#ifndef _GUI_H
#define _GUI_H

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include "Vector2D.h"
#include "ForceMeter.h"
#include "Converter.h"
#include "Minimap.h"

class WorldModel;
struct GuiEvent;

class GUI {

	SDL_Surface *display; // Pointer to the SDL primary surface

	ForceMeter forceMeter;
	Minimap minimap;

	Converter converter;

public:

	GUI(); // Constructor
	~GUI(); // Destructor

	void clear(); // Clear output screen
	void draw(const WorldModel &wm); // Draw world model stuff
	const GuiEvent& update(); // Flip the output screen and update events

}; // class GUI

#endif // _GUI_H

