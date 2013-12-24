#include <stdlib.h>
#include "testUtils.h"
#include "arrayList.h"
#include <string.h>

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
	int id;
	char* name;
	int age;
} Intern;

int compareStruct(void* first,void* second){
	Intern *intern1 = (Intern*)first, *intern2 = (Intern*)second;	
	return (intern1->age == intern2->age) &&
		(intern1->id == intern2->id) && 
		(0 == strcmp(intern1->name,intern2->name));
};

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};	
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 2;	
	interns = create(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	dispose(internsPtr);	
}

void test_insert_element(){
	int result = insert(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;

	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &ji);

	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));

	dispose(listPtr);		
}

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&tanbirka == get(internsPtr, 1));
	ASSERT(&ji == get(internsPtr, 2));
}

void test_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}

void test_removing_element(){
	int result;
	insert(internsPtr, 0, &prateek);
	result = remove(internsPtr,0);
	ASSERT(SUCCESS == result);
	ASSERT(0 == getLength(internsPtr));
	ASSERT(NULL == get(internsPtr,0));
};

void test_removing_element_from_last(){
	int result;
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	result = remove(internsPtr,1);
	ASSERT(1 == getLength(internsPtr));
	ASSERT(NULL == get(internsPtr,1));
	ASSERT(&prateek == get(internsPtr,0));
};

void test_removing_from_between(){
	int result;
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 2, &tanbirka);
	result = remove(internsPtr,1);
	ASSERT(SUCCESS == result);
	ASSERT(&prateek == get(internsPtr,0));
	ASSERT(&tanbirka == get(internsPtr,1));
	ASSERT(NULL == get(internsPtr,2));
};

void test_removing_element_beyond_capacity_should_fail(){
	int result;
	insert(internsPtr, 0, &prateek);
	result = remove(internsPtr,1);
	ASSERT(FAILURE == result);
};

void test_removing_element_from_negative_index_should_fail(){
	int result;
	result = remove(internsPtr,-1);
	ASSERT(FAILURE == result);
};

void removing_when_list_is_null(){
	int result;
	result = remove(NULL,0);
	ASSERT(FAILURE == result);	
};

void test_adding_record_at_end(){
	int result;
	result = add(internsPtr,&prateek);
	ASSERT(&prateek == get(internsPtr,0));
	ASSERT(SUCCESS == result);
};

void test_adding_when_list_is_null(){
	int result;
	result = add(NULL,&prateek);
	ASSERT(FAILURE == result);
};

void test_searching_element(){
	int result;	
	insert(internsPtr, 0, &prateek);
	result = search(internsPtr,&prateek,compareStruct);
	ASSERT(0 == result);
};

void test_searching_middle_element(){
	int result;
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 2, &tanbirka);
	result = search(internsPtr,&ji,compareStruct);
	ASSERT(1 == result);
};

void test_searching_absent_element_should_fail(){
	int result;
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	result = search(internsPtr,&tanbirka,compareStruct);
	ASSERT(-1 == result);
};

void test_searching_when_list_is_null_should_fail(){
	int result;
	result = search(NULL,&prateek, compareStruct);
	ASSERT(-1 == result);
};

void test_getting_iterator_of_list(){
	Iterator it;
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	it = getIterator(internsPtr);
	ASSERT(1 == it.hasNext(&it));
};

void test_getting_next_element_through_iterator(){
	Iterator it;
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	it = getIterator(internsPtr);
	ASSERT(&prateek == it.next(&it));
	ASSERT(&ji == it.next(&it));
};