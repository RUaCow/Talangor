#ifndef _GUI_H
#define _GUI_H

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include "Vector2D.h"

class WorldModel;
struct GuiEvent;

class GUI {

	SDL_Surface *display; // Pointer to the SDL primary surface

public:

	GUI(); // Constructor
	~GUI(); // Destructor

	void clear(); // Clear output screen
	void draw(const WorldModel &wm); // Draw world model stuff
	const GuiEvent& update(); // Flip the output screen and update events

private:

	inline Vector2Df convert(const Vector2Df &vector) {
		return Vector2Df(vector.x() * (display->w/2) + display->w/2, vector.y() * (display->w/2) + display->h/2);
	}
	inline Vector2Df deconvert(const Vector2Df &vector) {
		return Vector2Df((vector.x() - (display->w/2)) / (display->w/2), (vector.y() - (display->h/2)) / (display->w/2));
	}

}; // class GUI

#endif // _GUI_H

