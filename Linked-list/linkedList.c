#include "linkedList.h"
#include <stdlib.h>

List* create() {
	List* list = calloc(1,sizeof(List));
	list->head = NULL;
	list->length = 0;
	return list;
};

int insertAtBeginning(Node* node,Node* nodeToInsert,List* list){
	nodeToInsert->next = node;
	node->previous = nodeToInsert;
	list->head = nodeToInsert;
	return 1;
};

int insertAtSpecifiedIndex(Node* node,Node* nodeToInsert,List* list){
	nodeToInsert->previous = node;
	nodeToInsert->next = node->next;
	node->next = nodeToInsert;
	if(nodeToInsert->next!=NULL)
		node->next->previous = nodeToInsert;
	return 1;
};

int insert(List* list,void* element,int index){
	int i;
	Node* nodeToInsert = calloc(1,sizeof(Node));
	Node* node = list->head;
	Node* nextNode;
	nodeToInsert->data = element;
	if((index <= 0 )|| (index >(list->length+1)))  return 0;
	list->length++;
	if(list->head == NULL){
		list->head = nodeToInsert;
		return 1;
	}
	for(i=1;i<index-1;i++)
		node = node->next;
	if(index == 1)
		return insertAtBeginning(node,nodeToInsert,list);
	return insertAtSpecifiedIndex(node,nodeToInsert,list);
};

Node* setLinksToNULL(Node* node){
	node->previous = NULL;
	node->next = NULL;
	return node;
}

Node* remove(List *list, int index){
	int i;
	Node* nodeToDelete;
	Node* node;
	nodeToDelete = list->head;
	if(index<=0 || (!nodeToDelete)) return NULL;
	for(i=1;i<index;i++)
		nodeToDelete = nodeToDelete->next;
	if(NULL == nodeToDelete->previous){
		list->head = nodeToDelete->next;
		return setLinksToNULL(nodeToDelete);
	}
	node = nodeToDelete->previous;
	node->next = nodeToDelete->next;
	if(node->next!=NULL)
		node->next->previous = node;
	return setLinksToNULL(nodeToDelete);
};

void dispose(List* list){
	int i;
	Node *node = list->head;
	Node *nodeToDelete;
	while(node!=NULL){
		nodeToDelete = node;
		list->head = node->next;
		setLinksToNULL(nodeToDelete);
		free(nodeToDelete->data);
		free(nodeToDelete);
		node = list->head;
	}
	list->head = NULL;
};

int length(List* list){
	return list->length;
};