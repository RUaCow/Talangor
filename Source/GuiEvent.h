#ifndef _GUIEVENT_H
#define _GUIEVENT_H

#include "Vector2D.h"

enum MBState {

	BTN_NONE = 0,
	BTN_PRESSED = 1,
	BTN_RELEASED = 2,
	BTN_HOLD = 3

}; // enum MBState

struct GuiEvent {

	bool quitEvent; // True if user has pressed the close button otherwise false

	bool click; // True if the right mouse button is clicked
	Vector2df clickStart, clickEnd;

	MBState buttonState;

}; // struct GuiEvent

#endif // _GUIEVENT_H

