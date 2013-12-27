typedef int (*HashCodeGenerator)(void *key);
typedef int (*compareFunc)(void *first,void *second);
typedef struct {
	void* buckets;
	int capacity;
	HashCodeGenerator getHashCode;
	compareFunc compare;
} HashMap;

HashMap createHashMap(HashCodeGenerator getHashCode,compareFunc cmp,int capacity);
int put(HashMap *map,void *key,void *data);