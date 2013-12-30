#include "testUtils.h"
#include "merge-sort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInts(void *first,void *second){
	return *(int*)first - *(int*)second;
}

void test_sorting_two_elements_with_merge_sort(){
	int elements[] = {3,2},sortedElements[] = {2,3};
	void *elementsToSort[] = {&elements[0],&elements[1]};
	mSort(elementsToSort,0,1,2,compareInts);
	ASSERT(sortedElements[0] == *(int*)elementsToSort[0]);
	ASSERT(sortedElements[1] == *(int*)elementsToSort[1]);
};