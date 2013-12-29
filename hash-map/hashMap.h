#include "D:/workspace/dsa/iterator/iterator.h"
typedef int (*HashCodeGenerator)(void *key);
typedef int (*compareFunc)(void *first,void *second);
typedef struct {
	void *buckets;
	int capacity;
	HashCodeGenerator getHashCode;
	compareFunc compare;
} HashMap;

HashMap createHashMap(HashCodeGenerator getHashCode,compareFunc cmp,int capacity);
int put(HashMap *map,void *key,void *data);
void *getHashObject(HashMap *map,void *key);
int removeHashObject(HashMap *map,void *key);
Iterator keys(HashMap *map);
void disposeHashMap(HashMap *map);