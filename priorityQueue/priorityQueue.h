typedef struct node {
	char name[10];
	struct node* next;
	int priority;
	int time;
	int attempts;
} Node;
typedef struct {
	Node* head;
	int length;
} pQueue;

pQueue* create();
void insert(pQueue* pqueue,char* name,int priority,int time,int attempts);
Node* remove(pQueue* pqueue);