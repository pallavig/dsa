typedef struct {
	void** base;
	int top;
	int size;
} Stack;

typedef char String[256];
Stack* create(int size);
int push(Stack* pStack,void* element);
void* pop(Stack *pStack);
void* top(Stack* pStack);
void dispose(Stack* pStack);