typedef struct {
	void* base;
	int top;
	int size;
	int typeSize;
} Stack;

typedef char String[256];

int isFull(Stack* stack);
int isEmpty(Stack* stack);

Stack* New(int typeSize,int size);
int push(Stack* stack,void* element);
void* pop(Stack* stack);
void* top(Stack* stack);