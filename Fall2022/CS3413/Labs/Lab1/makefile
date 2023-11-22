CC=gcc
CFLAGS=-Wall -I.
DEPS=hellomake.h
OBJS=hellomake.o hellofunc.o
EXE=hellomake

hellomake: $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS)

hellomake.o: hellomake.c $(DEPS)
	$(CC) -c hellomake.c $(CFLAGS)

hellofunc.o: hellofunc.c $(DEPS)
	$(CC) -c hellofunc.c $(CFLAGS)

run:
	./$(EXE)

clean:
	rm $(OBJS) $(EXE) *.out 
	
	 

debug: hellomake.c hellofunc.c $(DEPS)
	$(CC) -g hellomake.c hellofunc.c $(CFLAGS) -o $(EXE)