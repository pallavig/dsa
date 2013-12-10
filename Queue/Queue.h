#include <stdlib.h>
#include <string.h>
typedef struct {
	void* base;
	int rear;
	int queueCapacity;
	int elementSize;	
} Queue;

typedef char String[256];

Queue* create(int elementSize,int queueCapacity);
int enQueue(Queue* queue,void* element);
void* deQueue(Queue* queue);
void dispose(Queue* queue);
int isFull(Queue* queue);
int isEmpty(Queue* queue);