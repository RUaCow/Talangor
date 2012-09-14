#ifndef TmDmAnAgEr_H
#define TmDmAnAgEr_H


class Map;
class SDL_GUI;

class TMDManager
{
	Map* map;
	SDL_GUI* gui;

public:
	//constructor
	TMDManager(void);
	//destructor
	~TMDManager(void);
};

#endif