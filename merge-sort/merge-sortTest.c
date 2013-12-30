#include "testUtils.h"
#include "merge-sort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInts(void *first,void *second){
	return *(int*)first - *(int*)second;
}

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