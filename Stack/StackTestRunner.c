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

	testStarted("test_creation_of_stack_of_three_integers");
	setup();
		test_creation_of_stack_of_three_integers();
	tearDown();
	testEnded();
	testStarted("test_creation_of_stack_of_three_characters");
	setup();
		test_creation_of_stack_of_three_characters();
	tearDown();
	testEnded();
	testStarted("test_creation_of_stack_of_three_floats");
	setup();
		test_creation_of_stack_of_three_floats();
	tearDown();
	testEnded();
	testStarted("test_creation_of_stack_of_three_doubles");
	setup();
		test_creation_of_stack_of_three_doubles();
	tearDown();
	testEnded();
	testStarted("test_creation_of_stack_of_three_strings");
	setup();
		test_creation_of_stack_of_three_strings();
	tearDown();
	testEnded();
	testStarted("test_creation_of_stack_of_three_structures");
	setup();
		test_creation_of_stack_of_three_structures();
	tearDown();
	testEnded();
	testStarted("test_isFull_gives_1_if_stack_is_full");
	setup();
		test_isFull_gives_1_if_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_isFull_gives_0_if_stack_is_not_full");
	setup();
		test_isFull_gives_0_if_stack_is_not_full();
	tearDown();
	testEnded();
	testStarted("test_pushing_an_integer_element_to_stack");
	setup();
		test_pushing_an_integer_element_to_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_an_character_element_to_stack");
	setup();
		test_pushing_an_character_element_to_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_an_float_element_to_stack");
	setup();
		test_pushing_an_float_element_to_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_an_double_element_to_stack");
	setup();
		test_pushing_an_double_element_to_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_an_String_element_to_stack");
	setup();
		test_pushing_an_String_element_to_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_an_strucure_element_to_stack");
	setup();
		test_pushing_an_strucure_element_to_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_two_elements_in_the_stack");
	setup();
		test_pushing_two_elements_in_the_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_an_integer_element_when_stack_is_full");
	setup();
		test_pushing_an_integer_element_when_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_returns_1_if_the_stack_is_empty");
	setup();
		test_isEmpty_returns_1_if_the_stack_is_empty();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_returns_0_if_the_stack_is_not_empty");
	setup();
		test_isEmpty_returns_0_if_the_stack_is_not_empty();
	tearDown();
	testEnded();
	testStarted("test_popping_an_integer_element_from_stack");
	setup();
		test_popping_an_integer_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_popping_an_character_element_from_stack");
	setup();
		test_popping_an_character_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_popping_an_double_element_from_stack");
	setup();
		test_popping_an_double_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_popping_an_float_element_from_stack");
	setup();
		test_popping_an_float_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_popping_an_String_element_from_stack");
	setup();
		test_popping_an_String_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_popping_an_integer_element_when_the_stack_is_empty");
	setup();
		test_popping_an_integer_element_when_the_stack_is_empty();
	tearDown();
	testEnded();
	testStarted("test_top_element_in_stack_of_integers");
	setup();
		test_top_element_in_stack_of_integers();
	tearDown();
	testEnded();
	testStarted("test_top_element_in_stack_of_characters");
	setup();
		test_top_element_in_stack_of_characters();
	tearDown();
	testEnded();
	testStarted("test_top_element_in_stack_of_floats");
	setup();
		test_top_element_in_stack_of_floats();
	tearDown();
	testEnded();
	testStarted("test_top_element_in_stack_of_doubles");
	setup();
		test_top_element_in_stack_of_doubles();
	tearDown();
	testEnded();
	testStarted("test_top_element_in_stack_of_Strings");
	setup();
		test_top_element_in_stack_of_Strings();
	tearDown();
	testEnded();
	testStarted("test_top_element_in_stack_of_structures");
	setup();
		test_top_element_in_stack_of_structures();
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
