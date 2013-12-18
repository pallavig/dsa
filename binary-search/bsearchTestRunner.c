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

	testStarted("test_search_an_integer_element_in_array");
	setup();
		test_search_an_integer_element_in_array();
	tearDown();
	testEnded();
	testStarted("test_search_middle_element_in_array");
	setup();
		test_search_middle_element_in_array();
	tearDown();
	testEnded();
	testStarted("test_search_the_first_element_of_array");
	setup();
		test_search_the_first_element_of_array();
	tearDown();
	testEnded();
	testStarted("test_search_last_element_of_the_array");
	setup();
		test_search_last_element_of_the_array();
	tearDown();
	testEnded();
	testStarted("test_search_element_in_array_of_even_number_size");
	setup();
		test_search_element_in_array_of_even_number_size();
	tearDown();
	testEnded();
	testStarted("test_search_element_which_is_absent");
	setup();
		test_search_element_which_is_absent();
	tearDown();
	testEnded();
	testStarted("test_searching_string");
	setup();
		test_searching_string();
	tearDown();
	testEnded();
	testStarted("test_searching_structure");
	setup();
		test_searching_structure();
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
