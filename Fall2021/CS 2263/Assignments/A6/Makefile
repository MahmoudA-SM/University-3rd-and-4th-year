GCC = gcc
CFLAGS = -g -Wall -Wshadow
TARGETS = playStack playQueue

HSTACK = Point2D.h Stack.h
OStack = Point2D.o Stack.o

HQUEUE = Point2D.h Queue.h
OQUEUE = Point2D.o Queue.o


run: $(TARGETS)

playQueue: $(OQUEUE) $(HQUEUE)
	$(GCC) $(CFLAGS) $(OQUEUE) $@.c -o $@ 

playStack: $(OStack) $(HSTACK)
	$(GCC) $(CFLAGS) $(OStack) $@.c -o $@

