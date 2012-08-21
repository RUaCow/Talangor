#ifndef _GUI_H
#define _GUI_H

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

class WorldModel;

class GUI {

	SDL_Surface *display; // Pointer to the SDL primary surface

public:

	GUI(); // Constructor
	~GUI(); // Destructor

	void clear(); // Clear output screen
	void draw(const WorldModel &wm); // Draw world model stuff
	void update();

private:

	inline Vector2df convert(const Vector2df &vector) {
		return Vector2df(vector.x() * (display->w/2) + display->w/2, vector.y() * (display->h/2) + display->h/2);
	}

}; // class GUI

#endif // _GUI_H

