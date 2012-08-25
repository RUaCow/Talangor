#ifndef _GUIEVENT_H
#define _GUIEVENT_H

#include "Vector2D.h"

struct GuiEvent {

	bool quitEvent; // True if user has pressed the close button otherwise false

	bool click; // True if the right mouse button is clicked
	Vector2df clickStart, clickEnd;

}; // struct GuiEvent

#endif // _GUIEVENT_H

