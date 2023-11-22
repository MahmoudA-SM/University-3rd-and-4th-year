#include "stackADT.h"
#include <stdio.h>
#include <stdlib.h>


Stack* mallocStack(int capacity)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}
void freeStack(Stack* stack){
	int i;
	for (int i = 0; i < stack->capacity; i++){
		
		free(stack->array[i]);
	}
	free(stack);
}
int isFull(Stack* stack)
{
	return stack->top == stack->capacity - 1;
}
int isEmpty(Stack* stack)
{
	return stack->top == -1;
}
void push(Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
}
int pop(Stack* stack)
{
	if (isEmpty(stack))
		return (int)NULL;
	return stack->array[stack->top--];
}
int peek(Stack* stack)
{
	if (isEmpty(stack))
		return (int) NULL;
	return stack->array[stack->top];
}

int main()
{
	Stack* stack = mallocStack(5);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	printf("%d\n",peek(stack));
	pop(stack);
	printf("%d\n",peek(stack));
	freeStack(stack);
	return 0;
}

