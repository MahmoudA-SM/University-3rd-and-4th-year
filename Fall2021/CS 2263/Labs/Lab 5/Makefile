Strings.o: Strings.c Strings.h
	gcc -w -g -Wall -Wshadow -c Strings.c
stringTest1.o: stringTest1.c Strings.c
	gcc -w -g -Wall -Wshadow -c stringTest1.c Strings.c
stringTest1: stringTest1.o Strings.o
	gcc -w -g -Wall -Wshadow -o stringTest1 stringTest1.o Strings.o
run: stringTest1
	./stringTest1
valgrindsT1: stringTest1
	valgrind --tool=memcheck --leak-check=full --verbose --log-file=logf.txt ./stringTest1
stringListTest.o: stringListTest.c Strings.c
	gcc -w -g -Wall -Wshadow -c stringListTest.c Strings.c
stringListTest: stringListTest.o Strings.o
	gcc -w -g -Wall -Wshadow -o stringListTest stringListTest.o Strings.o
valgrindsLT: stringListTest
	valgrind --tool=memcheck --leak-check=full --verbose --log-file=logSLT.txt ./stringListTest
stringListSortTest.o: stringListSortTest.c Strings.c
	gcc -w -g -Wall -Wshadow -c stringListSortTest.c Strings.c
stringListSortTest: stringListSortTest.o Strings.o
	gcc -w -g -Wall -Wshadow -o stringListSortTest stringListSortTest.o Strings.o
valgrindsLST: stringListSortTest
	valgrind --tool=memcheck --leak-check=full --verbose --log-file=logSLST.txt ./stringListSortTest