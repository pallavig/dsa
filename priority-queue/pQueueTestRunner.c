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

	testStarted("test_inserting_first_item_in_priority_queue");
	setup();
		test_inserting_first_item_in_priority_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_first_char_item_in_priority_queue");
	setup();
		test_inserting_first_char_item_in_priority_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_float_item");
	setup();
		test_inserting_float_item();
	tearDown();
	testEnded();
	testStarted("test_inserting_struct_item");
	setup();
		test_inserting_struct_item();
	tearDown();
	testEnded();
	testStarted("test_inserting_two_elments_with_second_of_lower_priority");
	setup();
		test_inserting_two_elments_with_second_of_lower_priority();
	tearDown();
	testEnded();
	testStarted("test_inserting_three_elements_with_third_of_higher_priority");
	setup();
		test_inserting_three_elements_with_third_of_higher_priority();
	tearDown();
	testEnded();
	testStarted("test_inserting_four_elements_in_random_priority_order");
	setup();
		test_inserting_four_elements_in_random_priority_order();
	tearDown();
	testEnded();
	testStarted("test_inserting_nodes_of_same_priority");
	setup();
		test_inserting_nodes_of_same_priority();
	tearDown();
	testEnded();
	testStarted("test_deleting_double_element_from_pqueue");
	setup();
		test_deleting_double_element_from_pqueue();
	tearDown();
	testEnded();
	testStarted("test_deleting_node_when_pqueue_is_empty");
	setup();
		test_deleting_node_when_pqueue_is_empty();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
