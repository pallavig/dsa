#include "testUtils.h"
#include "linkedList.h"
#include <string.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

List* list;
void* elementToInsert;
int res;

void assignSpaceAndData(int bytes,void* content){
	elementToInsert = calloc(1,bytes);
	memcpy(elementToInsert,content,bytes);
};

void setup(){
	list = create();
};

void teardown(){
	dispose(list);
};

void test_inserting_first_integer_node_in_linked_list(){
	int element = 10;
	assignSpaceAndData(sizeof(int),&element);
	res = insert(list,elementToInsert,1);
	ASSERT(1 == res);
	ASSERT(element == *(int*)getElement(list,1));
};

void test_inserting_first_character_node_in_linked_list(){
	char element = 'a';
	assignSpaceAndData(sizeof(char),&element);
	res = insert(list,elementToInsert,1);
	ASSERT(1 == res);
	ASSERT(element == *(char*)getElement(list,1));
};

void test_inserting_first_float_node_in_linked_list(){
	float element = 10.5f;
	assignSpaceAndData(sizeof(float),&element);
	memcpy(elementToInsert,&element,sizeof(float));
	res = insert(list,elementToInsert,1);
	ASSERT(1 == res);
	ASSERT(element == *(float*)getElement(list,1));
};

void test_inserting_first_double_node_in_linked_list(){
	double element = 10.5;
	assignSpaceAndData(sizeof(double),&element);
	res = insert(list,elementToInsert,1);
	ASSERT(1 == res);
	ASSERT(element == *(double*)getElement(list,1));
};

void test_inserting_first_String_node_in_linked_list(){
	String element = "swamiji";
	assignSpaceAndData(sizeof(String),&element);
	res = insert(list,elementToInsert,1);
	ASSERT(1 == list->length);
	ASSERT(1 == res);
	ASSERT(0 == strcmp(element,*(String*)getElement(list,1)));
};

void test_inserting_two_integer_elements_in_linked_list(){
	void* nodeDeleted;
	int element1 = 20,element2 =40;
	res = insert(list,&element1,1);
	res = insert(list,&element2,2);
	ASSERT(20 == *(int*)getElement(list,1));
	nodeDeleted = remove(list,1);
	ASSERT(20 == *(int*)nodeDeleted);
	ASSERT(40 == *(int*)getElement(list,1));
};

void test_insert_element_in_middle(){
	void* node;
	int element1 = 20,element2 = 40,element3 = 60;
	res = insert(list,&element1,1);
	res = insert(list,&element2,2);
	res = insert(list,&element3,2);
	ASSERT(20 == *(int*)getElement(list,1));
	ASSERT(60 == *(int*)getElement(list,2));
	ASSERT(40 == *(int*)getElement(list,3));
};

void test_insert_at_first_position_in_list(){
	int element1 = 20,element2 = 40;
	res = insert(list,&element1,1);
	res = insert(list,&element2,1);
	ASSERT(40 == *(int*)getElement(list,1));
	ASSERT(20 == *(int*)getElement(list,2));
};

void test_inserting_two_strings(){
	String element1 = "abc",element2 = "def";
	res = insert(list,element2,1);
	res = insert(list,element1,1);
	ASSERT(0 == strcmp(element1,getElement(list,1)));
	ASSERT(0 == strcmp(element2,getElement(list,2)));
}
 
void test_when_index_is_negative_node_should_not_be_inserted(){
	int element = 50;
	res = insert(list,&element,-1);
	ASSERT(0 == res);
};

void test_when_index_exceeds_lists_length_then_insertion_should_fail(){
	int element = 50;
	res = insert(list,&element,2);
	ASSERT(0 == res);
};

void test_deleting_the_char_node_when_only_one_is_present(){
	void* nodeDeleted;
	char element  = 'a';
	res = insert(list,&element,1);
	nodeDeleted = remove(list,1);
	ASSERT(element == *(char*)nodeDeleted);
	ASSERT(0 == list->length);
};

void test_deleting_the_float_node_when_only_one_is_present(){
	void* node;
	float element  = 10.5f;
	res = insert(list,&element,1);
	node = remove(list,1);
	ASSERT(element == *(float*)node);
	ASSERT(0 == list->length);
};

