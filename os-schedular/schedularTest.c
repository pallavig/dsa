#include "testUtils.h"
#include "schedular.h"
#include "D:/workspace/dsa/priority-queue/pQueue.h"
#include "D:/workspace/dsa/Linked-list/linkedList.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_process_schedular_with_only_one_process_running(){
	void* pqueue = create();
	int result;
	Process p1 = {"browser",20};
	enQueue(pqueue,&p1,1);
	result = runProcesses(pqueue);
	ASSERT(2 == result);
	dispose(pqueue);
};

void test_process_schedular_with_two_processes_running(){
	void* pqueue = create();
	int result;
	Process p1 = {"browser",20};
	Process p2 = {"gcc",30};
	enQueue(pqueue,&p1,1);
	enQueue(pqueue,&p2,2);
	result = runProcesses(pqueue);
	ASSERT(5 == result);
	dispose(pqueue);
};

void test_process_schedular_with_two_processes_of_same_priority(){
	void* pqueue = create();
	int result;
	Process p1 = {"browser",20};
	Process p2 = {"gcc",30};
	enQueue(pqueue,&p1,1);
	enQueue(pqueue,&p2,1);
	result = runProcesses(pqueue);
	ASSERT(5 == result);
};

void test_process_schedular_with_four_processes(){
	void* pqueue = create();
	int result;
	Process p1 = {"browser",20};
	Process p2 = {"gcc",30};
	Process p3 = {"node",10};
	Process p4 = {"subwlime",40};
	enQueue(pqueue,&p1,1);
	enQueue(pqueue,&p2,2);
	enQueue(pqueue,&p3,1);
	enQueue(pqueue,&p4,2);
	result = runProcesses(pqueue);
	ASSERT(10 == result);
};