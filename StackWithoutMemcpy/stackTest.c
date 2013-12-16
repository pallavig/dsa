#include "testUtils.h"
#include "stack.h"
#include <stdlib.h>
#include <string.h>

Stack* stack;

void dispose(Stack* stack){
	free(stack->base);
	free(stack);
};

void setup(){
	stack = create(3);
};

void tearDown(){
	dispose(stack);
};

int areEqual(Stack expected, Stack actual){
    int result = expected.size == actual.size && expected.top == actual.top;
    if(!result) return result;
    return 0 == memcmp(expected.base,actual.base,expected.size*sizeof(void*));
};

void test_creation_of_stack(){
    void* array[3] = {NULL,NULL,NULL};
    Stack expected = {array,-1,3};
    ASSERT(areEqual(expected, *stack));
};

void test_push_integer(){
	int *element = malloc(sizeof(int));
	*element = 10;
	push(stack,element);
	ASSERT(*element == **(int**)getElement(stack,0));
	free(element);
};

void test_push_two_integers(){
	int *element = malloc(sizeof(int)*2);
	element[0] = 1;element[1] = 2;
	push(stack,&element[0]);
	push(stack,&element[1]);
	ASSERT(element[0] == **(int**)getElement(stack,0));
	ASSERT(element[1] == **(int**)getElement(stack,1));
	free(element);
};

void test_pushing_an_character_in_stack(){
	char *elementToPush = malloc(sizeof(char));
	*elementToPush = 'a';
	push(stack,elementToPush);
	ASSERT(0 == stack->top);
	ASSERT(*elementToPush == **(char**)getElement(stack,0));
	free(elementToPush);
};

void test_pushing_an_float_in_stack(){
	float *elementToPush = malloc(sizeof(float));
	*elementToPush = 10.5f;
	push(stack,elementToPush);
	ASSERT(0 == stack->top);
	ASSERT(*elementToPush == **(float**)getElement(stack,0));
	free(elementToPush);
};


void test_pushing_an_double_in_stack(){
	double* elementToPush = malloc(sizeof(double));
	*elementToPush = 10.5;
	push(stack,elementToPush);
	ASSERT(0 == stack->top);
	ASSERT(*elementToPush == **(double**)getElement(stack,0));
	free(elementToPush);
};

void test_pushing_an_String_in_stack(){
	String* elementToPush = malloc(sizeof(String));
	strcpy((char*)elementToPush,"abcd");
	push(stack,elementToPush);
	ASSERT(0 == stack->top);
	ASSERT(0 == strcmp((char*)elementToPush,*(char**)getElement(stack,0)));
	free(elementToPush);
};

void test_pushing_elements_equal_to_size_of_stack(){
	int *element = malloc(sizeof(int)*3);
	element[0] = 1;element[1] = 2;element[2] = 3;
	push(stack,&element[0]);
	push(stack,&element[1]);
	push(stack,&element[2]);
	ASSERT(element[0] == **(int**)getElement(stack,0));
	ASSERT(element[1] == **(int**)getElement(stack,1));
	ASSERT(element[2] == **(int**)getElement(stack,2));
	free(element);	
};

// void test_pushing_elements_when_stack_is_full(){
// 	char *elementToPush = malloc(sizeof(char)*4);
// 	elementToPush[0] = 'a';elementToPush[1] = 'b';elementToPush[2] = 'c';
// 	elementToPush[3] = 'd';
// 	push(stack,&elementToPush[0]);
// 	push(stack,&elementToPush[1]);
// 	push(stack,&elementToPush[2]);
// 	push(stack,&elementToPush[3]);
// 	ASSERT(elementToPush[0] == **(char**)getElement(stack,0));
// 	ASSERT(elementToPush[1] == **(char**)getElement(stack,1));
// 	ASSERT(elementToPush[2] == **(char**)getElement(stack,2));
// 	ASSERT(elementToPush[3] == **(char**)getElement(stack,3));
// 	free(elementToPush);	
// };

void test_popping_an_integer(){
	void* poppedElement;
	int *element = malloc(sizeof(int));
	*element = 10;
	push(stack,element);
	poppedElement = pop(stack);
	ASSERT(10 == *(int*)poppedElement);
	ASSERT(-1 == stack->top);
};