GCC = gcc
CFLAGS = -g -Wall -Wshadow
TARGETS = sortTest stringListSortTest sortPoint2D
ST = sortTest.o
SLST = stringListSortTest.o
sP = sortPoint2D.o


all: $(TARGETS)

sortTest: $(ST)
	$(GCC) $(CFLAGS) $(ST) -o $@ 
	
stringListSortTest: $(SLST) 
	$(GCC) $(CFLAGS) $(SLST) -o $@
	
sortPoint2D: $(sP) 
	$(GCC) $(CFLAGS) $(sP) -o $@

%.o: %.c
	$(GCC) $(CFLAGS) -c $*.c 

clean:
	rm -f $(TARGETS) *.o

