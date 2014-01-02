#include "testUtils.h"
#include "BSTree.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* element1, void* element2){
	return *(int*)element1 - *(int*)element2; 
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