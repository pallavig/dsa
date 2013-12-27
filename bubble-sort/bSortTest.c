#include "testUtils.h"
#include "bSort.h"
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
	int number;
	char ch;
} Simple;

int compareIntegers(void* element1,void* element2){
	return *(int*)element1 - *(int*)element2;
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

int compareStruct(void* element1,void* element2){
	return ((Simple*)element1)->number - ((Simple*)element2)->number;
};

// int areEqual(char **actual,char *expected,int bytes){
// 	int i;
// 	for(i=0;i<bytes;i++){
// 		if(expected[i]!=*(char*)actual[i]){
// 			printf("%c and %c\n",expected[i],*(char*)actual);
// 			return 0;
// 		}
// 	}
// 	return 1;
// };

void test_sorting_five_integers_elements(){
	int length = 5;
	int elementsToSort[] = {5,4,3,2,1},sortedElements[] = {1,2,3,4,5},i;
	void* base[5] = {&elementsToSort[0],&elementsToSort[1],&elementsToSort[2],&elementsToSort[3],&elementsToSort[4]};
	bSort(base,5,compareIntegers);
	// printf("%d",areEqual((char**)base,(char*)sortedElements,5*sizeof(int)));
	for(i=0;i<length;i++)
		ASSERT(sortedElements[i] == *(char*)base[i]);
};

void test_sorting_three_character_elements(){
	char elementsToSort[] = {'a','c','b'},sortedElements[] = {'a','b','c'};
	int i;
	void *base[3] = {&elementsToSort[0],&elementsToSort[1],&elementsToSort[2]};
	bSort(base,3,compareCharacters);
	for(i=0;i<3;i++)
		ASSERT(sortedElements[i] == *(char*)base[i]);
};

void test_sorting_float_elements(){
	float elementToSort[] = {10.5f,1.5f,2.5f,7.5f},sortedElements[] = {1.5f,2.5f,7.5f,10.5f};
	int i;
	void *base[4] = {&elementToSort[0],&elementToSort[1],&elementToSort[2],&elementToSort[3]};
	bSort(base,4,compareFloats);
	for(i=0;i<4;i++)
		ASSERT(sortedElements[i] == *(float*)base[i]);
};

void test_sorting_double_elements(){
	double elementsToSort[] = {10.5,1.5,2.5,7.5},sortedElements[] = {1.5,2.5,7.5,10.5};
	int i;
	void *base[4] = {&elementsToSort[0],&elementsToSort[1],&elementsToSort[2],&elementsToSort[3]};
	bSort(base,4,compareDoubles);
	for(i=0;i<4;i++)
		ASSERT(sortedElements[i] == *(double*)base[i]);	
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
	bSort(base,3,compareStruct);
	for(i=0;i<3;i++){
		ASSERT(expected[i].number == (*(Simple*)base[i]).number);
		ASSERT(expected[i].ch == (*(Simple*)base[i]).ch);
	}
};

void test_inserting_duplicate_elements(){
	int length = 5;
	int elementsToSort[] = {5,4,3,1,1},sortedElements[] = {1,1,3,4,5},i;
	void* base[5] = {&elementsToSort[0],&elementsToSort[1],&elementsToSort[2],&elementsToSort[3],&elementsToSort[4]};
	bSort(base,5,compareIntegers);
	for(i=0;i<length;i++)
		ASSERT(sortedElements[i] == *(char*)base[i]);
};