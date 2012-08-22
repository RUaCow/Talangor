C=g++
CFLAGS=-g -O2 -Wall
CFLAGSG=-lSDL -lSDL_gfx
all:	Ball.o WorldModel.o Gui.o Manager.o
	$(C) main.cpp -o Talangor Ball.o Gui.o WorldModel.o Manager.o $(CFLAGS) $(CFLAGSG)
Ball:
	$(C) Ball.cpp -c $(CFLAGS)
WorldModel:
	$(C) WorldModel.cpp -c $(CFLAGS)
Gui:
	$(C) Gui.cpp -c $(CFLAGS)
Manager:
	$(C) Manager.cpp $(CFLAGS)
clean:
	rm -rf *.o talangor
touch:
	touch *.cpp
