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

	testStarted("test_sorting_five_integers_elements");
	setup();
		test_sorting_five_integers_elements();
	tearDown();
	testEnded();
	testStarted("test_sorting_three_character_elements");
	setup();
		test_sorting_three_character_elements();
	tearDown();
	testEnded();
	testStarted("test_sorting_float_elements");
	setup();
		test_sorting_float_elements();
	tearDown();
	testEnded();
	testStarted("test_sorting_double_elements");
	setup();
		test_sorting_double_elements();
	tearDown();
	testEnded();
	testStarted("test_sorting_structure");
	setup();
		test_sorting_structure();
	tearDown();
	testEnded();
	testStarted("test_inserting_duplicate_elements");
	setup();
		test_inserting_duplicate_elements();
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
