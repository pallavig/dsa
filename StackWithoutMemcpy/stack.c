#include "stack.h"
#include <stdlib.h>

Stack* create(int size){
    Stack* stack = calloc(sizeof(Stack), 1);
    stack->base = calloc(sizeof(void*), size);
    stack->top = -1;
    stack->size = size;
    return stack;
};

int isFull(Stack* stack){
	// printf("--->%d %d\n",stack->top+1,stack->size);
    return stack->top+1 == stack->size;
};

void** getElement(Stack* stack,int top){
    return stack->base + top * sizeof(stack->base);
};

int push(Stack* stack,void* element){
    void *temp;
    if(isFull(stack)){
    	printf("Entered\n");
        stack->size = stack->size*2;
        printf("*** %d\n",stack->size);
        temp = realloc(stack->base,stack->size*sizeof(void*));
        if(!temp)
        	return 0;
        stack->base = temp;

    }
    stack->top++;
    *(getElement(stack,stack->top)) = element;
    return 1;
};

void* pop(Stack *stack){
	return *(getElement(stack,stack->top--));
};