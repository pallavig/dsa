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

void createLinkedListInBuckets(HashMap *map){
	int i;
	ArrayList listOfBuckets = createArrayList(map->capacity);
	map->buckets = calloc(1,sizeof(ArrayList));
	*(ArrayList*)map->buckets = listOfBuckets;
	for(i=0;i<map->capacity;i++)
		addInArrayList(map->buckets, create());
};

HashMap createHashMap(HashCodeGenerator getHashCode,compareFunc cmp,int capacity){
	HashMap map;
	int i;
	List *listOfHashObjects;
	map.getHashCode = getHashCode;
	map.compare = cmp;
	map.capacity = capacity;
	createLinkedListInBuckets(&map);
	return map;
};

Object* getMatchingObject(HashMap *map,void *key,int flag){
	int hash;
	List *list;
	Object *object;
	Iterator it;
	hash = calculateHash(map,key);
	list = get(map->buckets,hash);
	it = getIterator(list);
	while(it.hasNext(&it)){
		object = it.next(&it);
		if(map->compare(object->key,key))
			return object;
	}
	return NULL;
};

void reHash(HashMap *map){
	int i;
	List *list;
	Object *object;
	Iterator it = keys(map);
	ArrayList listOfBuckets;
	Iterator dllIterator = getIterator(it.list);
	disposeHashMap(map);
	map->capacity = map->capacity * 2;
	createLinkedListInBuckets(map);
	for(i=0;i<map->capacity;i++)
		list = get(map->buckets,i);
	while(dllIterator.hasNext(&dllIterator)){
		object = dllIterator.next(&dllIterator);
		put(map,object->key,object->values);
	}
};

void rehashIfNeeded(HashMap *map){
	int i;
	List *listOfHashObjects;
	for(i=0;i<map->capacity;i++){
		listOfHashObjects = (List*)get(map->buckets,i);
		if(listOfHashObjects->length > 3)
			return reHash(map);
	}
};

int put(HashMap *map,void *key,void *value){
	List *listOfHashObjects;
	Object *objectPrevoiuslyPresent,*object;
	int hash;
	if(map == NULL || key == NULL) return 0;
	objectPrevoiuslyPresent = getMatchingObject(map,key,0);
	if(objectPrevoiuslyPresent){
		objectPrevoiuslyPresent->values = value;
		return 1;
	}
	object = createObject(key,value);
	hash = calculateHash(map,key);
	listOfHashObjects = get(map->buckets,hash);
	insert(listOfHashObjects,object,1);
	rehashIfNeeded(map);
	return 1;
};

void* getHashObject(HashMap *map,void *key){
	Object *object;
	if(key == NULL || map == NULL) return NULL;
	object = getMatchingObject(map,key,0);
	return (object)?object->values:NULL;
};

int removeHashObject(HashMap *map,void *key){
	List *list;
	Object *object;
	Iterator it;
	int index = 1,hash;
	if(key == NULL || map == NULL) return 0;
	hash = calculateHash(map,key);
	list = get(map->buckets,hash);
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

void *getNextKey(Iterator *hashit){
	Object *hashObject;
	Iterator dllIterator = getIterator(hashit->list);
	dllIterator.current = hashit->current;
	hashObject = dllIterator.next(&dllIterator);
	hashit->current = dllIterator.current;
	if(hashObject) return hashObject->key;
	return NULL;
};

Iterator keys(HashMap *map){
	int i = 0;
	Iterator it;
	Iterator listIterator;
	List *listOfHashObjects = create(),*list;
	while(i<map->capacity){
		list = (List*)get(map->buckets,i);
		listIterator = getIterator(list);
		while(listIterator.hasNext(&listIterator))
			insert(listOfHashObjects,listIterator.next(&listIterator),1);
		i++;
	}
	it = getIterator(listOfHashObjects);
	it.next = getNextKey;
	return it;
};

void disposeHashMap(HashMap *map){
	int i;
	List *listOfHashObjects;
	Iterator it;
	for(i=0;i<map->capacity;i++){
		listOfHashObjects = (List*)get(map->buckets,i);
		dispose(listOfHashObjects);
	};
	free(map->buckets);
};