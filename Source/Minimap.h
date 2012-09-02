#ifndef _MINIMAP_H
#define _MINIMAP_H

class WorldModel;
struct SDL_Surface;

class Minimap {

public:

	Minimap();
	~Minimap();

	void draw(SDL_Surface *display, const WorldModel &wm);

}; // class Minimap

#endif // _MINIMAP_H

