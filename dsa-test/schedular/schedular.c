#include "schedular.h"
#include <stdlib.h>

pQueue* runProcesses(pQueue* pqueue){
	Node* node;
	pQueue* result = create();
	while(pqueue->head){
		node = remove(pqueue);
		node->time = node->time - 10;
		node->attempts++;
		if(node->time > 0)
			insert(pqueue,node->name,node->priority,node->time,node->attempts);
		else
			insert(result,node->name,node->priority,node->time,node->attempts);
		free(node);
	}
	return result;
};