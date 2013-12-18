typedef struct {
	void* pQueueData;
	int priority;
} PQueueItem;
void enQueue(void* pqueue,void* data,int priority);
void* deQueue(void* pqueue);