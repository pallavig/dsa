#include "testUtils.h"
#include <string.h>
#include "isort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
	int number;
	char ch;
} Simple;

int compareIntegers(void* element1,void* element2){
	return *(int*)element1 - *(int*)element2;
};

int compareIntegersReverse(void* element1,void* element2){
	return *(int*)element2 - *(int*)element1;
};

int compareFloats(void* element1,void* element2){
	return *(float*)element1 - *(float*)element2;
};

int compareCharacters(void* element1,void* element2){
	return *(char*)element1 - *(char*)element2;
};

int compareDoubles(void* element1,void* element2){
	return *(double*)element1 - *(double*)element2;
};

int compareStrings(void* element1,void* element2){
	return strcmp((char*)element1,(char*)element2);
};

int compareStruct(void* element1,void* element2){
	return ((Simple*)element1)->number - ((Simple*)element2)->number;
};

int areEqual(void* element1,void* element2,int bytes){
	return 0 == memcmp(element1,element2,bytes);
};

void test_sorting_five_integers(){
	int elementsToSort[] = {3,2,4,5,1};
	int expected[] = {1,2,3,4,5};
	isort(elementsToSort,5,sizeof(int),compareIntegers);
	ASSERT(areEqual(expected,elementsToSort,sizeof(int)*5));
};

void test_sorting_floats(){
	float elementsToSort[] = {10.5f,11.5f,5.5f,6.5f,12.5f};
	float expected[] = {5.5f,6.5f,10.5f,11.5f,12.5f};
	isort(elementsToSort,5,sizeof(float),compareFloats);
	ASSERT(areEqual(expected,elementsToSort,sizeof(float)*5));
};

void test_sorting_characters(){
	char elementsToSort[] = {'a','e','b','z','y'};
	char expected[] = {'a','b','e','y','z'};
	isort(elementsToSort,5,sizeof(char),compareCharacters);
	ASSERT(areEqual(expected,elementsToSort,sizeof(char)*5));
};

void test_sorting_doubles(){
	double elementsToSort[] = {100.5,200.5,50.5,60.5,1000.5,2000.5};
	double expected[] = {50.5,60.5,100.5,200.5,1000.5,2000.5};
	isort(elementsToSort,6,sizeof(double),compareDoubles);
	ASSERT(areEqual(expected,elementsToSort,sizeof(double)*6));
};

void test_sorting_strings(){
	String elementsToSort[] = {"aaa","eee","bbb","zzz","yyy"};
	String expected[] = {"aaa","bbb","eee","yyy","zzz"};
	isort(elementsToSort,5,sizeof(String),compareStrings);
	ASSERT(areEqual(expected,elementsToSort,sizeof(String)*5));		
};

void test_sorting_already_sorted_elements(){
	char elementsToSort[] = {'a','b','e','y','z'};
	char expected[] = {'a','b','e','y','z'};
	isort(elementsToSort,5,sizeof(char),compareCharacters);
	ASSERT(areEqual(expected,elementsToSort,sizeof(char)*5));
};

void test_sorting_when_elements_are_reversely_sorted(){
	int elementsToSort[] = {5,4,3,2,1};
	int expected[] = {1,2,3,4,5};
	isort(elementsToSort,5,sizeof(int),compareIntegers);
	ASSERT(areEqual(expected,elementsToSort,sizeof(int)*5));	
};

void test_sorting_elements_in_reverse_order(){
	int elementsToSort[] = {1,2,3,4,5};
	int expected[] = {5,4,3,2,1};
	isort(elementsToSort,5,sizeof(int),compareIntegersReverse);
	ASSERT(areEqual(expected,elementsToSort,sizeof(int)*5));	
};

void test_sorting_structure_according_to_numbers(){
		Simple *elementsToSort = calloc(3,sizeof(Simple));
		Simple *expected = calloc(3,sizeof(Simple));
		elementsToSort[0].number = 20;
		elementsToSort[0].ch = 'a';
		elementsToSort[1].number = 12;
		elementsToSort[1].ch = 'b';
		elementsToSort[2].number = 40;
		elementsToSort[2].ch = 'c';
		expected[0].number = 12;
		expected[0].ch = 'b';
		expected[1].number = 20;
		expected[1].ch = 'a';
		expected[2].number = 40;
		expected[2].ch = 'c';
		isort(elementsToSort,3,sizeof(Simple),compareStruct);
		ASSERT(areEqual(expected,elementsToSort,sizeof(Simple)*3));
};