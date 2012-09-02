#include "Minimap.h"
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include "WorldModel.h"

Minimap::Minimap() {

}

Minimap::~Minimap() {

}

void Minimap::draw(SDL_Surface *display, const WorldModel &wm) {
	const Vector2di size(display->w / 5, display->h / 5);
	const Vector2di margin(20, 20);

	rectangleRGBA(display, margin.x(), display->h - margin.y() - size.y(),
			margin.x() + size.x(), display->h - margin.y(),
			255, 255, 255, 255);
}

