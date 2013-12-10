#include "Queue.h"

Queue* create(int elementSize, int queueCapacity){
	Queue* queue = calloc(1,sizeof(Queue));
	queue->rear = -1;
	queue->base = calloc(queueCapacity,elementSize);
	queue->elementSize = elementSize;
	queue->queueCapacity = queueCapacity;
	return queue;
};

void* getElement(Queue* queue){
	return queue->base+(queue->elementSize*queue->rear);
};

int isFull(Queue* queue){
	return (queue->rear == queue->queueCapacity-1);
}

int enQueue(Queue* queue,void* element){
	if(isFull(queue))
		return 0;
	queue->rear++;
	memcpy(getElement(queue),element,queue->elementSize);
	return 1;
};

int isEmpty(Queue* queue){
	return queue->rear == (-1);
}

void* deQueue(Queue *queue){
	void* firstElement;
	if(isEmpty(queue)) return NULL;
	firstElement = malloc(queue->elementSize);
	memcpy(firstElement,queue->base,queue->elementSize);
	memmove(queue->base,queue->base+queue->elementSize,(queue->queueCapacity-1)*queue->elementSize);	
	queue->rear--;
	return firstElement;	
};

void dispose(Queue* queue){
	free(queue->base);
	free(queue);
}