#include "pQueue.h"
#include "D:/workspace/dsa/Linked-list/linkedList.h"
#include <stdlib.h>
Node* result;
typedef void* (*comparePriorityFunc)(Node* node,Node* result);

PQueueItem* createPQItem(void* data,int priority){
	PQueueItem* pQueueItem = calloc(1,sizeof(PQueueItem));
	pQueueItem->pQueueData = data;
	pQueueItem->priority = priority;
	return pQueueItem;
};

int compareByPriority(void* dataToInsert,void* dataOfNode){
	return ((PQueueItem*)dataOfNode)->priority <= ((PQueueItem*)dataToInsert)->priority;
};

void enQueue(void* pqueue,void* data,int priority){
	int i,res;
	PQueueItem* pQueueItem = createPQItem(data,priority);
	for(i=1;i<=length(pqueue);i++){
		res = compareByPriority(pQueueItem,getElement(pqueue,i));
		if(res==0)
			break;
	}
	insert(pqueue,pQueueItem,i);
};

void* deQueue(void* pqueue){
	void* deletedElement;
	deletedElement = remove(pqueue,1);
	return (deletedElement)?((Node*)deletedElement)->data:NULL;
};