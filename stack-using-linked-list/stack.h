#include "../Linked-list/linkedList.h"
typedef struct {
	List* list;
} Stack;

Stack* createStack();
void push(Stack* stack,void* element);
void* pop(Stack* stack);
void* top(Stack* stack);
void disposeStack(Stack* stack);