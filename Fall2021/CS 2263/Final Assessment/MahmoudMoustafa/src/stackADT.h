#ifndef STACK_H
#define STACK_H
typedef struct stack {
	int top;
	int capacity;
	int* array;
}Stack;
Stack *mallocStack();
void freeStack(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
#endif