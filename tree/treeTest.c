#include "testUtils.h"
#include "tree.h"
#include <memory.h>
#include "treePrivate.h"
// #include "d:/workspace/dsa/Linked-list/linkedList.h"
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmpInt(void* first,void* second){
	return *(int*)first - *(int*)second;
};

void test_inserting_first_node_in_linked_list(){
	Tree tree = createTree(cmpInt);
	void* element;
	TreeNode *tn;
	Iterator it;
	int element1 =10;
	ASSERT(1 == insertTreeNode(&tree,NULL,&element1));
	it = getChildren(&tree,NULL);
	element = it.next(&it);
	ASSERT(*(int*)element == element1);
	tn = searchTreeNode(&tree,&element1);
	ASSERT(element1 == *(int*)tn->data);
};

void test_inserting_two_nodes_one_root_and_its_child(){
	Tree tree = createTree(cmpInt);
	Iterator it;
	TreeNode *tn;
	int element1 = 10,element2 = 20;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	it = getChildren(&tree,&element1);
	ASSERT(element2 == *(int*)it.next(&it));
	tn = searchTreeNode(&tree,&element2);
	ASSERT(element2 == *(int*)tn->data);
};

void test_inserting_three_nodes_one_after_the_other(){
	Tree tree = createTree(cmpInt);
	Iterator it;
	TreeNode *tn;
	int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	// insertTreeNode(&tree,&element1,&element3);
	// insertTreeNode(&tree,&element1,&element4);
	// it = getChildren(&tree,&element1);
	// ASSERT(element4 == *(int*)it.next(&it));
	tn = searchTreeNode(&tree,&element2);
	ASSERT(element2 == *(int*)tn->data);
};

void test_inserting_node_at_depth_two(){
	Tree tree = createTree(cmpInt);
	void * element;
	Iterator it;
	TreeNode *tn;
	int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	insertTreeNode(&tree,&element2,&element3);
	it = getChildren(&tree,&element2);
	tn = searchTreeNode(&tree,&element2);
	ASSERT(element2 == *(int*)tn->data);
	ASSERT(element3 == *(int*)it.next(&it));
};