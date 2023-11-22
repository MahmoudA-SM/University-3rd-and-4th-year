#include <stdlib.h>
#include <stdio.h>
#include "binTree.h"

pNode mallocNode(){
	pNode node = (pNode)malloc(sizeof(Node));
	if(node == (pNode)NULL){
		return (pNode)NULL;
	}
	return node;
}
void freeNode(pNode node){
    free(node);
}
pNode createNode(char payload){
	pNode pFirst = mallocNode();
	pFirst->payload = payload;
	return pFirst;
}

pNode addNode(pNode head, char payload){
	pNode temp;
	temp = head;
	if(temp->right == (pNode)NULL){
		if(payload > temp->payload){
			temp->right = mallocNode();
			temp->right->payload = payload;
			return temp->right;
		}
	}
	if(temp->left == (pNode)NULL){
		if(payload < temp->payload){
			temp->left = mallocNode();
			temp->left->payload = payload;
			return temp->left;
		}
	}
}

void printnode(char c){
	printf("%c\n", c);
}
void systemicprint(pNode node){
	if(node != (pNode)NULL){
		systemicprint(node->left);
		printnode(node->payload);
		systemicprint(node->right);
	}
}
