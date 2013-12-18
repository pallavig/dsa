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
	testStarted("test_pushing_an_integer_to_stack");
	setup();
		test_pushing_an_integer_to_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_two_characters_to_stack");
	setup();
		test_pushing_two_characters_to_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_three_floats_to_stack");
	setup();
		test_pushing_three_floats_to_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_string_to_stack");
	setup();
		test_pushing_string_to_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_structure_to_stack");
	setup();
		test_pushing_structure_to_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_double_element");
	setup();
		test_pushing_double_element();
	tearDown();
	testEnded();
	testStarted("test_popping_all_elements");
	setup();
		test_popping_all_elements();
	tearDown();
	testEnded();
	testStarted("test_popping_float_from_stack");
	setup();
		test_popping_float_from_stack();
	tearDown();
	testEnded();
	testStarted("test_popping_String_from_stack");
	setup();
		test_popping_String_from_stack();
	tearDown();
	testEnded();
	testStarted("test_poppig_structure_from_stack");
	setup();
		test_poppig_structure_from_stack();
	tearDown();
	testEnded();
	testStarted("test_popping_from_an_empty_stack");
	setup();
		test_popping_from_an_empty_stack();
	tearDown();
	testEnded();
	testStarted("test_getting_top_integer_node");
	setup();
		test_getting_top_integer_node();
	tearDown();
	testEnded();
	testStarted("test_getting_top_character_node");
	setup();
		test_getting_top_character_node();
	tearDown();
	testEnded();
	testStarted("test_getting_the_top_node_from_stack");
	setup();
		test_getting_the_top_node_from_stack();
	tearDown();
	testEnded();
	testStarted("test_getting_top_when_stack_is_empty");
	setup();
		test_getting_top_when_stack_is_empty();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
