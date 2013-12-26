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

	testStarted("test_inserting_first_node_in_linked_list");
	setup();
		test_inserting_first_node_in_linked_list();
	tearDown();
	testEnded();
	testStarted("test_inserting_two_nodes_one_root_and_its_child");
	setup();
		test_inserting_two_nodes_one_root_and_its_child();
	tearDown();
	testEnded();
	testStarted("test_inserting_three_nodes_one_after_the_other");
	setup();
		test_inserting_three_nodes_one_after_the_other();
	tearDown();
	testEnded();
	testStarted("test_inserting_node_at_depth_two");
	setup();
		test_inserting_node_at_depth_two();
	tearDown();
	testEnded();
	testStarted("test_searching_root_node");
	setup();
		test_searching_root_node();
	tearDown();
	testEnded();
	testStarted("test_searching_nodes_depth_one");
	setup();
		test_searching_nodes_depth_one();
	tearDown();
	testEnded();
	testStarted("test_searching_at_depth_two");
	setup();
		test_searching_at_depth_two();
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
