#include "testUtils.h"
#include "stack.h"
#include <string.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int number;
	char ch;
} Simple;

float element1,element2,element3;
float *elementToInsert1,*elementToInsert2,*elementToInsert3;
Stack* stack;
String* stringElement1,*stringElement2;
Simple *s1,*s2;

void setup(){
	element1 = 1.5f;
	element2 = 2.5f;
	element3 = 3.5f;
	elementToInsert1 = calloc(1,sizeof(float));
	elementToInsert2 = calloc(1,sizeof(float));
	elementToInsert3 = calloc(1,sizeof(float));
	stringElement1 = calloc(1,sizeof(String));
	stringElement2 = calloc(1,sizeof(String));
	s1 = (Simple*)calloc(1,sizeof(Simple));
	s2 = (Simple*)calloc(1,sizeof(Simple));
	memcpy(elementToInsert1,&element1,sizeof(float));
	memcpy(elementToInsert2,&element2,sizeof(float));
	memcpy(elementToInsert3,&element3,sizeof(float));
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
	ASSERT(element1 == *(char*)stack->list->head->data);
	ASSERT(element2 == *(char*)stack->list->head->next->data);
};

void test_pushing_three_floats_to_stack(){
	push(stack,elementToInsert1);
	push(stack,elementToInsert2);
	push(stack,elementToInsert3);
	ASSERT(element1 == *(float*)stack->list->head->data);
	ASSERT(element2 == *(float*)stack->list->head->next->data);
	ASSERT(element3 == *(float*)stack->list->head->next->next->data);
};

void test_pushing_string_to_stack(){
	strcpy((char*)stringElement1,"abc");
	strcpy((char*)stringElement2,"def");
	push(stack,stringElement1);
	push(stack,stringElement2);
	ASSERT(0 == strcmp((char*)stringElement1,stack->list->head->data));
	ASSERT(0 == strcmp((char*)stringElement2,stack->list->head->next->data));
};

void test_pushing_structure_to_stack(){
	s1->number = 10;
	s1->ch = 'a';
	s2->number = 20;
	s2->ch = 'b';
	push(stack,s1);
	push(stack,s2);
	ASSERT(10 == ((Simple*)stack->list->head->data)->number);
	ASSERT('a' == ((Simple*)stack->list->head->data)->ch);
	ASSERT(20 == ((Simple*)stack->list->head->next->data)->number);
	ASSERT('b' == ((Simple*)stack->list->head->next->data)->ch);
};

void test_pushing_double_element(){
	double doubleElement1 = 10.5,doubleElement2 = 20.5;
	double* doubleElementToInsert1 = assignSpaceAndData(sizeof(double),&doubleElement1);
	double* doubleElementToInsert2 = assignSpaceAndData(sizeof(double),&doubleElement2);
	push(stack,doubleElementToInsert1);
	push(stack,doubleElementToInsert2);
	ASSERT(doubleElement1 == *(double*)stack->list->head->data);
	ASSERT(doubleElement2 == *(double*)stack->list->head->next->data);

};

void test_popping_all_elements(){
	Node* node;
	int intElement1 = 10,intElement2 = 20;
	void* elementToPush1 = assignSpaceAndData(sizeof(int),&intElement1);
	void* elementToPush2 = assignSpaceAndData(sizeof(int),&intElement2);
	push(stack,elementToPush1);
	push(stack,elementToPush2);
	node = pop(stack);
	ASSERT(intElement2 == *(int*)node->data);
	node = pop(stack);
	ASSERT(intElement1 == *(int*)node->data);
	ASSERT(NULL == stack->list->head);
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
	ASSERT(1 == length(stack->list));
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
	ASSERT(1 == length(stack->list));
	ASSERT(0 == strcmp((char*)&element1,stack->list->head->data));
};

void test_poppig_structure_from_stack(){
	Node* node;
	s1->number = 10;
	s1->ch = 'a';
	s2->number = 20;
	s2->ch = 'b';
	push(stack,s1);
	push(stack,s2);
	node = pop(stack);
	ASSERT(20 == ((Simple*)node->data)->number);
	ASSERT('b' == ((Simple*)node->data)->ch);
	ASSERT(1 == length(stack->list));
	ASSERT(10 == ((Simple*)stack->list->head->data)->number);
	ASSERT('a' == ((Simple*)stack->list->head->data)->ch);
};

void test_popping_from_an_empty_stack(){
	Node* node = pop(stack);
	ASSERT(NULL == node);
};

void test_getting_top_integer_node(){
	Node* node;
	int intElement1 = 10,intElement2 = 20;
	void* elementToPush1 = assignSpaceAndData(sizeof(int),&intElement1);
	void* elementToPush2 = assignSpaceAndData(sizeof(int),&intElement2);
	push(stack,elementToPush1);
	push(stack,elementToPush2);
	node = top(stack);
	ASSERT(intElement2 == *(int*)node->data);
	ASSERT(2 == length(stack->list));
};

void test_getting_top_character_node(){
	Node* node;
	char element1 = 'a',element2 = 'b';
	void* elementToPush1 = assignSpaceAndData(sizeof(char),&element1);
	void* elementToPush2 = assignSpaceAndData(sizeof(char),&element2);
	push(stack,elementToPush1);
	push(stack,elementToPush2);
	node = top(stack);
	ASSERT(element2 == *(char*)node->data);
	ASSERT(NULL == node->next);
	ASSERT(NULL == node->previous);
	ASSERT(2 == length(stack->list));
	node = pop(stack);
	ASSERT(element2 == *(char*)node->data);
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

void test_getting_top_when_stack_is_empty(){
	Node* node = top(stack);
	ASSERT(NULL == node);
};