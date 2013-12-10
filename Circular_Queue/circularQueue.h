#include <stdlib.h>
#include <string.h>
typedef struct {
	void* base;
	int front;
	int rear;
	int queueCapacity;
	int typeSize;	
} CircularQueue;

typedef char String[256];

CircularQueue* create(int typeSize,int queueCapacity);
int enQueue(CircularQueue* cQueue,void* element);
int isFull(CircularQueue* cQueue);
void* deQueue(CircularQueue* cQueue);
int isEmpty(CircularQueue* cQueue);