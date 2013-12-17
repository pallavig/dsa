#include "stack.h"
#include <stdlib.h>

Stack* create(int size){
    Stack* pStack = calloc(sizeof(Stack), 1);
    pStack->base = calloc(sizeof(void*), size);
    pStack->top = -1;
    pStack->size = size;
    return pStack;
};

int isFull(Stack* pStack){
    return pStack->top+1 == pStack->size;
};

int push(Stack* pStack,void* element){
    void *temp;
    if(isFull(pStack)){
        pStack->size = pStack->size*2;
        temp = realloc(pStack->base,pStack->size*sizeof(void*));
        if(!temp)
        	return 0;
        pStack->base = temp;

    }
    pStack->top++;
    *(pStack->base + pStack->top) = element;
    return 1;
};

int isEmpty(Stack* pStack){
    return -1 == pStack->top;
};

void* top(Stack* pStack){
    void *topElement;
    if(isEmpty(pStack))
        return NULL;
    topElement = *(pStack->base+pStack->top);
    return topElement;
};

void* pop(Stack *stack){
    void *topElement;
    topElement = top(stack);
    if(topElement != NULL)
        stack->top--;
    return topElement;
};

void dispose(Stack* stack){
    free(stack->base);
    free(stack);
};