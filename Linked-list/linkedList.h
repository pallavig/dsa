struct node {
	void* data;
	struct node* next;
	struct node* previous;
};
typedef struct node Node;
typedef struct {
	int length;
	Node* head;
} List;

typedef char String[256];


List* create();
int insert(List* list,void* element,int index);
Node* remove(List* list,int index);
void dispose(List* list);
int length(List* list);
void* getElement(List* list,int index);