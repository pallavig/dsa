#include "testUtils.h"
#include "BSTree.h"
#include "../customTypes.h"
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

#define SUCCESS 1

int compareInt(void* element1, void* element2){
	return *(int*)element1 - *(int*)element2; 
};

// typedef struct {
// 	int number;
// 	char ch;
// } Simple;

// int compareFloats(void* element1,void* element2){
// 	return *(float*)element1 - *(float*)element2;
// };
// int compareStruct(void* element1,void* element2){
// 	return ((Simple*)element1)->number - ((Simple*)element2)->number;
// };

int compareCharacters(void* element1,void* element2){
	return *(char*)element1 - *(char*)element2;
};

int compareDoubles(void* element1,void* element2){
	return *(double*)element1 - *(double*)element2;
};

int compareStrings(void * element1,void *element2){
	return strcmp(element1,element2);
};

void test_inserting_first_node(){
	BSTree tree = createBinarySearchTree(compareInt);
	int data = 2;
	ASSERT(insert(&tree,&data));
};

void test_inserts_two_nodes_below_root(){
	BSTree tree = createBinarySearchTree(compareInt);
	int dataOfRoot = 2;
	int dataAtRightOfRoot = 3;
	int dataAtLeftOfRoot = 1;
	ASSERT(insert(&tree,&dataOfRoot));	
	ASSERT(insert(&tree,&dataAtRightOfRoot));
	ASSERT(insert(&tree,&dataAtLeftOfRoot));
};

void test_inserts_four_nodes_below_root(){
	BSTree tree = createBinarySearchTree(compareInt);
	int dataOfRoot = 10;
	int data9 = 9,data8 = 8, data11 = 11, data12 =12,data7 = 7,data13 = 13;
	ASSERT(insert(&tree,&dataOfRoot));
	ASSERT(insert(&tree,&data8));
	ASSERT( 8 == *(int*)getLeft(&tree,&dataOfRoot));
	ASSERT(insert(&tree,&data9));
	ASSERT(9 == *(int*)getRight(&tree,&data8));
	ASSERT(insert(&tree,&data12));
	ASSERT(12 == *(int*)getRight(&tree,&dataOfRoot));
	ASSERT(insert(&tree,&data11));
	ASSERT(11 == *(int*)getLeft(&tree,&data12));
	ASSERT(insert(&tree,&data7));
	ASSERT(7 == *(int*)getLeft(&tree,&data8));
	ASSERT(insert(&tree,&data13));
	ASSERT(13 == *(int*)getRight(&tree,&data12));
};

void test_inserting_character_data(){
	BSTree tree = createBinarySearchTree(compareCharacters);
	char dataA = 'a',dataB = 'b',dataC = 'c',dataD = 'd';
	insert(&tree,&dataC);
	insert(&tree,&dataD);
	insert(&tree,&dataB);
	insert(&tree,&dataA);
	ASSERT(dataD == *(char*)getRight(&tree,&dataC));
	ASSERT(dataB == *(char*)getLeft(&tree,&dataC));
	ASSERT(dataA == *(char*)getLeft(&tree,&dataB));
};

void test_inserting_double_data(){
	BSTree tree = createBinarySearchTree(compareDoubles);
	double data1 = 1.0,data2 = 2.0,data3 = 3.0,data4 = 4.0;
	insert(&tree,&data2);
	insert(&tree,&data1);
	insert(&tree,&data4);
	insert(&tree,&data3);
	ASSERT(data4 == *(double*)getRight(&tree,&data2));
	ASSERT(data1 == *(double*)getLeft(&tree,&data2));
	ASSERT(data3 == *(double*)getLeft(&tree,&data4));
};

void test_inserting_strings(){
	BSTree tree = createBinarySearchTree(compareStrings);
	String data1 = "aaa",data2 = "bbb",data3 = "ccc",data4 = "ddd";
	insert(&tree,&data4);
	insert(&tree,&data2);
	insert(&tree,&data3);
	insert(&tree,&data1);
	ASSERT(0 == compareStrings(data2,getLeft(&tree,&data4)));
	ASSERT(0 == compareStrings(data3,getRight(&tree,&data2)));
	ASSERT(0 == compareStrings(data1,getLeft(&tree,&data2)));
};

void test_inserting_duplicate_record_shouold_fail(){
	BSTree tree = createBinarySearchTree(compareStrings);
	String data1 = "aaa",data2 = "bbb";
	insert(&tree,&data1);
	insert(&tree,&data2);
	ASSERT(0 == insert(&tree,&data2));
};

void test_search_root_node(){
	BSTree tree = createBinarySearchTree(compareInt);
	int dataOfRoot = 10;
	ASSERT(insert(&tree,&dataOfRoot));	
	ASSERT(SUCCESS == search(&tree,&dataOfRoot));
};

void test_search_node_at_depth_one(){
	BSTree tree = createBinarySearchTree(compareDoubles);
	double data1 = 1.0,data2 = 2.0,data3 = 3.0,data4 = 4.0;
	insert(&tree,&data2);
	insert(&tree,&data1);
	insert(&tree,&data4);
	insert(&tree,&data3);
	ASSERT(SUCCESS == search(&tree,&data1));
	ASSERT(SUCCESS == search(&tree,&data4));
	ASSERT(SUCCESS == search(&tree,&data3));
};
