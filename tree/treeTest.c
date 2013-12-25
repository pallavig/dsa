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
	Iterator it;
	int element1 =10;
	ASSERT(1 == insertTreeNode(&tree,NULL,&element1));
	it = getChildren(&tree,NULL);
	element = it.next(&it);
	ASSERT(*(int*)element == element1);
	it = getChildren(&tree,&element1);
	traverse(&tree,&it);
};

void test_inserting_two_nodes_one_root_and_its_child(){
	Tree tree = createTree(cmpInt);
	void* element;
	Iterator it;
	TreeNode *treenode;
	int element1 = 10,element2 = 20;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	it = getChildren(&tree,&element1);
	ASSERT(element2 == *(int*)((TreeNode*)it.next(&it))->data);
	it = getChildren(&tree,&element1);
	traverse(&tree,&it);
};

void test_inserting_three_nodes_one_after_the_other(){
	Tree tree = createTree(cmpInt);
	void* element;
	Iterator it;
	TreeNode *treenode;
	int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	insertTreeNode(&tree,&element1,&element3);
	insertTreeNode(&tree,&element1,&element4);
	it = getChildren(&tree,&element1);
	ASSERT(element4 == *(int*)((TreeNode*)it.next(&it))->data);
	ASSERT(element3 == *(int*)((TreeNode*)it.next(&it))->data);
	ASSERT(element2 == *(int*)((TreeNode*)it.next(&it))->data);
	it = getChildren(&tree,&element1);
	traverse(&tree,&it);
};

