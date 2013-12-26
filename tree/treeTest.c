#include "testUtils.h"
#include "tree.h"
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmpInt(void* first,void* second){
	return *(int*)first - *(int*)second;
};

void test_inserting_first_node_in_linked_list(){
	Tree tree = createTree(cmpInt);
	Iterator it;
	void *element;
	int element1 =10;
	ASSERT(1 == insertTreeNode(&tree,NULL,&element1));
	it = getChildren(&tree,NULL);
	element = it.next(&it);
	ASSERT(*(int*)element == element1);
	disposeTree(&tree);
};

void test_inserting_two_nodes_one_root_and_its_child(){
	Tree tree = createTree(cmpInt);
	Iterator it;
	int element1 = 10,element2 = 20;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	it = getChildren(&tree,&element1);
	ASSERT(element2 == *(int*)it.next(&it));
	ASSERT(NULL == it.next(&it));
	disposeTree(&tree);
};

void test_inserting_three_nodes_one_after_the_other(){
	Tree tree = createTree(cmpInt);
	Iterator it;
	int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	insertTreeNode(&tree,&element1,&element3);
	insertTreeNode(&tree,&element1,&element4);
	it = getChildren(&tree,&element1);
	ASSERT(element4 == *(int*)it.next(&it));
	ASSERT(element3 == *(int*)it.next(&it));
	ASSERT(element2 == *(int*)it.next(&it));
	disposeTree(&tree);
};

void test_inserting_node_at_depth_two(){
	Tree tree = createTree(cmpInt);
	void * element;
	Iterator it;
	int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	insertTreeNode(&tree,&element2,&element3);
	insertTreeNode(&tree,&element2,&element4);
	it = getChildren(&tree,&element2);
	ASSERT(element4 == *(int*)it.next(&it));
	ASSERT(element3 == *(int*)it.next(&it));
	disposeTree(&tree);
};

void test_searching_root_node(){
	Tree tree = createTree(cmpInt);
	int element1 =10;
	ASSERT(1 == insertTreeNode(&tree,NULL,&element1));
	ASSERT(1 == search(&tree,&element1));
	disposeTree(&tree);
};

void test_searching_nodes_depth_one(){
	Tree tree = createTree(cmpInt);
	int element1 = 10,element2 = 20,element3 = 30;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	insertTreeNode(&tree,&element1,&element3);
	ASSERT(1 == search(&tree,&element2));
	ASSERT(1 == search(&tree,&element3));
	disposeTree(&tree);
};

void test_searching_at_depth_two(){
	Tree tree = createTree(cmpInt);
	int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	insertTreeNode(&tree,&element2,&element3);
	insertTreeNode(&tree,&element2,&element4);
	ASSERT(1 == search(&tree,&element3));
	ASSERT(1 == search(&tree,&element4));
	disposeTree(&tree);
};

void test_removing_leaf_node(){
	Tree tree = createTree(cmpInt);
	int element1 = 10,element2 = 20;
	Iterator it;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	ASSERT(1 == removeTreeNode(&tree,&element2));
	it = getChildren(&tree,&element1);
	ASSERT(NULL == it.next(&it));
	disposeTree(&tree);
};

void test_removing_node_that_is_absent(){
	Tree tree = createTree(cmpInt);
	int element1 = 10,element2 = 20,element3 = 30;
	Iterator it;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	ASSERT(0 == removeTreeNode(&tree,&element3));
	disposeTree(&tree);
};

void test_removing_node_from_depth_two(){
	Iterator it;
	Tree tree = createTree(cmpInt);
	int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	insertTreeNode(&tree,&element2,&element3);
	insertTreeNode(&tree,&element2,&element4);
	ASSERT(1 == removeTreeNode(&tree,&element3));
	it = getChildren(&tree,&element2);
	ASSERT(element4 == *(int*)it.next(&it));
	ASSERT(NULL == it.next(&it));
	disposeTree(&tree);
};

void test_removing_node_that_has_childs_should_fail(){
	Tree tree = createTree(cmpInt);
	int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
	insertTreeNode(&tree,NULL,&element1);
	insertTreeNode(&tree,&element1,&element2);
	ASSERT(0 == removeTreeNode(&tree,&element1));
	disposeTree(&tree);
};

void test_removing_root_node_when_it_has_no_childs(){
	Tree tree = createTree(cmpInt);
	int element1 = 10;
	insertTreeNode(&tree,NULL,&element1);
	ASSERT(1 == removeTreeNode(&tree,&element1));
	ASSERT(0 == search(&tree,&element1));
};