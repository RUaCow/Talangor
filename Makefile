C=g++
CFLAGS=-g -O2 -Wall
CFLAGSG=-lSDL -lSDL_gfx
all:	Ball.o WorldModel.o Gui.o
	$(C) main.cpp -o Talangor Ball.o Gui.o WorldModel.o $(CFLAGS) $(CFLAGSG)
Ball:
	$(C) Ball.cpp -c $(CFLAGS)
WorldModel:
	$(C) WorldModel.cpp -c $(CFLAGS)
Gui:
	$(C) Gui.cpp -c $(CFLAGS)
clean:
	rm -rf *.o talangor
touch:
	touch *.cpp
