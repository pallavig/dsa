#include "circularQueue.h"
CircularQueue* create(int typeSize,int queueCapacity){
	CircularQueue* cQueue = calloc(1,sizeof(CircularQueue));
	cQueue->front = -1;
	cQueue->rear = -1;
	cQueue->queueCapacity = queueCapacity;
	cQueue->typeSize = typeSize;
	cQueue->base = calloc(queueCapacity,typeSize);
	return cQueue;
};

int isFull(CircularQueue* cQueue){
	return cQueue->front == ((cQueue->rear+1) % cQueue->queueCapacity);
};

int getRear(CircularQueue* cQueue){
	return cQueue->rear % cQueue->queueCapacity;
}

int enQueue(CircularQueue* cQueue,void* element){
	int offset;
	if(isFull(cQueue)) return 0;
	if(cQueue->front == (-1)) cQueue->front = 0;
	++cQueue->rear;
	offset = getRear(cQueue) * cQueue->typeSize;
	cQueue->rear = getRear(cQueue);
	memcpy(cQueue->base + offset,element,cQueue->typeSize);
	return 1;
};

void incrementFront(CircularQueue* cQueue){
	cQueue->front = (++cQueue->front) % cQueue->queueCapacity;
};

int isEmpty(CircularQueue* cQueue){
	return cQueue->front == (-1);
};

void* deQueue(CircularQueue* cQueue){
	void* element;
	int firstElementOffset;
	element = calloc(1,cQueue->typeSize);
	firstElementOffset = cQueue->front*cQueue->typeSize;
	if(cQueue->front == cQueue->rear){
		cQueue->front = (-1);
		cQueue->rear = (-1);
	}
	else
	{
		memcpy(element,cQueue->base+firstElementOffset,cQueue->typeSize);
		incrementFront(cQueue);
	}
	return element;
};