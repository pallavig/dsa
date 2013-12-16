typedef struct {
	void** base;
	int top;
	int size;
} Stack;

typedef char String[256];
void** getElement(Stack* stack,int top);
Stack* create(int size);
int push(Stack* stack,void* element);
void* pop(Stack *stack);