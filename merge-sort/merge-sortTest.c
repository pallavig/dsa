#include "testUtils.h"
#include "merge-sort.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
	int number;
	char ch;
} Simple;

int compareInts(void *first,void *second){
	return *(int*)first - *(int*)second;
};

int compareChars(void *first,void *second){
	return *(char*)first - *(char*)second;
};

int compareFloats(void *first,void *second){
	return *(float*)first - *(float*)second;
};

int compareDoubles(void *first,void *second){
	return *(double*)first - *(double*)second;
};

int compareStruct(void* element1,void* element2){
	return ((Simple*)element1)->number - ((Simple*)element2)->number;
};

void test_sorting_two_elements_with_merge_sort(){
	int elements[] = {3,2},sortedElements[] = {2,3};
	void *elementsToSort[] = {&elements[0],&elements[1]};
	mSort(elementsToSort,2,compareInts);
	ASSERT(sortedElements[0] == *(int*)elementsToSort[0]);
	ASSERT(sortedElements[1] == *(int*)elementsToSort[1]);
};

void test_sorting_four_elements_with_merge_sort(){
	int elements[] = {2,3,4,1},sortedElements[] = {1,2,3,4};
	void *elementsToSort[] = {&elements[0],&elements[1],&elements[2],&elements[3]};
	mSort(elementsToSort,4,compareInts);
	ASSERT(sortedElements[0] == *(int*)elementsToSort[0]);
	ASSERT(sortedElements[1] == *(int*)elementsToSort[1]);
	ASSERT(sortedElements[2] == *(int*)elementsToSort[2]);
	ASSERT(sortedElements[3] == *(int*)elementsToSort[3]);
};

void test_sorting_three_elements(){
	int elements[] = {3,2,1},sortedElements[] = {1,2,3};
	void *elementsToSort[] = {&elements[0],&elements[1],&elements[2]};
	mSort(elementsToSort,3,compareInts);
	ASSERT(sortedElements[0] == *(int*)elementsToSort[0]);
	ASSERT(sortedElements[1] == *(int*)elementsToSort[1]);
	ASSERT(sortedElements[2] == *(int*)elementsToSort[2]);
};

void test_sorting_five_elements(){
	int elements[] = {2,3,4,5,1},sortedElements[] = {1,2,3,4,5};
	void *elementsToSort[] = {&elements[0],&elements[1],&elements[2],&elements[3],&elements[4]};
	mSort(elementsToSort,5,compareInts);
	ASSERT(sortedElements[0] == *(int*)elementsToSort[0]);
	ASSERT(sortedElements[1] == *(int*)elementsToSort[1]);
	ASSERT(sortedElements[2] == *(int*)elementsToSort[2]);
	ASSERT(sortedElements[3] == *(int*)elementsToSort[3]);	
	ASSERT(sortedElements[4] == *(int*)elementsToSort[4]);	
};

void test_sorting_characters(){
	char elements[] = {'b','a','d','c'},sortedElements[] = {'a','b','c','d'};
	void *elementsToSort[] = {&elements[0],&elements[1],&elements[2],&elements[3]};
	mSort(elementsToSort,4,compareChars);
	ASSERT(sortedElements[0] == *(char*)elementsToSort[0]);
	ASSERT(sortedElements[1] == *(char*)elementsToSort[1]);
	ASSERT(sortedElements[2] == *(char*)elementsToSort[2]);
	ASSERT(sortedElements[3] == *(char*)elementsToSort[3]);	
};

void test_sorting_floats(){
	float elements[] = {10.5f,11.5f,1.5f,2.5f},sortedElements[] = {1.5f,2.5f,10.5f,11.5f};
	void *elementsToSort[] = {&elements[0],&elements[1],&elements[2],&elements[3]};
	mSort(elementsToSort,4,compareFloats);
	ASSERT(sortedElements[0] == *(float*)elementsToSort[0]);
	ASSERT(sortedElements[1] == *(float*)elementsToSort[1]);
	ASSERT(sortedElements[2] == *(float*)elementsToSort[2]);
	ASSERT(sortedElements[3] == *(float*)elementsToSort[3]);		
};

void test_sorting_doubles(){
	double elements[] = {10.5,11.5,1.5,2.5},sortedElements[] = {1.5,2.5,10.5,11.5};
	void *elementsToSort[] = {&elements[0],&elements[1],&elements[2],&elements[3]};
	mSort(elementsToSort,4,compareDoubles);
	ASSERT(sortedElements[0] == *(double*)elementsToSort[0]);
	ASSERT(sortedElements[1] == *(double*)elementsToSort[1]);
	ASSERT(sortedElements[2] == *(double*)elementsToSort[2]);
	ASSERT(sortedElements[3] == *(double*)elementsToSort[3]);		
};


void test_sorting_structure(){
	int i;
	Simple *elementsToSort = calloc(3,sizeof(Simple));
	Simple *expected = calloc(3,sizeof(Simple));
	void *base[3];
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
	base[0] = &elementsToSort[0]; 
	base[1] = &elementsToSort[1]; 
	base[2] = &elementsToSort[2];
	mSort(base,3,compareStruct);
	for(i=0;i<3;i++){
		ASSERT(expected[i].number == (*(Simple*)base[i]).number);
		ASSERT(expected[i].ch == (*(Simple*)base[i]).ch);
	}
};

void test_sorting_duplicate_elements(){
	int length = 5;
	int elementsToSort[] = {5,4,3,1,1},sortedElements[] = {1,1,3,4,5},i;
	void* base[5] = {&elementsToSort[0],&elementsToSort[1],&elementsToSort[2],&elementsToSort[3],&elementsToSort[4]};
	mSort(base,5,compareInts);
	for(i=0;i<length;i++)
		ASSERT(sortedElements[i] == *(char*)base[i]);
};