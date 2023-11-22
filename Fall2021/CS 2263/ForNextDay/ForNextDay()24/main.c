#include <stdio.h>
#include <stdlib.h>
#include "binTree.h"

int main(){
	char m = 'm';
	char n = 'n';
	char o = 'o';
	Node* root = createNode(n);
	Node* l = addNode(root, m);
	Node* r = addNode(root, o);
  printf("Ordered BINTREE \n");
	systemicprint(root);
	freeNode(l);
	freeNode(root);
	freeNode(r);
	return EXIT_SUCCESS;
}
