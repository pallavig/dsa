#include <stdlib.h>
#include "hashMap.h"
#include "D:/workspace/dsa/ArrayList/arrayList.h"
#include "D:/workspace/dsa/Linked-list/linkedList.h"

typedef struct {
	void *key;
	void *values;
} Object;

typedef struct {
	int bucketNumber;
	Iterator listIterator;
	HashMap map;
} IteratorPosition;

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
	List *listOfHashObjects;
	ArrayList listOfBuckets = createArrayList(capacity);
	map.getHashCode = getHashCode;
	map.compare = cmp;
	map.capacity = capacity;
	map.buckets = calloc(1,sizeof(ArrayList));
	*(ArrayList*)map.buckets = listOfBuckets;
	for(i=0;i<capacity;i++)
		addInArrayList(map.buckets, create());
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
	listOfHashObjects = get(map->buckets,hash);//((ArrayList*)map->buckets)->base[hash];
	insert(listOfHashObjects,object,1);
	return 1;
};

void* getHashObject(HashMap *map,void *key){
	List *list;
	Object *object;
	Iterator it;
	int hash = calculateHash(map,key);
	list = get(map->buckets,hash);
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

void* hashMapCurrent(Iterator *it){
	IteratorPosition *ip = it->current;
	Iterator listIterator = ip->listIterator;
	void *result = NULL;
	if(listIterator.hasNext(&listIterator)){
		result = listIterator.next(&listIterator);
		return ((Object*)result)->values;
	}
	return NULL;
};

int hashMapHasCurrent(Iterator *it){
	IteratorPosition *ip = it->current;
	Iterator listIerator;
	List *listOfHashElements;

	while(ip->bucketNumber < ip->map.capacity){
		if(ip->listIterator.hasNext(&ip->listIterator))
			return 1;
		ip->bucketNumber++;
		listOfHashElements = get(ip->map.buckets,ip->bucketNumber);
		it->list = listOfHashElements;
		listIerator = getIterator(listOfHashElements);
		ip->listIterator = listIerator;
		hashMapCurrent(it);
	}
	return 0;
};

Iterator keys(HashMap *map){
	Iterator it;
	List *listOfHashElements;
	Iterator listIerator;
	IteratorPosition *ip = calloc(1,sizeof(IteratorPosition));
	listOfHashElements = (List*)get(map->buckets,0);
	listIerator = getIterator(listOfHashElements);
	ip->bucketNumber = 0;
	ip->listIterator = listIerator;
	ip->map = *(map);
	it.current = ip;
	it.list = listOfHashElements;
	it.hasNext = hashMapHasCurrent;
	it.next = hashMapCurrent;
	return it;
};