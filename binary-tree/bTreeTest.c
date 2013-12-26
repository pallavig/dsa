#include "testUtils.h"
#include "bTree.h"
#include <string.h>
#include "bTreePrivate.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmpInt(void* first,void* second){
	return *(int*)first - *(int*)second;
};

void test_inserting_first_element(){
	int res;
	BinaryTree tree = createBinaryTree(cmpInt);
	int element1 = 10;
	res = insert(&tree,&element1,NULL);
	ASSERT(res == 1);
}

void test_inserting_elements_at_depth_two(){
	BinaryTree tree = createBinaryTree(cmpInt);
	int res;
	int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
	insert(&tree,&element1,NULL);
	insert(&tree,&element2,&element1);
	insert(&tree,&element3,&element1);
	res = insert(&tree,&element4,&element1);
	ASSERT(res == 0);
	ASSERT(&element2 == getLeft(&tree,&element1));
	ASSERT(&element3 == getRight(&tree,&element1));
};

void test_inserting_two_childrens_at_depth_two(){
	BinaryTree tree = createBinaryTree(cmpInt);
	int element1  = 10,element2 = 20,element3 = 30,element4 = 40,element5 = 50;
	BinaryTreeNode *node;
	insert(&tree,&element1,NULL);
	insert(&tree,&element2,&element1);
	insert(&tree,&element3,&element1);
	insert(&tree,&element4,&element2);
	insert(&tree,&element5,&element2);
	ASSERT(&element2 == getLeft(&tree,&element1));
	ASSERT(&element3 == getRight(&tree,&element1));
	ASSERT(&element4 == getLeft(&tree,&element2));
	ASSERT(&element5 == getRight(&tree,&element2));
};

void test_adding_childs_to_right_child_of_root(){
	BinaryTree tree = createBinaryTree(cmpInt);
	int element1  = 10,element2 = 20,element3 = 30,element4 = 40,element5 = 50;
	BinaryTreeNode *node;
	insert(&tree,&element1,NULL);
	insert(&tree,&element2,&element1);
	insert(&tree,&element3,&element1);
	insert(&tree,&element4,&element3);
	insert(&tree,&element5,&element3);
	ASSERT(&element2 == getLeft(&tree,&element1));
	ASSERT(&element3 == getRight(&tree,&element1));
	printf("-->%p",((BinaryTreeNode*)tree.root)->right->left);
	// ASSERT(&element4 == getLeft(&tree,&element3));
	// ASSERT(&element5 == getRight(&tree,&element3));
};