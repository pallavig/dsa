#include "merge-sort.h"
#include <stdlib.h>

void merge(void **left,void **right,int length,void **base,int start,int end,CompareFunc compare){
	void **temp = malloc(length*2*sizeof(void*));
	int i,leftCounter=0,rightCounter=0;
	for (i=0;i<(length*2);++i)
	{
		if(leftCounter > (length-1))
			temp[i] = right[rightCounter];
		else if(rightCounter>(length-1))
			temp[i] = left[leftCounter];
		else if(compare(left[leftCounter],right[rightCounter]) > 0){
			temp[i] = right[rightCounter];
			rightCounter++;
		}
		else{
			temp[i] = left[leftCounter];
			leftCounter++;
		}
	}
	for(i=0;i<length*2;i++)
		base[start+i] = temp[i];
	free(temp);
};

void mSort(void **base,int start,int end,int length,CompareFunc compare){
	int mid,i;
	void **left,**right;
	mid = (start + end)/2;
	for(i=0;i<length;i++)
	left = malloc((mid+1)*sizeof(void*));
	right = malloc((mid+1)*sizeof(void*));
	if(length == 1)
		return;
	else{
		for(i=0;i<=mid;i++){
			left[i] = base[i];
			right[i] = base[mid+(i+1)];
		}
		mSort(left,0,mid,mid+1,compare);
		mSort(right,0,mid,mid+1,compare);
		merge(left,right,mid+1,base,start,end,compare);
	}
	free(left);
	free(right);
};