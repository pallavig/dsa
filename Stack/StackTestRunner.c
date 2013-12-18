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

	testStarted("test_creation_of_stack");
	setup();
		test_creation_of_stack();
	tearDown();
	testEnded();
	testStarted("test_push_integer");
	setup();
		test_push_integer();
	tearDown();
	testEnded();
	testStarted("test_push_two_integers");
	setup();
		test_push_two_integers();
	tearDown();
	testEnded();
	testStarted("test_pushing_an_character_in_stack");
	setup();
		test_pushing_an_character_in_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_an_float_in_stack");
	setup();
		test_pushing_an_float_in_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_an_double_in_stack");
	setup();
		test_pushing_an_double_in_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_an_String_in_stack");
	setup();
		test_pushing_an_String_in_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_elements_equal_to_size_of_stack");
	setup();
		test_pushing_elements_equal_to_size_of_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_elements_when_stack_is_full");
	setup();
		test_pushing_elements_when_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_popping_one_integer_when_two_are_present");
	setup();
		test_popping_one_integer_when_two_are_present();
	tearDown();
	testEnded();
	testStarted("test_popping_from_an_empty_stack");
	setup();
		test_popping_from_an_empty_stack();
	tearDown();
	testEnded();
	testStarted("test_getting_top_element_from_empty_stack");
	setup();
		test_getting_top_element_from_empty_stack();
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
