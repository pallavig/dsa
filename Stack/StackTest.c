#include "testUtils.h"
#include <string.h>
#include "Stack.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(Stack* actual,Stack* expected){
	int res = (actual->typeSize == expected->typeSize) &&
				(actual->size == expected->size) &&
				(actual->top == expected->top);
	if(!res)
		 return res;
	res = memcmp(actual->base,expected->base,actual->size*actual->typeSize);
	return 0==res;
};

int checkStackElements(Stack* stack,void* elements,int top){
	int i=0;
	if(stack->top != top)
		return 0;
	return 0 == memcmp(stack->base,elements,stack->size*stack->typeSize);
}

typedef struct
{
	int data;
	char ch;
} Simple;


//------------------New--------------------------

void test_creation_of_stack_of_three_integers(){
	Stack *actual = New(sizeof(int),3);
	int expected_arr[3] = {0,0,0};
	Stack expected = {&expected_arr,-1,3,sizeof(int)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

void test_creation_of_stack_of_three_characters(){
	Stack *actual = New(sizeof(char),3);
	char expected_arr[3] = {0,0,0};
	Stack expected = {&expected_arr,-1,3,sizeof(char)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

void test_creation_of_stack_of_three_floats(){
	Stack *actual = New(sizeof(float),3);
	float expected_arr[3] = {0.0f,0.0f,0.0f};
	Stack expected = {&expected_arr,-1,3,sizeof(float)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

void test_creation_of_stack_of_three_doubles(){
	Stack *actual = New(sizeof(double),3);
	double expected_arr[3] = {0.0,0.0,0.0};
	Stack expected = {&expected_arr,-1,3,sizeof(double)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

void test_creation_of_stack_of_three_strings(){
	Stack *actual = New(sizeof(String),3);
	String expected_arr[3] = {"","",""};
	Stack expected = {&expected_arr,-1,3,sizeof(String)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

void test_creation_of_stack_of_three_structures(){
	Stack* actual = New(sizeof(Simple),3);
	Simple *s = calloc(3,sizeof(Simple));
	Stack expected = {s,-1,3,sizeof(Simple)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

//-----------------isFull--------------------

void test_isFull_gives_1_if_stack_is_full(){
	double expected_arr[3] = {0.0,0.0,0.0};
	Stack stack = {&expected_arr,2,3,sizeof(double)};
	int result = isFull(&stack);
	ASSERT(1 == result);
};

void test_isFull_gives_0_if_stack_is_not_full(){
	double expected_arr[3] = {0.0,0.0,0.0};
	Stack stack = {&expected_arr,1,3,sizeof(double)};
	int result = isFull(&stack);
	ASSERT(0 == result);
}

//-------------------------push------------------------

void test_pushing_an_integer_element_to_stack(){
	Stack* stack = New(sizeof(int),3);
	int element = 10;
	int elements[3] = {10,0,0};
	int res = push(stack,&element);
	ASSERT(res == 1);
	ASSERT(checkStackElements(stack,elements,0));
	dispose(stack);
};

void test_pushing_an_character_element_to_stack(){
	Stack* stack = New(sizeof(char),3);
	char element = 'a';
	char elements[3] = {'a',0,0};
	int res = push(stack,&element);
	ASSERT(res == 1);
	ASSERT(checkStackElements(stack,elements,0));
	dispose(stack);
};

void test_pushing_an_float_element_to_stack(){
	Stack* stack = New(sizeof(float),3);
	float element = 10.0f;
	float elements[3] = {10.0f,0.0f,0.0f};
	int res = push(stack,&element);
	ASSERT(res == 1);
	ASSERT(checkStackElements(stack,elements,0));
	dispose(stack);
};

void test_pushing_an_double_element_to_stack(){
	Stack* stack = New(sizeof(double),3);
	double element = 10.0;
	double elements[3] = {10.0,0.0,0.0};
	int res = push(stack,&element);
	ASSERT(res == 1);
	ASSERT(checkStackElements(stack,elements,0));
	dispose(stack);
};

void test_pushing_an_String_element_to_stack(){
	Stack* stack = New(sizeof(String),3);
	String element = "abc";
	String elements[3] = {"abc","",""};
	int res = push(stack,&element);
	ASSERT(res == 1);
	ASSERT(checkStackElements(stack,elements,0));
	dispose(stack);
};

void test_pushing_an_strucure_element_to_stack(){
	Stack* stack = New(sizeof(Simple),3);
	Simple *element = calloc(1,sizeof(Simple));
	Simple *emptyElement = calloc(1,sizeof(Simple));
	Simple* elements = calloc(3,sizeof(Simple));
	int res;
	element->data = 10;
	element->ch ='a';
	elements[0].data = 10;
	elements[0].ch = 'a';
	res = push(stack,element);
	ASSERT(res == 1);
	ASSERT(checkStackElements(stack,elements,0));
	dispose(stack);
};

void test_pushing_two_elements_in_the_stack(){
	Stack* stack = New(sizeof(int),3);
	int element = 10;
	int elements[3] = {10,0,0};
	int res = push(stack,&element);
	ASSERT(res == 1);
	ASSERT(checkStackElements(stack,elements,0));
	res = push(stack,&element);
	ASSERT(res == 1);
	elements[1] = 10;
	ASSERT(checkStackElements(stack,elements,1));
	dispose(stack);
}

void test_pushing_an_integer_element_when_stack_is_full(){
	Stack* stack = New(sizeof(int),3);
	int element = 10;
	int res = push(stack,&element);
	res = push(stack,&element);
	res = push(stack,&element);
	ASSERT(stack->top == 2);
	res = push(stack,&element);
	ASSERT(res == 0);
	dispose(stack);
};

//------------------isEmpty--------------------------------

void test_isEmpty_returns_1_if_the_stack_is_empty(){
	Stack* stack = New(sizeof(int), 3);
	int result = isEmpty(stack);
	ASSERT(1 == result);
	dispose(stack);
};

void test_isEmpty_returns_0_if_the_stack_is_not_empty(){
	Stack* stack = New(sizeof(int), 3);
	int data = 10;
	int element = push(stack,&data );
	int result = isEmpty(stack);
	ASSERT(0 == result);
	dispose(stack);
};

//------------------pop------------------------------------

void test_popping_an_integer_element_from_stack(){
	Stack* stack = New(sizeof(int), 3);
	int* result;
	int status ,element = 10;
	status = push(stack, &element);
	result = pop(stack);
	ASSERT(*result == 10);
	ASSERT(stack->top == -1);
	dispose(stack);
};

void test_popping_an_character_element_from_stack(){
	Stack* stack = New(sizeof(char), 3);
	char* result;
	int status;
	char element = 'a';
	status = push(stack, &element);
	result = pop(stack);
	ASSERT(*result == 'a');
	ASSERT(stack->top == -1);
	dispose(stack);
};

void test_popping_an_double_element_from_stack(){
	Stack* stack = New(sizeof(double), 3);
	double* result;
	int status;
	double element = 10.0;
	status = push(stack, &element);
	result = pop(stack);
	ASSERT(*result == 10.0);
	ASSERT(stack->top == -1);
	dispose(stack);
};

void test_popping_an_float_element_from_stack(){
	Stack* stack = New(sizeof(float), 3);
	float* result;
	int status;
	float element = 10.0;
	status = push(stack, &element);
	result = pop(stack);
	ASSERT(*result == 10.0);
	ASSERT(stack->top == -1);
	dispose(stack);
};

void test_popping_an_String_element_from_stack(){
	Stack* stack = New(sizeof(String), 3);
	String* result;
	int status;
	String element = "abc";
	status = push(stack, &element);
	result = pop(stack);
	ASSERT(0 == strcmp(*result,"abc"));
	ASSERT(stack->top == -1);
	dispose(stack);
};

void test_popping_an_integer_element_when_the_stack_is_empty(){
	Stack* stack = New(sizeof(int), 3);
	int* result;
	result = pop(stack);
	ASSERT(NULL == result);
	dispose(stack);
};

//------------------top---------------------

void test_top_element_in_stack_of_integers(){
	Stack* stack = New(sizeof(int),3);
	int* result;
	int res;
	int element = 10;
	res = push(stack,&element);
	result = top(stack);
	ASSERT(element == *result);
	dispose(stack);
};

void test_top_element_in_stack_of_characters(){
	Stack* stack = New(sizeof(char),3);
	char* result;
	int res;
	char element = 'a';
	res = push(stack,&element);
	result = top(stack);
	ASSERT(element == *result);
	dispose(stack);
};

void test_top_element_in_stack_of_floats(){
	Stack* stack = New(sizeof(float),3);
	float* result;
	int res;
	float element = 10.0f;
	res = push(stack,&element);
	result = top(stack);
	ASSERT(element == *result);
	dispose(stack);
};

void test_top_element_in_stack_of_doubles(){
	Stack* stack = New(sizeof(double),3);
	double* result;
	int res;
	double element1 = 10.0;
	double element2 = 11.0;
	res = push(stack,&element1);
	res = push(stack,&element2);
	result = top(stack);
	ASSERT(element2 == *result);
	dispose(stack);
};

void test_top_element_in_stack_of_Strings(){
	Stack* stack = New(sizeof(String),3);
	String* result;
	int res;
	String element1 = "abc";
	String element2 = "xyz";
	res = push(stack,&element1);
	res = push(stack,&element2);
	result = top(stack);
	ASSERT(0 == strcmp(element2,*result));
	dispose(stack);
};

void test_top_element_in_stack_of_structures(){
	Stack* stack =New(sizeof(Simple),3);
	Simple* s = calloc(1,sizeof(Simple));
	Simple* expected;
	int res;
	s->data = 10;
	s->ch = 'b';
	res = push(stack,s);
	expected = top(stack);
	ASSERT(expected->data == 10);
	ASSERT(expected->ch == 'b');
	dispose(stack);
};