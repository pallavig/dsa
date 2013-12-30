#include "merge-sort.h"
#include <stdlib.h>

void merge(void **left,void **right,int length,void **base,int start,int end,CompareFunc compare){
	void **temp = malloc(length*2);
	// printf("%d\n",*(int*)left[0]);
	int i;
	if(compare(left[0],right[0]) > 0){
		temp[0] = right[0];
		temp[1] = left[0];
	}
	for(i=0;i<length*2;i++)
		base[start+i] = temp[i];
	free(temp);
};

void mSort(void **base,int start,int end,int length,CompareFunc compare){
	int mid,i;
	void **left,**right;
	mid = (start + end)/2;
	left = malloc(mid*sizeof(void*));
	right = malloc(mid*sizeof(void*));
	if(length == 1)
		return;
	else{
		for(i=0;i<=mid;i++){
			left[i] = base[i];
			right[i] = base[mid+1];
		}
		mSort(left,0,mid,mid+1,compare);
		mSort(right,0,mid,mid+1,compare);
		merge(left,right,mid+1,base,start,end,compare);
	}
	free(left);
	free(right);
};