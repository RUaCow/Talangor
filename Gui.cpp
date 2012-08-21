#include "Gui.h"
#include "WorldModel.h"

GUI::GUI() {
	SDL_Init(SDL_INIT_VIDEO);
	display = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
}

GUI::~GUI() {
	SDL_Quit();
}

void GUI::clear() {
	SDL_FillRect(display, NULL, SDL_MapRGBA(display->format, 0, 0, 0, 0));
}

void GUI::draw(const WorldModel &wm) {
	// Draw balls
	for(int i = 0; i < wm.balls.size(); i ++)
		circleRGBA(display, convert(wm.balls[i].pos).x(), convert(wm.balls[i].pos).y(), wm.balls[i].radius,
				255, 255, 255, 255);
}

void GUI::update() {
	SDL_Flip(display);
}

