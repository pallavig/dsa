#include "arrayList.h"
#include <stdlib.h>

ArrayList create(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
}

void shiftElementsIfNeeded(ArrayList *list, int index) {
	int i;
	if (index < list->length) {
		for (i = list->length - 1; i >= index; i--) {
			list->base[i+1] = list->base[i];
		}
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

int insert(ArrayList *list, int index, void* data) {
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;
	increaseCapacity(list);
	shiftElementsIfNeeded(list, index);
	list->base[index] = data;
	list->length++;
	return 1;
}

int remove(ArrayList *list,int index){
	int i;
	if(index > list->length-1 || index < 0) return 0;
	if(index < list->length){
		for(i=index;i<list->length-1;i++){
			list->base[i] = list->base[i+1];
		}
	}
	list->length--;
	return 1;	
};

void* get(ArrayList *list, int index) {
	if (index < 0 || index >= list->length) return NULL;
	return list->base[index];
}

void dispose(ArrayList *list) {
	free(list->base);
}