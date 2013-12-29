#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_putting_first_element_in_list");
	setup();
		test_putting_first_element_in_list();
	tearDown();
	testEnded();
	testStarted("test_putting_two_elements_in_the_list");
	setup();
		test_putting_two_elements_in_the_list();
	tearDown();
	testEnded();
	testStarted("test_putting_three_elements");
	setup();
		test_putting_three_elements();
	tearDown();
	testEnded();
	testStarted("test_putting_same_key_twice_should_update_the_value");
	setup();
		test_putting_same_key_twice_should_update_the_value();
	tearDown();
	testEnded();
	testStarted("test_putting_key_value_pair_when_hash_map_is_null_should_fail");
	setup();
		test_putting_key_value_pair_when_hash_map_is_null_should_fail();
	tearDown();
	testEnded();
	testStarted("test_putting_when_key_is_null_should_fail");
	setup();
		test_putting_when_key_is_null_should_fail();
	tearDown();
	testEnded();
	testStarted("test_getting_element_that_is_absent");
	setup();
		test_getting_element_that_is_absent();
	tearDown();
	testEnded();
	testStarted("test_getting_when_map_is_null_should_fail");
	setup();
		test_getting_when_map_is_null_should_fail();
	tearDown();
	testEnded();
	testStarted("test_getting_when_key_is_null_should_fail");
	setup();
		test_getting_when_key_is_null_should_fail();
	tearDown();
	testEnded();
	testStarted("test_deleting_element_having_specific_key");
	setup();
		test_deleting_element_having_specific_key();
	tearDown();
	testEnded();
	testStarted("test_deleting_element_when_absent");
	setup();
		test_deleting_element_when_absent();
	tearDown();
	testEnded();
	testStarted("test_deleting_when_key_is_null_should_fail");
	setup();
		test_deleting_when_key_is_null_should_fail();
	tearDown();
	testEnded();
	testStarted("test_deleting_when_map_is_null_should_fail");
	setup();
		test_deleting_when_map_is_null_should_fail();
	tearDown();
	testEnded();
	testStarted("test_deleting_one_element_when_two_are_present");
	setup();
		test_deleting_one_element_when_two_are_present();
	tearDown();
	testEnded();
	testStarted("test_iterating_over_hash_map");
	setup();
		test_iterating_over_hash_map();
	tearDown();
	testEnded();
	testStarted("test_iterating_when_no_elements_are_present_in_first_bucket");
	setup();
		test_iterating_when_no_elements_are_present_in_first_bucket();
	tearDown();
	testEnded();
	testStarted("test_iterating_when_no_more_elements_are_present");
	setup();
		test_iterating_when_no_more_elements_are_present();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
