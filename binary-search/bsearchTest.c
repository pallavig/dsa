#include "testUtils.h"
#include "bsearch.h"
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntegers(ConstVoidPtr key,ConstVoidPtr element){
	return *(int*)key - *(int*)element;
};

int compareChars(ConstVoidPtr key,ConstVoidPtr element){
	return *(char*)key - *(char*)element;
};

int compareFloats(ConstVoidPtr key,ConstVoidPtr element){
	return *(float*)key - *(float*)element;
};

int compareDouble(ConstVoidPtr key,ConstVoidPtr element){
	return *(double*)key - *(double*)element;
}

void test_search_middle_element_in_array(){
	int key = 30;
	int arr[] = {10,20,30,40,50};
	ConstVoidPtr result;
	result = bsearch(&key,&arr,5,sizeof(int),compareIntegers);
	ASSERT(30 == *(int*)result);
};

void test_search_the_first_element_of_array(){
	char key = 'a';
	char arr[] = {'a','b','c','d','e'};
	ConstVoidPtr result;
	result = bsearch(&key,&arr,5,sizeof(char),compareChars);
	ASSERT(key == *(char*)result);
};

void test_search_last_element_of_the_array(){
	float key = 10.5f;
	float arr[] = {1.5f,2.5f,3.5f,4.5f,10.5f};
	ConstVoidPtr result;
	result = bsearch(&key,&arr,5,sizeof(float),compareFloats);
	ASSERT(key == *(float*)result);
};

void test_search_element_in_array_of_even_number_size(){
	double key = 2.5;
	double arr[] = {1.5,2.5,3.5,4.5,5.5,6.5};
	ConstVoidPtr result;
	result = bsearch(&key,&arr,6,sizeof(double),compareDouble);
	ASSERT(key == *(double*)result);
};

void test_search_element_which_is_absent(){
	int key = 20;
	int arr[] = {10,30,50,70,90};
	ConstVoidPtr result;
	result = bsearch(&key,&arr,5,sizeof(int),compareIntegers);
	ASSERT(NULL == result);
};