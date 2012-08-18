C=g++
CFLAGS=-g -O2 -Wall
all:	Ball.o WorldModel.o
	$(C) main.cpp -o talangor Ball.o WorldModel.o $(CFLAGS)
Ball:
	$(C) Ball.cpp -c $(CFLAGS)
WorldModel:
	$(C) WorldModel.cpp -c $(CFLAGS)
clean:
	rm -rf *.o talangor
touch:
	touch *.cpp
