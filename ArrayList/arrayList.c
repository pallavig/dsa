#include "arrayList.h"
#include <stdlib.h>

ArrayList createArrayList(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
}

void shiftElementsIfNeeded(ArrayList *list, int index) {
	int i;
	for (i = list->length - 1; i >= index; i--) {
		list->base[i+1] = list->base[i];
	}
}

int isFull(ArrayList *list) {
	return list->length == list->capacity;
}

void increaseCapacity(ArrayList *list) {
	int targetCapacity;
	if (isFull(list)) {
		targetCapacity = list->capacity * 2;
		list->base = realloc(list->base, targetCapacity * sizeof(void*));
		list->capacity = targetCapacity;
	}	
}

int getLength(ArrayList *list){
	return list->length;
};

int insertInArrayList(ArrayList *list, int index, void* data) {
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;
	increaseCapacity(list);
	shiftElementsIfNeeded(list, index);
	list->base[index] = data;
	list->length++;
	return 1;
};

int addInArrayList(ArrayList *list,void *data){
	if(list == NULL) return 0;
	return insertInArrayList(list,list->length,data);
};

int removeFromArrayList(ArrayList *list,int index){
	int i;
	if(index > list->length-1 || index < 0) return 0;
	for(i=index;i<list->length-1;i++){
		list->base[i] = list->base[i+1];
	}
	list->length--;
	return 1;
};

void* get(ArrayList *list, int index) {
	if (index < 0 || index >= list->length) return NULL;
	return list->base[index];
};

int search(ArrayList *list,void* data,CompareFunc cmp){
	int i,res;
	if(list == NULL) return -1;
	for(i=0;i<list->length;i++){
		res = cmp(get(list,i),data);
		if(1 == res)
			return i;
	}
	return -1;
};

int hasCurrentInArrayList(Iterator *it){
	return it->current != NULL;
};

void* giveCurrentElement(Iterator *it){
	if(it->hasNext(it)){
		void **current;
		current = it->current;
		it->current = it->current + sizeof(void*);
		return *current;
	}
	return NULL;
};

Iterator getIterator(ArrayList *list){
	Iterator it;
	it.current = list->base;
	it.list = list->base;
	it.hasNext = hasCurrentInArrayList;
	it.next = giveCurrentElement;
	return it;
};

void iterate(ArrayList list, ForEach* forEach){
        int result,index;
        for(index = 0;index < list.length ;index++){
                forEach(list.base[index]);
        }
}

void disposeArrayList(ArrayList *list) {
	free(list->base);
};