void test_deleting_the_String_node_when_only_one_is_present(){
	void* node;
	String element  = "abc";
	res = insert(list,&element,1);
	node = remove(list,1);
	ASSERT(0 == strcmp(element,node));
	ASSERT(0 == list->length);
};

void test_deleting_first_node_when_two_are_present_in_list(){
	void* node;
	int element1 = 20,element2 = 40;
	res = insert(list,&element1,1);
	res = insert(list,&element2,2);
	node = remove(list,1);
	ASSERT(element1 == *(int*)node);
	ASSERT(element2 == *(int*)getElement(list,1));
	ASSERT(1 == list->length);
 };

void test_deleting_last_node_when_two_are_present_in_list(){
	void* node;
	int element1 = 10,element2 = 20;
	res = insert(list,&element1,1);
	res = insert(list,&element2,2);
	node = remove(list,2);
	ASSERT(element2 == *(int*)node);
	ASSERT(element1 = *(int*)getElement(list,1));
	ASSERT(1 == list->length);
};

void test_deleting_all_nodes(){
	void* node;
	int element1  = 10,element2 = 20,element3 = 30;
	res = insert(list,&element1,1);
	res = insert(list,&element2,2);
	res = insert(list,&element3,3);
	node = remove(list,1);
	ASSERT(element1 == *(int*)node);
	node = remove(list,1);
	ASSERT(element2 == *(int*)node);
	node = remove(list,1);
	ASSERT(element3 == *(int*)node);
};

void test_deleting_second_element_when_three_are_present(){
	int element1  = 10,element2 = 20,element3 = 30;
	void* node;
	Node* secondNode;
	res = insert(list,&element1,1);
	res = insert(list,&element2,2);
	res = insert(list,&element3,3);
	node = remove(list,2);
	ASSERT(element2 == *(int*)node);
	ASSERT(element1 == *(int*)getElement(list,1));
	ASSERT(element3 == *(int*)getElement(list,2));
	ASSERT(2 == length(list));
};

void test_deleting_from_empty_list(){
	int element1 = 100;
	Node* node;
	res = insert(list,&element1,1);
	node = remove(list,1);
	ASSERT(element1 == *(int*)node);
	node = remove(list,1);
	ASSERT(NULL == node);
};

void test_when_negative_index_is_given_to_delete(){
	ASSERT(NULL == remove(list,-1));
};

void test_when_zero_index_is_given_to_delete(){
	ASSERT(NULL == remove(list,0));
};

void test_deletion_from_empty_list_should_return_nothing(){
	ASSERT(NULL == remove(list,1));
}

void test_length_of_empty_linked_list(){
	ASSERT(0 == length(list));
};

void test_length_of_three_node_list(){
	double element1  = 10.5,element2 = 20.5,element3 = 30.5;
	res = insert(list,&element1,1);
	res = insert(list,&element2,2);
	res = insert(list,&element3,3);
	ASSERT(3 == length(list));
};

void test_getting_elements_of_linked_list_for_three_elements(){
	void* result;
	int element1 = 20,element2 = 40,element3 = 60;
	res = insert(list,&element1,1);
	res = insert(list,&element2,2);
	res = insert(list,&element3,3);
	result = getElement(list,1);
	ASSERT(element1 == *(int*)result);
	result = getElement(list,2);
	ASSERT(element2 == *(int*)result);
	result = getElement(list,3);
	ASSERT(element3 == *(int*)result);
};

void test_whether_iterator_gives_next_node(){
	int element1 = 20,element2 = 40,element3 = 60;
	Iterator it;
	void *e1;
	res = insert(list,&element1,1);
	res = insert(list,&element2,2);
	res = insert(list,&element3,3);
	it = getIterator(list);
	res = it.hasNext(&it);
	e1 = it.next(&it);
	ASSERT(1 == res);
	ASSERT(20 == *(int*)e1);
	e1 = it.next(&it);
	ASSERT(40 == *(int*)e1);
	e1 = it.next(&it);
	ASSERT(60 == *(int*)e1);
	e1 = it.next(&it);
	ASSERT(NULL == e1);
};