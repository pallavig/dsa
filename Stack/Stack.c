#include "Stack.h"
#include <stdlib.h>
#include <string.h>

Stack* New(int typeSize,int size){
	Stack *stack = (Stack*)calloc(1,sizeof(Stack));
	stack->typeSize = typeSize;
	stack->base = calloc(size,typeSize);
	stack->size = size;
	stack->top = (-1);
	return stack;
};

int isFull(Stack* stack){
	return ((stack->top+1) == stack->size);
};

int push(Stack* stack,void* element){
	int offset;
	if(isFull(stack))
		return 0;
	stack->top = stack->top + 1;
	offset = stack->top*stack->typeSize;
	memcpy(stack->base+offset,element,stack->typeSize);
	return 1;
};

int isEmpty(Stack* stack){
	return ((stack->top) == -1);
};

void* pop(Stack *stack){
	void* poppedElement = malloc(stack->typeSize);
	int offset;
	if(isEmpty(stack))
		return NULL;
	offset = stack->top*stack->typeSize;
	memcpy(poppedElement,stack->base + offset, stack->typeSize);
	stack->top = stack->top - 1;
	return poppedElement;
};

void* top(Stack* stack){
	void* topElement = malloc(stack->typeSize);
	int offset;
	if(isEmpty(stack))
		return NULL;
	offset = stack->top*stack->typeSize;
	memcpy(topElement,stack->base + offset, stack->typeSize);
	return topElement;
};