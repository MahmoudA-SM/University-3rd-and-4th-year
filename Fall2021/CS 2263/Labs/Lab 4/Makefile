Strings.o: Strings.c Strings.h
	gcc -c Strings.c
main: main.o Strings.o
	gcc -o main main.o Strings.o
main.o: main.c
	gcc -c main.c
run: main
	./main output.txt
fgsmain.o: fgsmain.c
		gcc -c fgsmain.c
fgsmain: fgsmain.o Strings.o
	gcc -o fgsmain fgsmain.o Strings.o
run2: fgsmain
	./fgsmain
