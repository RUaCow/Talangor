C=g++
CFLAGS=-O2 -Wall
all:	Ball.o
Ball.o:
	$(C) Ball.cpp -c $(CFLAGS)
clean:
	rm -rf *.o
