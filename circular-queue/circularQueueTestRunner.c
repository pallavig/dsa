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

	testStarted("test_creation_of_integer_circular_queue");
	setup();
		test_creation_of_integer_circular_queue();
	tearDown();
	testEnded();
	testStarted("test_creation_of_character_circular_queue");
	setup();
		test_creation_of_character_circular_queue();
	tearDown();
	testEnded();
	testStarted("test_creation_of_float_circular_queue");
	setup();
		test_creation_of_float_circular_queue();
	tearDown();
	testEnded();
	testStarted("test_creation_of_double_circular_queue");
	setup();
		test_creation_of_double_circular_queue();
	tearDown();
	testEnded();
	testStarted("test_creation_of_String_circular_queue");
	setup();
		test_creation_of_String_circular_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_an_integer_element_in_circular_queue");
	setup();
		test_inserting_an_integer_element_in_circular_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_an_character_element_in_circular_queue");
	setup();
		test_inserting_an_character_element_in_circular_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_an_float_element_in_circular_queue");
	setup();
		test_inserting_an_float_element_in_circular_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_an_double_element_in_circular_queue");
	setup();
		test_inserting_an_double_element_in_circular_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_an_String_element_in_circular_queue");
	setup();
		test_inserting_an_String_element_in_circular_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_elements_equal_to_size_of_queue");
	setup();
		test_inserting_elements_equal_to_size_of_queue();
	tearDown();
	testEnded();
	testStarted("test_user_should_be_informed_when_queue_is_full");
	setup();
		test_user_should_be_informed_when_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_check_full_stack_when_front_is_not_pointing_to_first_element_of_array");
	setup();
		test_check_full_stack_when_front_is_not_pointing_to_first_element_of_array();
	tearDown();
	testEnded();
	testStarted("test_it_should_not_allow_to_insert_an_element_when_stack_is_full");
	setup();
		test_it_should_not_allow_to_insert_an_element_when_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_deleting_an_element_from_the_queue");
	setup();
		test_deleting_an_element_from_the_queue();
	tearDown();
	testEnded();
	testStarted("test_ensuring_circular_behaviour_of_queue");
	setup();
		test_ensuring_circular_behaviour_of_queue();
	tearDown();
	testEnded();
	testStarted("test_to_check_behaviour_when_deleting_all_elements");
	setup();
		test_to_check_behaviour_when_deleting_all_elements();
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

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
