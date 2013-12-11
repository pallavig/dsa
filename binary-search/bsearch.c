#include "bsearch.h"
#include <string.h>
ConstVoidPtr bsearch(ConstVoidPtr key,ConstVoidPtr base,int nitems,int size,int (*compare)(ConstVoidPtr,ConstVoidPtr)){
	ConstVoidPtr middleElement;
	int middle,found,start = 0,end = nitems - 1;
	while(start<=end){
		middle = (start+end)/2;
		middleElement = base + (middle*size);
		found = compare(key,middleElement);
		if(0 == found) return middleElement;
		if(found < 0) end = middle-1;
		if(found > 0) start = middle+1;
	}
	return NULL;
};