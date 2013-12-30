#include "merge-sort.h"
#include <stdlib.h>

void merge(void **left,void **right,int leftLength,int rightLength,void **base,CompareFunc compare){
	int totalLength  = leftLength + rightLength;
	int i,leftCounter=0,rightCounter=0;
	for (i=0;i<totalLength;++i)
	{
		if(leftCounter > leftLength-1){
			base[i] = right[rightCounter];
			rightCounter++;
			continue;
		}
		if(rightCounter>rightLength-1){
			base[i] = left[leftCounter];
			leftCounter++;
			continue;
		}
		if(compare(left[leftCounter],right[rightCounter]) > 0){
			base[i] = right[rightCounter];
			rightCounter++;
			continue;
		}
		base[i] = left[leftCounter];
		leftCounter++;
	}
};

void mSort(void **base,int length,CompareFunc compare){
	int mid,i;
	void **left,**right;
	mid = length/2;
	left = malloc((mid+1)*sizeof(void*));
	right = malloc((mid+1)*sizeof(void*));
	if(length == 1)
		return;
	for(i=0;i<mid;i++)
		left[i] = base[i];
	for(i=mid;i<length;i++)
		right[i-mid] = base[i];
	mSort(left,mid,compare);
	mSort(right,length-mid,compare);
	merge(left,right,mid,length-mid,base,compare);
	free(left);
	free(right);
};