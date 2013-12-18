#include "testUtils.h"
#include "stack.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_new_integer_stack(){
	Stack* stack = New(sizeof(int));
	ASSERT(stack->typeSize == sizeof(int));
	ASSERT(stack->top == NULL);
	ASSERT(stack->elementsPresent == 0);
	free(stack);
};

void test_pushing_an_integer_in_the_stack(){
	Stack* stack = New(sizeof(int));
	int element =10;
	push(stack,&element);
	ASSERT(*(int*)((*stack->top).element) == 10);
	ASSERT(stack->elementsPresent == 1);
	ASSERT((*stack->top).previous == NULL);
};

void test_pop_integer_element_from_the_stack(){
	Stack* stack = New(sizeof(int));
	int element = 10;
	Stack_element* stack_element;
	push(stack,&element);
	stack_element = pop(stack);
	ASSERT(*(int*)stack_element->element == element);
};

void test_pop_integer_element_from_the_empty_stack(){
	Stack* stack = New(sizeof(int));
	int element = 10;
	Stack_element* stack_element;
	push(stack,&element);
	stack_element = pop(stack);
	stack_element = pop(stack);
	ASSERT(stack_element == NULL);
};