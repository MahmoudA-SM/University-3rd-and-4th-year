htags.o: htags.c
	gcc -c htags.c
display.o: display.c
	gcc -c display.c
htags: htags.o display.o
	gcc -o htags htags.o display.o
run: htags
	./htags HelloWorld.html