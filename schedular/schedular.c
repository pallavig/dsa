#include "schedular.h"
#include "D:/workspace/dsa/genericPriorityQueue/pQueue.h"
#include "D:/workspace/dsa/Linked-list/linkedList.h"

int runProcesses(void *pqueue){
	int result=0;
	void* node;
	while(length(pqueue)){
		node = deQueue(pqueue);
		((Process*)((PQueueItem*)node)->pQueueData)->time-=10;
		result++;
		if(((Process*)(((PQueueItem*)node)->pQueueData))->time > 0){
			enQueue(pqueue,((PQueueItem*)node)->pQueueData,((PQueueItem*)node)->priority);
		}
	}
	return result;
};

//handle when time is more
//if one process captures whole cpu time
//each indiviual process should have one assert to count