#include "testUtils.h"
#include "stack.h"
#include <string.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Stack* stack;
void setup(){
	stack = createStack();
};

void tearDown(){
	disposeStack(stack);
}

void* assignSpaceAndData(int byte,void* element){
	void* elementToPush;
	elementToPush = calloc(1,byte);
	memcpy(elementToPush,element,byte);
	return elementToPush;
}

void test_creation_of_stack(){
	ASSERT(0 == stack->list->length);
	ASSERT(NULL == stack->list->head);
};

void test_pushing_an_integer_to_stack(){
	int element = 10;
	void* elementToPush = assignSpaceAndData(sizeof(int),&element);
	push(stack,elementToPush);
	ASSERT(element == *(int*)stack->list->head->data);
};

void test_pushing_two_characters_to_stack(){
	char element1 = 'a',element2 = 'b';
	void* elementToPush1 = assignSpaceAndData(sizeof(char),&element1);
	void* elementToPush2 = assignSpaceAndData(sizeof(char),&element2);
	push(stack,elementToPush1);
	push(stack,elementToPush2);
	ASSERT(element2 == *(char*)stack->list->head->data);
	ASSERT(element1 == *(char*)stack->list->head->next->data);
};

void test_popping_float_from_stack(){
	Node* node;
	float element1 = 10.5f,element2 = 11.5f;
	void* elementToPush1 = assignSpaceAndData(sizeof(float),&element1);
	void* elementToPush2 = assignSpaceAndData(sizeof(float),&element2);
	push(stack,elementToPush1);
	push(stack,elementToPush2);
	node = pop(stack);
	ASSERT(element2 == *(float*)node->data);
	ASSERT(element1 == *(float*)stack->list->head->data);
};

void test_popping_String_from_stack(){
	Node* node;
	String element1 = "abc",element2 = "def";
	void* elementToPush1 = assignSpaceAndData(sizeof(String),&element1);
	void* elementToPush2 = assignSpaceAndData(sizeof(String),&element2);
	push(stack,elementToPush1);
	push(stack,elementToPush2);
	node = pop(stack);
	ASSERT(0==strcmp((char*)&element2,node->data));
	ASSERT(0 == strcmp((char*)&element1,stack->list->head->data));
};

void test_getting_the_top_node_from_stack(){
	Node* node;
	String element1 = "abc",element2 = "def";
	void* elementToPush1 = assignSpaceAndData(sizeof(String),&element1);
	void* elementToPush2 = assignSpaceAndData(sizeof(String),&element2);
	push(stack,elementToPush1);
	push(stack,elementToPush2);
	node = top(stack);
	ASSERT(0==strcmp((char*)&element2,node->data));
};