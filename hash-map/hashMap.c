#include <stdlib.h>
#include "hashMap.h"
#include "D:/workspace/dsa/ArrayList/arrayList.h"
#include "D:/workspace/dsa/Linked-list/linkedList.h"

typedef struct {
	void *key;
	void *values;
} Object;

Object* createObject(void *key,void *values){
	Object *object = calloc(1,sizeof(Object));
	object->key = key;
	object->values = values;
	return object;
};

int calculateHash(HashMap *map,void *key){
	int hashcode = map->getHashCode(key);
	return hashcode % map->capacity;
};

HashMap createHashMap(HashCodeGenerator getHashCode,compareFunc cmp,int capacity){
	HashMap map;
	int i;
	ArrayList listOfBuckets = createArrayList(capacity);
	map.getHashCode = getHashCode;
	map.compare = cmp;
	map.buckets = calloc(1,sizeof(ArrayList));
	*(ArrayList*)map.buckets = listOfBuckets;
	for(i=0;i<capacity;i++)
		((ArrayList*)map.buckets)->base[i] = create();
	map.capacity = capacity;
	return map;
};

int put(HashMap *map,void *key,void *value){
	List *listOfHashObjects;
	Object *objectPrevoiuslyPresent,*object;
	int hash;
	objectPrevoiuslyPresent = getHashObject(map,key);
	if(objectPrevoiuslyPresent) objectPrevoiuslyPresent->values = value;
	object = createObject(key,value);
	hash = calculateHash(map,key);
	listOfHashObjects = ((ArrayList*)map->buckets)->base[hash];
	insert(listOfHashObjects,object,1);
	return 1;
};

void* getHashObject(HashMap *map,void *key){
	List *list;
	Object *object;
	Iterator it;
	int hash = calculateHash(map,key);
	list = ((ArrayList*)map->buckets)->base[hash];
	it = getIterator(list);
	while(it.hasNext(&it)){
		object = it.next(&it);
		if(map->compare(object->key,key))
			return object->values;
	}
	return NULL;
};

int removeHashObject(HashMap *map,void *key){
	List *list;
	Object *object;
	Iterator it;
	int index = 1;
	int hash = calculateHash(map,key);
	list = ((ArrayList*)map->buckets)->base[hash];
	it = getIterator(list);
	while(it.hasNext(&it)){
		object = it.next(&it);
		if(map->compare(object->key,key)){
			remove(list,index);
			return 1;
		}
		index++;
	}
	return 0;
};