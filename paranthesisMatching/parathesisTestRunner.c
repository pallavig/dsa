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

	testStarted("test_matching_parenthesis_for_round_brackets");
	setup();
		test_matching_parenthesis_for_round_brackets();
	tearDown();
	testEnded();
	testStarted("test_matching_parenthesis_for_rectangular_brackets");
	setup();
		test_matching_parenthesis_for_rectangular_brackets();
	tearDown();
	testEnded();
	testStarted("test_matching_parenthesis_for_curly_brackets");
	setup();
		test_matching_parenthesis_for_curly_brackets();
	tearDown();
	testEnded();
	testStarted("test_matching_parenthesis_with_an_extra_closing_brace");
	setup();
		test_matching_parenthesis_with_an_extra_closing_brace();
	tearDown();
	testEnded();
	testStarted("test_matching_parenthesis_when_data_is_present");
	setup();
		test_matching_parenthesis_when_data_is_present();
	tearDown();
	testEnded();
	testStarted("test_when_parathesis_are_incorrect");
	setup();
		test_when_parathesis_are_incorrect();
	tearDown();
	testEnded();
	testStarted("test_matching_parenthesis_when_none_are_present");
	setup();
		test_matching_parenthesis_when_none_are_present();
	tearDown();
	testEnded();
	testStarted("test_match_parenthesis_when_data_is_empty");
	setup();
		test_match_parenthesis_when_data_is_empty();
	tearDown();
	testEnded();
	testStarted("test_matching_parenthesis_when_data_starts_with_closing_parenthesis");
	setup();
		test_matching_parenthesis_when_data_starts_with_closing_parenthesis();
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
