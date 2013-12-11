#include "priorityQueue.h"
#include <string.h>
#include <stdlib.h>
pQueue* create(){
	pQueue* pqueue = calloc(1,sizeof(pQueue));
	return pqueue;
};

Node* createNode(char* name,int priority,int time,int attempts){
	Node* node = calloc(1,sizeof(Node));
	node->attempts = 0;
	strcpy(node->name,name);
	node->priority = priority;
	node->time = time;
	node->attempts = attempts;
	return node;
}

void insertAtBeginning(Node* nodeToInsert,Node* node,pQueue* pqueue){
	nodeToInsert->next = node;
	pqueue->head = nodeToInsert;
}

void insertAfterSpecifiedNode(Node* nodeToInsert,Node* node,pQueue* pqueue){
	nodeToInsert->next = node->next;
	node->next = nodeToInsert;	
}

void insert(pQueue* pqueue,char* name,int priority,int time,int attempts){
	Node* node,*pv;
	Node* nodeToInsert = createNode(name,priority,time,attempts);
	if(NULL == pqueue->head){
		pqueue->head = nodeToInsert; pqueue->length++;
		return;
	}
	node = pqueue->head;
	while(node!=NULL){
		if(node->priority < nodeToInsert->priority)
			break;
		if(node->priority == nodeToInsert->priority){
			insertAfterSpecifiedNode(nodeToInsert,node,pqueue);
			return;
		}
		pv = node;
		node = node->next;
	}
	if(node == NULL){
		node = pv;
		insertAtBeginning(nodeToInsert,node,pqueue);
		return;
	}
	insertAfterSpecifiedNode(nodeToInsert,node,pqueue);
	return;
}

Node* remove(pQueue *pqueue){
	Node* node;
	node = pqueue->head;
	pqueue->head = pqueue->head->next;
	node->next = NULL;
	return node;
}