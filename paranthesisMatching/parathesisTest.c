#include "testUtils.h"
#include "parathesis.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_w(){
	char data[] = "{if(a==2){printf(a);}}";
	ASSERT(areParanthesisCorrect(data));
};

void test_when_parathesis_are_incorrect(){
	char data[] = "{if(a==2){printf(a)}";
	ASSERT(0 == areParanthesisCorrect(data));
};

void test_for_rectangular_braces(){
	char data[] = "if(done using stack){go to 4 line}}[@]";
	ASSERT(0 == areParanthesisCorrect(data));
};