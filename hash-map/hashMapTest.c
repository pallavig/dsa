#include "testUtils.h"
#include "hashMap.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
	int isbn;
	char name[20];
} Book;

int getHashCode(void *key){
	return ((Book*)key)->isbn;
};

int cmpInt(void *first,void *second){
	return *(int*)first - *(int*)second;
};

void test_putting_first_element_in_list(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	Book youCanWin = {10,"You Can Win"};
	int isbn = 10;
	ASSERT(1 == put(&map,&isbn,&youCanWin));
};