#include <stdlib.h>
#include "hashMap.h"
#include "D:/workspace/dsa/ArrayList/arrayList.h"
#include "D:/workspace/dsa/Linked-list/linkedList.h"
HashMap createHashMap(HashCodeGenerator getHashCode,compareFunc cmp,int capacity){
	HashMap map;
	int i;
	ArrayList list = createArrayList(capacity);
	map.getHashCode = getHashCode;
	map.compare = cmp;
	map.buckets = calloc(1,sizeof(ArrayList));
	*(ArrayList*)map.buckets = list;
	for(i=0;i<capacity;i++)
		((ArrayList*)map.buckets)->base[i] = create();
	map.capacity = capacity;
	return map;
};

int put(HashMap *map,void *key,void *data){
	int hash = map->getHashCode(key) % map->capacity;
	return 1;
}