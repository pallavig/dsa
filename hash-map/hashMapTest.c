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
int isbn15 = 15;
int isbn14 = 14;

int getHashCode(void *key){
	return *(int*)key;
};

int cmpInt(void *first,void *second){
	return 0 == *(int*)first - *(int*)second;
};

void test_putting_first_element_in_list(){
	Book youCanWin = {10,"YouCanWin"};
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	ASSERT(1 == put(&map,&isbn10,&youCanWin.name));
	ASSERT(0 == strcmp(youCanWin.name,getHashObject(&map,&isbn10)));
	disposeHashMap(&map);
};

void test_putting_two_elements_in_the_list(){
	Book youCanWin = {10,"YouCanWin"};
	Book swamiAndFriends = {11,"Swami and friends"};
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	put(&map,&isbn10,&youCanWin.name);
	put(&map,&isbn11,&swamiAndFriends.name);
	ASSERT(0 == strcmp(youCanWin.name,getHashObject(&map,&isbn10)));
	ASSERT(0 == strcmp(swamiAndFriends.name,getHashObject(&map,&isbn11)));
	disposeHashMap(&map);
};

void test_putting_three_elements(){
	Book youCanWin = {10,"YouCanWin"};
	Book swamiAndFriends = {11,"Swami and friends"};
	Book yayati = {20,"Yayati"};
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	put(&map,&isbn10,&youCanWin.name);
	put(&map,&isbn11,&swamiAndFriends.name);
	put(&map,&isbn20,&yayati.name);
	ASSERT(0 == strcmp(youCanWin.name,getHashObject(&map,&isbn10)));
	ASSERT(0 == strcmp(swamiAndFriends.name,getHashObject(&map,&isbn11)));
	ASSERT(0 == strcmp(yayati.name,getHashObject(&map,&isbn20)));
	disposeHashMap(&map);
};

void test_putting_same_key_twice_should_update_the_value(){
	Iterator it;
	Book youCanWin = {10,"YouCanWin"};
	Book swamiAndFriends = {11,"Swami and friends"};
	Book theSecretSeven = {10,"The Secret Seven"};
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	put(&map,&isbn10,&youCanWin.name);
	put(&map,&isbn10,&theSecretSeven.name);
	it = keys(&map);
	ASSERT(0 == strcmp(theSecretSeven.name,getHashObject(&map,&isbn10)));
	ASSERT(0 != strcmp(youCanWin.name,getHashObject(&map,&isbn10)));
	disposeHashMap(&map);
};

void test_putting_key_value_pair_when_hash_map_is_null_should_fail(){
	Book youCanWin = {10,"YouCanWin"};
	ASSERT(0 == put(NULL,&isbn10,&youCanWin.name));
};

void test_putting_when_key_is_null_should_fail(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	Book youCanWin = {10,"YouCanWin"};
	ASSERT(0 == put(&map,NULL,&youCanWin.name));	
	disposeHashMap(&map);
};

void test_getting_element_that_is_absent(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	ASSERT(NULL == getHashObject(&map,&isbn10));
	disposeHashMap(&map);
};

void test_getting_when_map_is_null_should_fail(){
	ASSERT(NULL == getHashObject(NULL,&isbn10));
};

void test_getting_when_key_is_null_should_fail(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	ASSERT(NULL == getHashObject(&map,NULL));
	disposeHashMap(&map);
};

void test_deleting_element_having_specific_key(){
	Book youCanWin = {10,"YouCanWin"};
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	put(&map,&isbn10,&youCanWin.name);
	ASSERT(1 == removeHashObject(&map,&isbn10));
	ASSERT(NULL == getHashObject(&map,&isbn10));
	disposeHashMap(&map);
};

void test_deleting_element_when_absent(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	ASSERT(0 == removeHashObject(&map,&isbn11));
	disposeHashMap(&map);
};

void test_deleting_when_key_is_null_should_fail(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	ASSERT(0 == removeHashObject(&map,NULL));
	disposeHashMap(&map);
};

void test_deleting_when_map_is_null_should_fail(){
	ASSERT(0 == removeHashObject(NULL,NULL));
}

void test_deleting_one_element_when_two_are_present(){
	Book youCanWin = {10,"YouCanWin"};
	Book swamiAndFriends = {11,"Swami and friends"};
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	put(&map,&isbn10,&youCanWin.name);
	put(&map,&isbn11,&swamiAndFriends.name);
	ASSERT(1 == removeHashObject(&map,&isbn10));
	ASSERT(NULL == getHashObject(&map,&isbn10));
	ASSERT(0 == strcmp(swamiAndFriends.name,getHashObject(&map,&isbn11)));
	disposeHashMap(&map);
};

void test_iterating_over_hash_map(){
	Book youCanWin = {10,"YouCanWin"};
	Book yayati = {20,"Yayati"};
	Book swamiAndFriends = {11,"Swami and friends"};
	Book theSecretSeven = {15,"The Secret Seven"};
	Book theFamousFive = {14,"The secret seven"};
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	Iterator it;
	put(&map,&isbn10,&youCanWin.name);
	put(&map,&isbn11,&swamiAndFriends.name);
	put(&map,&isbn20,&yayati.name);
	put(&map,&isbn15,&theSecretSeven.name);
	put(&map,&isbn14,&theFamousFive.name);
	it = keys(&map);
	ASSERT(15 == *(int*)it.next(&it));
	ASSERT(14 == *(int*)it.next(&it));
	ASSERT(11 == *(int*)it.next(&it));
	ASSERT(10 == *(int*)it.next(&it));
	ASSERT(20 == *(int*)it.next(&it));
	ASSERT(NULL == it.next(&it));
	disposeHashMap(&map);
};

void test_iterating_when_no_elements_are_present_in_first_bucket(){
	Book swamiAndFriends = {11,"Swami and friends"};
	Iterator it;
	void *key;
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	put(&map,&isbn11,&swamiAndFriends.name);
	it = keys(&map);
	key = it.next(&it);
	ASSERT(11 == *(int*)key);
	ASSERT(0 == strcmp(swamiAndFriends.name,getHashObject(&map,key)));
	ASSERT(NULL == it.next(&it));
	disposeHashMap(&map);
};

void test_iterating_when_no_more_elements_are_present(){
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	Iterator it;
	it = keys(&map);
	ASSERT(0 == it.hasNext(&it));
	ASSERT(NULL == it.next(&it));
	disposeHashMap(&map);
};

void test_map_should_rehash_when_elements_in_bucket_are_more_than_3(){
	Iterator it;
	Book youCanWin = {10,"YouCanWin"};
	Book yayati = {20,"Yayati"};
	Book swamiAndFriends = {30,"Swami and friends"};
	Book theSecretSeven = {40,"The Secret Seven"};
	int isbn30 = 30,isbn40 = 40;
	HashMap map = createHashMap(getHashCode,cmpInt,10);
	put(&map,&isbn10,&youCanWin.name);
	put(&map,&isbn20,&yayati.name);
	put(&map,&isbn30,&swamiAndFriends.name);
	put(&map,&isbn40,&theSecretSeven.name);
	it = keys(&map);
	ASSERT(10 == *(int*)it.next(&it));
	ASSERT(30 == *(int*)it.next(&it));
	ASSERT(20 == *(int*)it.next(&it));
	ASSERT(40 == *(int*)it.next(&it));
	ASSERT(NULL == it.next(&it));
};