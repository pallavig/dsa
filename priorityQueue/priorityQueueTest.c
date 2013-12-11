#include "testUtils.h"
#include "priorityQueue.h"
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_creation_of_priority_queue(){
	pQueue *pqueue = create();
	ASSERT(NULL == pqueue->head);
	ASSERT(0 == pqueue->length);
};

void test_inserting_first_process(){
	pQueue* pqueue = create();
	insert(pqueue,"gcc",1,10);
	ASSERT(0 == pqueue->head->attempts);
	ASSERT(1 == pqueue->head->priority);
	ASSERT(10 == pqueue->head->time);
	ASSERT(0 == strcmp("gcc",pqueue->head->name));
	ASSERT(NULL == pqueue->head->next);
};

void test_inserting_two_nodes_with_second_of_higher_priority(){
	pQueue* pqueue = create();
	insert(pqueue,"browser",2,10);
	insert(pqueue,"gcc",1,20);
	ASSERT(0 == strcmp(pqueue->head->name,"gcc"));
	ASSERT(0 == pqueue->head->attempts);
	ASSERT(1 == pqueue->head->priority);
	ASSERT(20 == pqueue->head->time);
	ASSERT(0 == strcmp(pqueue->head->next->name,"browser"));
	ASSERT(0 == pqueue->head->next->attempts);
	ASSERT(2 == pqueue->head->next->priority);
	ASSERT(10 == pqueue->head->next->time);
};

void test_inserting_two_nodes_with_second_of_lower_priority(){
	pQueue* pqueue = create();
	insert(pqueue,"browser",1,10);
	insert(pqueue,"gcc",2,20);
	ASSERT(0 == strcmp(pqueue->head->name,"browser"));
	ASSERT(0 == pqueue->head->attempts);
	ASSERT(1 == pqueue->head->priority);
	ASSERT(10 == pqueue->head->time);
	ASSERT(0 == strcmp(pqueue->head->next->name,"gcc"));
	ASSERT(0 == pqueue->head->next->attempts);
	ASSERT(2 == pqueue->head->next->priority);
	ASSERT(20 == pqueue->head->next->time);	
}

void test_inserting_in_between(){
	pQueue* pqueue = create();
	insert(pqueue,"browser",1,10);
	insert(pqueue,"gcc",3,20);
	insert(pqueue,"main",2,30);
	ASSERT(0 == strcmp(pqueue->head->name,"browser"));
	ASSERT(0 == strcmp(pqueue->head->next->name,"main"));
	ASSERT(0 == strcmp(pqueue->head->next->next->name,"gcc"));
};

void test_removing_node(){
	Node* node;
	pQueue* pqueue = create();
	insert(pqueue,"browser",2,10);
	insert(pqueue,"gcc",1,20);
	node = remove(pqueue);
	ASSERT(node->next == NULL);
	ASSERT(0 == strcmp("gcc",node->name));
}