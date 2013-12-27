#include "d:/workspace/dsa/iterator/iterator.h"
typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;
typedef int (*CompareFunc)(void* first,void* second);
typedef void ForEach(void* data);

ArrayList createArrayList(int capacity);
void disposeArrayList(ArrayList *list);

int insertInArrayList(ArrayList *list, int index, void* data);
int addInArrayList(ArrayList *list,void *data);
int removeFromArrayList(ArrayList *list,int index);
int search(ArrayList *list,void* data,CompareFunc cmp);

int getLength(ArrayList *list);
void* get(ArrayList *list, int index);

Iterator getArrayListIterator(ArrayList *list);
void iterate(ArrayList list, ForEach* forEach);