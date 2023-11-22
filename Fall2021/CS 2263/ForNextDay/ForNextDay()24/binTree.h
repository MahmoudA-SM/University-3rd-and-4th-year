#include <stdlib.h>
#include <stdio.h>
typedef struct node{
	char payload;
	struct node* right;
	struct node* left;
}Node, *pNode;
pNode mallocNode();
void freeNode(pNode n);
pNode createNode(char payload);
pNode addNode(pNode head, char payload);
void printnode(char c);
void systemicprint(pNode n);
