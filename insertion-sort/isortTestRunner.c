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

	testStarted("test_sorting_five_integers");
	setup();
		test_sorting_five_integers();
	tearDown();
	testEnded();
	testStarted("test_sorting_floats");
	setup();
		test_sorting_floats();
	tearDown();
	testEnded();
	testStarted("test_sorting_characters");
	setup();
		test_sorting_characters();
	tearDown();
	testEnded();
	testStarted("test_sorting_doubles");
	setup();
		test_sorting_doubles();
	tearDown();
	testEnded();
	testStarted("test_sorting_strings");
	setup();
		test_sorting_strings();
	tearDown();
	testEnded();
	testStarted("test_sorting_already_sorted_elements");
	setup();
		test_sorting_already_sorted_elements();
	tearDown();
	testEnded();
	testStarted("test_sorting_when_elements_are_reversely_sorted");
	setup();
		test_sorting_when_elements_are_reversely_sorted();
	tearDown();
	testEnded();
	testStarted("test_sorting_elements_in_reverse_order");
	setup();
		test_sorting_elements_in_reverse_order();
	tearDown();
	testEnded();
	testStarted("test_sorting_structure_according_to_numbers");
	setup();
		test_sorting_structure_according_to_numbers();
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
