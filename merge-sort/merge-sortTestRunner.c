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

	testStarted("test_sorting_two_elements_with_merge_sort");
	setup();
		test_sorting_two_elements_with_merge_sort();
	tearDown();
	testEnded();
	testStarted("test_sorting_four_elements_with_merge_sort");
	setup();
		test_sorting_four_elements_with_merge_sort();
	tearDown();
	testEnded();
	testStarted("test_sorting_three_elements");
	setup();
		test_sorting_three_elements();
	tearDown();
	testEnded();
	testStarted("test_sorting_five_elements");
	setup();
		test_sorting_five_elements();
	tearDown();
	testEnded();
	testStarted("test_sorting_characters");
	setup();
		test_sorting_characters();
	tearDown();
	testEnded();
	testStarted("test_sorting_floats");
	setup();
		test_sorting_floats();
	tearDown();
	testEnded();
	testStarted("test_sorting_doubles");
	setup();
		test_sorting_doubles();
	tearDown();
	testEnded();
	testStarted("test_sorting_structure");
	setup();
		test_sorting_structure();
	tearDown();
	testEnded();
	testStarted("test_sorting_duplicate_elements");
	setup();
		test_sorting_duplicate_elements();
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
