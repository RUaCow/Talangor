#include "Gui.h"
#include "WorldModel.h"
#include "GuiEvent.h"

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
	for(int i = 0; i < (int)wm.balls.size(); i ++)
		circleRGBA(display, convert(wm.balls[i].pos).x(), convert(wm.balls[i].pos).y(), wm.balls[i].radius * (float)display->w/2,
				255, 255, 255, 255);
}

const GuiEvent& GUI::update() {
	// Update events

	static GuiEvent currentEvent;
	static SDL_Event event;

	currentEvent.click = false;

	if(currentEvent.buttonState == BTN_PRESSED)
		currentEvent.buttonState = BTN_HOLD;
	else if(currentEvent.buttonState == BTN_RELEASED)
		currentEvent.buttonState = BTN_NONE;
	
	if(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT)
			currentEvent.quitEvent = true;
		else if(event.type == SDL_MOUSEBUTTONDOWN) {
			currentEvent.buttonState = BTN_PRESSED;
			currentEvent.clickStart = deconvert(Vector2df(event.button.x, event.button.y));
		} else if(event.type == SDL_MOUSEBUTTONUP) {
			currentEvent.buttonState = BTN_RELEASED;
			currentEvent.click = true;
			currentEvent.clickEnd = deconvert(Vector2df(event.button.x, event.button.y));
			//cout << Vector2df(event.button.x, event.button.y) << '\t' << convert(currentEvent.clickEnd) << endl;
			//cout << currentEvent.clickEnd << endl;
		}
	}

	// Draw force vector
	if(currentEvent.buttonState == BTN_HOLD)
		lineRGBA(display, convert(currentEvent.clickStart).x(), convert(currentEvent.clickStart).y(), event.button.x, event.button.y,
				255, 255, 255, 255);

	// Flip the screen
	SDL_Flip(display);

	return currentEvent;
}

