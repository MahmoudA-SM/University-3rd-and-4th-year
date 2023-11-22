#include <stdio.h>
#include <stdlib.h>
void display(int c, char *t){
	int i = 0;
	while(t[i] != '>' && t[i] != ' ' && t[i] != '/'){
		printf("%c", t[i]);
		i++;
	}
	printf(" --> %d\n", c);
	
}