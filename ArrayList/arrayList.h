#include "d:/workspace/dsa/iterator/iterator.h"
typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;
typedef int (*CompareFunc)(void* first,void* second);

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);
int add(ArrayList *list,void *data);
int remove(ArrayList *list,int index);
int search(ArrayList *list,void* data,CompareFunc cmp);

int getLength(ArrayList *list);
void* get(ArrayList *list, int index);

Iterator getIterator(ArrayList *list);

void dispose(ArrayList *list);