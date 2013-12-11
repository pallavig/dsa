#include "testUtils.h"
#include "schedular.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_process_schedular(){
	pQueue* pqueue = create();
	pQueue* result;
	insert(pqueue,"browser",1,10,0);
	insert(pqueue,"gcc",3,20,0);
	result = runProcesses(pqueue);
	ASSERT(result->head->attempts == 1);
	ASSERT(result->head->next->attempts == 2);
	free(pqueue);
	free(result);
};