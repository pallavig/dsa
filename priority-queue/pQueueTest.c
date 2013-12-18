#include "testUtils.h"
#include "D:/workspace/dsa/Linked-list/linkedList.h"
#include "pQueue.h"
#include <string.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
	int number;
	char ch;
} Simple;
void* pqueue;


void setup(){
	pqueue = create();
};

void tearDown(){
	dispose(pqueue);
};

void test_inserting_first_item_in_priority_queue(){
	int element = 10;
	enQueue(pqueue,&element,1);
	ASSERT(10 == *(int*)((PQueueItem*)deQueue(pqueue))->pQueueData);
};

void test_inserting_first_char_item_in_priority_queue(){
	char ch = 'a';
	enQueue(pqueue,&ch,1);
	ASSERT('a' == *(char*)((PQueueItem*)deQueue(pqueue))->pQueueData);
};

void test_inserting_float_item(){
	float element = 1.5f;
	enQueue(pqueue,&element,2);
	ASSERT(1.5f == *(float*)((PQueueItem*)deQueue(pqueue))->pQueueData);
};

void test_inserting_struct_item(){
	PQueueItem* deletedElemnt;
	Simple s1 = {10,'a'};
	enQueue(pqueue,&s1,2);
	deletedElemnt = deQueue(pqueue);
	ASSERT(10 == ((Simple*)deletedElemnt->pQueueData)->number);
	ASSERT('a' == ((Simple*)deletedElemnt->pQueueData)->ch);
};

void test_inserting_two_elments_with_second_of_lower_priority(){
	int element1 = 10,element2 = 20;
	PQueueItem* deletedElemnt;
	enQueue(pqueue,&element1,1);
	enQueue(pqueue,&element2,2);
	deletedElemnt = deQueue(pqueue);
	ASSERT(10 == (*(int*)deletedElemnt->pQueueData));
	deletedElemnt = deQueue(pqueue);
	ASSERT(20 == (*(int*)deletedElemnt->pQueueData));
};

void test_inserting_three_elements_with_third_of_higher_priority(){
	PQueueItem* deletedElemnt;
	int element1 = 10,element2 = 20,element3 = 30;
	enQueue(pqueue,&element2,2);
	enQueue(pqueue,&element1,1);
	enQueue(pqueue,&element3,3);
	deletedElemnt = deQueue(pqueue);
	ASSERT(10 == (*(int*)deletedElemnt->pQueueData));
	deletedElemnt = deQueue(pqueue);
	ASSERT(20 == (*(int*)deletedElemnt->pQueueData));
	deletedElemnt = deQueue(pqueue);
	ASSERT(30 == (*(int*)deletedElemnt->pQueueData));
};

void test_inserting_four_elements_in_random_priority_order(){
	PQueueItem* deletedElemnt;
	int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
	enQueue(pqueue,&element2,2);
	enQueue(pqueue,&element1,1);
	enQueue(pqueue,&element4,4);
	enQueue(pqueue,&element3,3);
	deletedElemnt = deQueue(pqueue);
	ASSERT(10 == (*(int*)deletedElemnt->pQueueData));	
	deletedElemnt = deQueue(pqueue);
	ASSERT(20 == (*(int*)deletedElemnt->pQueueData));
	deletedElemnt = deQueue(pqueue);
	ASSERT(30 == (*(int*)deletedElemnt->pQueueData));
	deletedElemnt = deQueue(pqueue);
	ASSERT(40 == (*(int*)deletedElemnt->pQueueData));
};

void test_inserting_nodes_of_same_priority(){
	PQueueItem* deletedElemnt;
	float element1 = 10.5f,element2 = 20.5f,element3 = 30.5f;
	enQueue(pqueue,&element1,2);
	enQueue(pqueue,&element2,2);
	enQueue(pqueue,&element3,1);
	deletedElemnt = deQueue(pqueue);
	ASSERT(30.5f == (*(float*)deletedElemnt->pQueueData));
	deletedElemnt = deQueue(pqueue);
	ASSERT(10.5f == (*(float*)deletedElemnt->pQueueData));
	deletedElemnt = deQueue(pqueue);
	ASSERT(20.5f == (*(float*)deletedElemnt->pQueueData));
};

void test_deleting_double_element_from_pqueue(){
	PQueueItem* deletedElemnt;
	double element1 = 10.5,element2 = 20.5;
	enQueue(pqueue,&element1,2);
	enQueue(pqueue,&element2,1);
	deletedElemnt = deQueue(pqueue);
	ASSERT(20.5 == (*(double*)deletedElemnt->pQueueData));	
	deletedElemnt = deQueue(pqueue);
	ASSERT(10.5 == (*(double*)deletedElemnt->pQueueData));
};

void test_deleting_node_when_pqueue_is_empty(){
	Node* deletedNode;
	deletedNode = deQueue(pqueue);
	ASSERT(NULL == deletedNode);
};