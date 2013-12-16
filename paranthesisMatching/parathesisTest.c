#include "testUtils.h"
#include "parathesis.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_matching_parenthesis_for_round_brackets(){
    char data[] = "()";
    ASSERT(areParanthesisCorrect(data));
};

void test_matching_parenthesis_for_rectangular_brackets(){
    char data[] = "[]";
    ASSERT(areParanthesisCorrect(data));
};

void test_matching_parenthesis_for_curly_brackets(){
    char data[] = "{}";
    ASSERT(areParanthesisCorrect(data));
};

void test_matching_parenthesis_with_an_extra_closing_brace(){
    char data[] = "())";
    ASSERT(0 ==  areParanthesisCorrect(data));
}

void test_matching_parenthesis_when_data_is_present(){
	char data[] = "{if(a==2){printf(a);}}";
	ASSERT(areParanthesisCorrect(data));
};

void test_when_parathesis_are_incorrect(){
	char data[] = "{if(a==2){printf(a)}";
	ASSERT(0 == areParanthesisCorrect(data));
};

void test_matching_parenthesis_when_none_are_present(){
	char data[] = "abcdefghijklmnopqrstuvwxyz";
	ASSERT(1 == areParanthesisCorrect(data));
};

void test_match_parenthesis_when_data_is_empty(){
	char data[] = "";
	ASSERT(1 == areParanthesisCorrect(data));
}

void test_matching_parenthesis_when_data_starts_with_closing_parenthesis(){
	char data[] = "}}}{{{";
	ASSERT(0 == areParanthesisCorrect(data));
};