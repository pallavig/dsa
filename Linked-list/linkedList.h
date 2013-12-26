#include "iterator.h"
typedef struct node {
	void* data;
	struct node* next;
	struct node* previous;
} Node;
typedef struct {
	int length;
	void* head;
} List;

typedef char String[256];

List* create();
int insert(List* list,void* element,int index);
void* remove(List* list,int index);
void dispose(List* list);
int length(List* list);
void* getElement(List* list,int index);
Iterator getIterator(List* list);