#include "bSort.h"
void bSort(void **base,int numberOfElements,compareFunc compare){
	int outerLoopCounter,innerLoopCounter,compareResult;
	void *temp;
	for (outerLoopCounter=1;outerLoopCounter<numberOfElements;++outerLoopCounter)
	{
		for(innerLoopCounter=0;innerLoopCounter<(numberOfElements-outerLoopCounter);innerLoopCounter++){
			compareResult = compare(base[innerLoopCounter],base[innerLoopCounter+1]);
			if(compareResult > 0){
				temp = base[innerLoopCounter];
				base[innerLoopCounter] = base[innerLoopCounter+1];
				base[innerLoopCounter+1] = temp;
			}
		}
	}
};