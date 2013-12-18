#include "testUtils.h"
#include "stack.h"
#include <stdlib.h>
#include <string.h>

void test_creation_of_stack(){
	Stack *pStack = create(3);
	ASSERT(pStack->top == -1);
	ASSERT(pStack->size == 3);
	dispose(pStack);
};

void test_push_integer(){
	Stack *pStack = create(3);
	void* topElement;
	int element = 10;
	push(pStack,&element);
	topElement = top(pStack);
	ASSERT(element == *(int*)topElement);
	dispose(pStack);
};

void test_push_two_integers(){
	Stack *pStack = create(3);
	void *topElement;
	int element1 = 10,element2 = 20;
	push(pStack,&element1);
	topElement = top(pStack);
	ASSERT(element1 == *(int*)top(pStack));
	push(pStack,&element2);
	ASSERT(element2 == *(int*)top(pStack));
	dispose(pStack);
};

void test_pushing_an_character_in_stack(){
	Stack *pStack = create(3);
	void *topElement;
	char element = 'a';
	push(pStack,&element);
	ASSERT(element == *(char*)top(pStack));
	dispose(pStack);
};

void test_pushing_an_float_in_stack(){
	Stack *pStack = create(1);
	float element = 10.5f;
	push(pStack,&element);
	ASSERT(element == *(float*)top(pStack));
	dispose(pStack);
};

void test_pushing_an_double_in_stack(){
	Stack *pStack = create(2);
	double element = 10;
	push(pStack,&element);
	ASSERT(element == *(double*)top(pStack));
	dispose(pStack);
};

void test_pushing_an_String_in_stack(){
	Stack *pStack = create(2);
	String element = "abcd";
	push(pStack,&element);
	ASSERT(0 == strcmp(element,(char*)top(pStack)));
	dispose(pStack);
};

void test_pushing_elements_equal_to_size_of_stack(){
	Stack *pStack = create(2);
	int element1 = 10,element2 = 20,element3 = 30;
	push(pStack,&element1);
	push(pStack,&element2);
	push(pStack,&element3);
	ASSERT(element3 == *(int*)pop(pStack));
	ASSERT(element2 == *(int*)pop(pStack));
	ASSERT(element1 == *(int*)pop(pStack));
	dispose(pStack);
};

void test_pushing_elements_when_stack_is_full(){
	Stack *pStack = create(2);
	char element1 = 'a',element2 = 'b',element3 = 'c',element4 = 'd';
	push(pStack,&element1);
	push(pStack,&element2);
	push(pStack,&element3);
	push(pStack,&element4);
	ASSERT(element4 == *(char*)pop(pStack));
	ASSERT(element3 == *(char*)pop(pStack));
	ASSERT(element2 == *(char*)pop(pStack));
	ASSERT(element1 == *(char*)pop(pStack));
	dispose(pStack);
};

void test_popping_one_integer_when_two_are_present(){
	Stack *pStack = create(2);
	int element1 = 10,element2 = 20;
	push(pStack,&element1);
	push(pStack,&element2);
	ASSERT(element2 == *(int*)pop(pStack));
	ASSERT(element1 == *(int*)top(pStack));
	dispose(pStack);
};

void test_popping_from_an_empty_stack(){
	Stack *pStack = create(2);
	char element = 'a';
	push(pStack,&element);
	ASSERT(element == *(char*)pop(pStack));
	ASSERT(NULL == pop(pStack));
	dispose(pStack);
};

void test_getting_top_element_from_empty_stack(){
	Stack *pStack = create(3);
	ASSERT(NULL == top(pStack));
};