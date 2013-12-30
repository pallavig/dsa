#include "merge-sort.h"
#include <stdlib.h>

void merge(void **left,void **right,int leftLength,int rightLength,int length,void **base,CompareFunc compare){
	void **temp = malloc(length*2*sizeof(void*));
	int i,leftCounter=0,rightCounter=0;
	for (i=0;i<length;++i)
	{
		if(leftCounter > leftLength-1){
			temp[i] = right[rightCounter];
			rightCounter++;
		}
		else if(rightCounter>rightLength-1){
			temp[i] = left[leftCounter];
			leftCounter++;
		}
		else if(compare(left[leftCounter],right[rightCounter]) > 0){
			temp[i] = right[rightCounter];
			rightCounter++;
		}
		else{
			temp[i] = left[leftCounter];
			leftCounter++;
		}
	}
	for(i=0;i<length;i++)
		base[i] = temp[i];
	free(temp);
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
	merge(left,right,mid,length-mid,length,base,compare);
	free(left);
	free(right);
};