#include "testUtils.h"
#include "hashMap.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
	int isbn;
	char name[20];
} Book;

int isbn10 = 10;
int isbn11 = 11;
int isbn20 = 20;
Book youCanWin = {10,"You Can Win"};
Book swamiAndFriends = {11,"Swami and friends"};
Book yayati = {20,"Yayati"};
Book theSecretSeven = {10,"The Secret Seven"};

int getHashCode(void *key){
	return *(int*)key;
};

int cmpInt(void *first,void *second){
	return 0 == *(int*)first - *(int*)second;
};

void test_putting_first_element_in_list(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	ASSERT(1 == put(&map,&isbn10,&youCanWin.name));
	ASSERT(0 == strcmp(youCanWin.name,getHashObject(&map,&isbn10)));
};

void test_putting_two_elements_in_the_list(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	put(&map,&isbn10,&youCanWin.name);
	put(&map,&isbn11,&swamiAndFriends.name);
	ASSERT(0 == strcmp(youCanWin.name,getHashObject(&map,&isbn10)));
	ASSERT(0 == strcmp(swamiAndFriends.name,getHashObject(&map,&isbn11)));
};

void test_putting_three_elements(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	put(&map,&isbn10,&youCanWin.name);
	put(&map,&isbn11,&swamiAndFriends.name);
	put(&map,&isbn20,&yayati.name);
	ASSERT(0 == strcmp(youCanWin.name,getHashObject(&map,&isbn10)));
	ASSERT(0 == strcmp(swamiAndFriends.name,getHashObject(&map,&isbn11)));
	ASSERT(0 == strcmp(yayati.name,getHashObject(&map,&isbn20)));
};

void test_putting_same_key_twice_should_update_the_value(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	put(&map,&isbn10,&youCanWin.name);
	put(&map,&isbn10,&theSecretSeven.name);
	ASSERT(0 == strcmp(theSecretSeven.name,getHashObject(&map,&isbn10)));
	ASSERT(0 != strcmp(youCanWin.name,getHashObject(&map,&isbn10)));
};

void test_getting_element_that_is_absent(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	ASSERT(NULL == getHashObject(&map,&isbn10));
};

void test_deleting_element_having_specific_key(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	put(&map,&isbn10,&youCanWin.name);
	ASSERT(1 == removeHashObject(&map,&isbn10));
	ASSERT(NULL == getHashObject(&map,&isbn10));
};

void test_deleting_element_when_absent(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	ASSERT(0 == removeHashObject(&map,&isbn11));
};

void test_deleting_one_element_when_two_are_present(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	put(&map,&isbn10,&youCanWin.name);
	put(&map,&isbn11,&swamiAndFriends.name);
	ASSERT(1 == removeHashObject(&map,&isbn10));
	ASSERT(NULL == getHashObject(&map,&isbn10));
	ASSERT(0 == strcmp(swamiAndFriends.name,getHashObject(&map,&isbn11)));
};

// // void test_iterating_over_hash_map(){
// // 	HashMap map = createHashMap(getHashCode,cmpInt,10);
// // 	Iterator it;
// // 	put(&map,&isbn10,&youCanWin.name);
// // 	put(&map,&isbn11,&swamiAndFriends.name);
// // 	it = keys(&map);
// // 	ASSERT(isbn10 == *(int*)it.next(&it));
// // };