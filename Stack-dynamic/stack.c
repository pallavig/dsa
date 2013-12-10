#include "stack.h"
#include <string.h>
#include <stdlib.h>
Stack* New(int typeSize){
	Stack* stack = calloc(1,sizeof(Stack));
	stack->top = NULL;
	stack->typeSize = typeSize;
	stack->elementsPresent = 0;
	return stack;
};

void push(Stack* stack,void* element){
	Stack_element* stack_element = calloc(1,sizeof(Stack_element));
	int *elementToBePushed = (int*)calloc(1,stack->typeSize);
	memcpy(elementToBePushed,element,stack->typeSize);
	stack_element->element = elementToBePushed;
	if(stack->top == NULL){
		stack_element->previous = NULL;
		stack->top = stack_element;
	}
	else {
		stack_element->previous = stack->top;
		stack->top = stack_element;
	}
	stack->elementsPresent++;
};

Stack_element* pop(Stack* stack){
	Stack_element *stack_element;
	Stack_element* poppedElement;
	if(stack->top == NULL)
		return NULL;
	stack_element = calloc(1,sizeof(Stack_element));
	poppedElement = stack->top;
	stack_element->element = calloc(1,stack->typeSize);
	memcpy(stack_element->element, stack->top->element,stack->typeSize);
	stack->top = (*stack->top).previous;
	poppedElement->previous = NULL;
	free(poppedElement->element);
	free(poppedElement);
	return stack_element;
};