#include "testUtils.h"
#include "merge-sort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInts(void *first,void *second){
	return *(int*)first - *(int*)second;
};

int compareChars(void *first,void *second){
	return *(char*)first - *(char*)second;
};

int compareFloats(void *first,void *second){
	return *(float*)first - *(float*)second;
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