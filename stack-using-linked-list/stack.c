#include "stack.h"
#include <stdlib.h>
#include <string.h>
Stack* createStack(){
	Stack* stack = calloc(1,sizeof(Stack));
	stack->list = create();
	return stack;
};

void push(Stack* stack,void* element){
	insert(stack->list,element,stack->list->length+1);
};

void* pop(Stack* stack){
	void* node;
	if(stack->list->head == NULL) return NULL;
	node = remove(stack->list,stack->list->length);
	return node;
};

void* top(Stack* stack){
	void* node;
	void* removedElement;
	if(stack->list->head == NULL) return NULL;
	node = calloc(1,sizeof(Node));
	removedElement = pop(stack);
	memcpy(node,removedElement,sizeof(Node));
	push(stack,removedElement);
	return node;
};

void disposeStack(Stack* stack){
	dispose(stack->list);
	free(stack);
};