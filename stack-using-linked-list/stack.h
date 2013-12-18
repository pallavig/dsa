#include "../Linked-list/linkedList.h"
typedef struct {
	List* list;
} Stack;

Stack* createStack();
void push(Stack* stack,void* element);
Node* pop(Stack* stack);
Node* top(Stack* stack);
void disposeStack(Stack* stack);