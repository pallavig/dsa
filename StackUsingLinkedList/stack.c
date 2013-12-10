#include "stack.h"
#include <stdlib.h>
#include <string.h>
Stack* createStack(){
	Stack* stack = calloc(1,sizeof(Stack));
	stack->list = create();
	return stack;
};

void push(Stack* stack,void* element){
	insert(stack->list,element,1);
};

Node* pop(Stack* stack){
	Node* node;
	if(stack->list->head == NULL) return NULL;
	node = remove(stack->list,1);
	return node;
};

Node* top(Stack* stack){
	Node* node;
	if(stack->list->head == NULL) return NULL;
	node = calloc(1,sizeof(Node));
	memcpy(node,stack->list->head,sizeof(Node));
	node = setLinksToNULL(node);
	return node;
};

void disposeStack(Stack* stack){
	dispose(stack->list);
	free(stack);
};