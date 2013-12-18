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

	testStarted("test_creation_of_priority_queue");
	setup();
		test_creation_of_priority_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_first_process");
	setup();
		test_inserting_first_process();
	tearDown();
	testEnded();
	testStarted("test_inserting_two_nodes_with_second_of_lower_priority");
	setup();
		test_inserting_two_nodes_with_second_of_lower_priority();
	tearDown();
	testEnded();
	testStarted("test_inserting_two_nodes_with_second_of_higher_priority");
	setup();
		test_inserting_two_nodes_with_second_of_higher_priority();
	tearDown();
	testEnded();
	testStarted("test_inserting_in_between");
	setup();
		test_inserting_in_between();
	tearDown();
	testEnded();
	testStarted("test_inserting_two_processes_of_same_priority");
	setup();
		test_inserting_two_processes_of_same_priority();
	tearDown();
	testEnded();
	testStarted("test_inserting_three_processes_of_which_two_are_of_same_priority");
	setup();
		test_inserting_three_processes_of_which_two_are_of_same_priority();
	tearDown();
	testEnded();
	testStarted("test_removing_node");
	setup();
		test_removing_node();
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
