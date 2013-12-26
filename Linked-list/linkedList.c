#include "linkedList.h"
#include <stdlib.h>

List* create() {
	List* list = calloc(1,sizeof(List));
	list->head = NULL;
	list->length = 0;
	return list;
};

Node* createNode(void* data){
	Node* node = calloc(1,sizeof(Node));
	node->data = data;
	return node;
};

int insertAtBeginning(Node* nodeToInsert,List* list){
	list->length++;
	nodeToInsert->next = list->head;
	((Node*)(list->head))->previous = nodeToInsert;
	list->head = nodeToInsert;
	return 1;
};

int insertAtSpecifiedIndex(Node* node,Node* nodeToInsert,List* list){
	list->length++;
	nodeToInsert->previous = node;
	nodeToInsert->next = node->next;
	node->next = nodeToInsert;
	if(nodeToInsert->next!=NULL)
		nodeToInsert->next->previous = nodeToInsert;
	return 1;
};


int insert(List* list,void* element,int index){
	int i;
	Node* nodeToInsert = createNode(element);
	Node* nextNode;
	Node* node = list->head;
	void* result;
	if((index <= 0 )|| (index >(list->length+1)))  return 0;
	if(list->head == NULL){
		list->length++;
		list->head = nodeToInsert;
		return 1;
	}
	for(i=1;i<index-1;i++)
		node = node->next;
	if(index == 1)
		return insertAtBeginning(nodeToInsert,list);
	return insertAtSpecifiedIndex(node,nodeToInsert,list);
};

Node* setLinksToNULL(Node* node){
	node->previous = NULL;
	node->next = NULL;
	return node;
};

Node* removeFromBeginning(List* list){
	Node* nodeToDelete = list->head;
	list->head = nodeToDelete->next;
	if(nodeToDelete->next)
		nodeToDelete->next->previous = NULL;
	return setLinksToNULL(nodeToDelete);
};

Node* removeNode(Node* nodeToDelete){
	Node* node;
	node = nodeToDelete->previous;
	node->next = nodeToDelete->next;
	if(node->next!=NULL)
		node->next->previous = node;
	return setLinksToNULL(nodeToDelete);
};

void* remove(List *list, int index){
	int i;
	Node* nodeToDelete;
	void* data;
	nodeToDelete = list->head;
	if(index<=0 || (!nodeToDelete)) return NULL;
	for(i=1;i<index;i++)
		nodeToDelete = nodeToDelete->next;
	list->length--;
	if(NULL == nodeToDelete->previous){
		data = removeFromBeginning(list)->data;
		free(nodeToDelete);
		return data;
	}
	data = removeNode(nodeToDelete)->data;
	free(nodeToDelete);
	return data;
	// return data;
};

void* getElement(List* list,int index){
	int i;
	Node* node;
	node = list->head; 
	for(i=1;(i<index);i++){
		node = node->next;
		if(node == NULL)
			break;
	}
	return node->data;
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

int hasCurrent(Iterator* it){
	return ((Node*)(it->current)) != NULL;
};

void* current(Iterator* it){
	void* result = NULL;
	if(it->hasNext(it)){
		result = ((Node*)(it->current))->data;
		it->current = ((Node*)(it->current))->next;
	}
	return result;
};

Iterator getIterator(List* list){
	Iterator it;
	if(list==NULL) it.current = NULL;
	else it.current = list->head;
	it.list = list;
	it.hasNext = hasCurrent;
	it.next = current;
	return it;
};