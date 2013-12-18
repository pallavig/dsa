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

Node* pop(Stack* stack){
	Node* node;
	if(stack->list->head == NULL) return NULL;
	node = remove(stack->list,stack->list->length);
	return node;
};

Node* top(Stack* stack){
	Node* node;
	Node* removedElement;
	if(stack->list->head == NULL) return NULL;
	node = calloc(1,sizeof(Node));
	removedElement = pop(stack);
	memcpy(node,removedElement,sizeof(Node));
	push(stack,removedElement->data);
	return node;
};

void disposeStack(Stack* stack){
	dispose(stack->list);
	free(stack);
};