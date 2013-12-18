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

	testStarted("test_creation_of_queue_with_integers");
	setup();
		test_creation_of_queue_with_integers();
	tearDown();
	testEnded();
	testStarted("test_creation_of_queue_with_characters");
	setup();
		test_creation_of_queue_with_characters();
	tearDown();
	testEnded();
	testStarted("test_creation_of_queue_with_floats");
	setup();
		test_creation_of_queue_with_floats();
	tearDown();
	testEnded();
	testStarted("test_creation_of_queue_with_doubles");
	setup();
		test_creation_of_queue_with_doubles();
	tearDown();
	testEnded();
	testStarted("test_creation_of_queue_with_Strings");
	setup();
		test_creation_of_queue_with_Strings();
	tearDown();
	testEnded();
	testStarted("test_user_should_be_informed_when_stack_is_full");
	setup();
		test_user_should_be_informed_when_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_user_should_be_informed_when_stack_is_not_full");
	setup();
		test_user_should_be_informed_when_stack_is_not_full();
	tearDown();
	testEnded();
	testStarted("test_inserting_an_integer_element_in_queue");
	setup();
		test_inserting_an_integer_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_an_character_element_in_queue");
	setup();
		test_inserting_an_character_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_an_float_element_in_queue");
	setup();
		test_inserting_an_float_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_an_String_element_in_queue");
	setup();
		test_inserting_an_String_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_an_element_when_queue_is_full");
	setup();
		test_inserting_an_element_when_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_user_should_be_informed_when_queue_is_empty");
	setup();
		test_user_should_be_informed_when_queue_is_empty();
	tearDown();
	testEnded();
	testStarted("test_user_should_be_informed_when_queue_is_not_empty");
	setup();
		test_user_should_be_informed_when_queue_is_not_empty();
	tearDown();
	testEnded();
	testStarted("test_deleting_an_integer_element_from_queue");
	setup();
		test_deleting_an_integer_element_from_queue();
	tearDown();
	testEnded();
	testStarted("test_deleting_an_character_element_from_the_queue");
	setup();
		test_deleting_an_character_element_from_the_queue();
	tearDown();
	testEnded();
	testStarted("test_deleting_an_float_element_from_the_queue");
	setup();
		test_deleting_an_float_element_from_the_queue();
	tearDown();
	testEnded();
	testStarted("test_deleting_an_double_element_from_the_queue");
	setup();
		test_deleting_an_double_element_from_the_queue();
	tearDown();
	testEnded();
	testStarted("test_deleting_an_String_element_from_the_queue");
	setup();
		test_deleting_an_String_element_from_the_queue();
	tearDown();
	testEnded();
	testStarted("test_deleting_an_String_element_from_the_queue_fail");
	setup();
		test_deleting_an_String_element_from_the_queue_fail();
	tearDown();
	testEnded();
	testStarted("test_deleting_an_element_when_queue_is_empty");
	setup();
		test_deleting_an_element_when_queue_is_empty();
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
