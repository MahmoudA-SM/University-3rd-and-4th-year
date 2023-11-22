GCC = gcc
CFLAGS = -g -Wall -Wshadow
TARGETS = genIntBin sortInMemoryIntBin sortOnDiskIntBin reportIntBin


all: $(TARGETS)

genIntBin: genIntBin.o
	$(GCC) $(CFLAGS) $@.c -o $@ -lm
	
sortInMemoryIntBin: sortInMemoryIntBin.o
	$(GCC) $(CFLAGS) $@.c -o $@ -lm
	
sortOnDiskIntBin: sortOnDiskIntBin.o
	$(GCC) $(CFLAGS) $@.c -o $@ -lm
	
reportIntBin: reportIntBin.o
	$(GCC) $(CFLAGS) $@.c -o $@ -lm

%.o: %.c
	$(GCC) $(CFLAGS) -c $*.c -lm

clean:
	rm -f $(TARGETS) *.o