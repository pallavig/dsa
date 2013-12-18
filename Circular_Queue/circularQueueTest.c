#include "testUtils.h"
#include "circularQueue.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareQueue(CircularQueue* actual,CircularQueue* expected){
	return (actual->typeSize == expected->typeSize) && 
	(actual->queueCapacity == expected->queueCapacity) &&
	(actual->rear == expected->rear) && 
	(actual->front == expected->front) && 
	(0 == memcmp(expected->base,actual->base,expected->queueCapacity*expected->typeSize));
}

void test_creation_of_integer_circular_queue(){
	CircularQueue* actual = create(sizeof(int),3);
	int exp_arr[] = {0,0,0};
	CircularQueue expected = {exp_arr,-1,-1,3,sizeof(int)};
	ASSERT(compareQueue(actual,&expected));
};

void test_creation_of_character_circular_queue(){
	CircularQueue* actual = create(sizeof(char),3);
	char exp_arr[] = {0,0,0};
	CircularQueue expected = {exp_arr,-1,-1,3,sizeof(char)};
	ASSERT(compareQueue(actual,&expected));
};

void test_creation_of_float_circular_queue(){
	CircularQueue* actual = create(sizeof(float),3);
	float exp_arr[] = {0.0f,0.0f,0.0f};
	CircularQueue expected = {exp_arr,-1,-1,3,sizeof(float)};
	ASSERT(compareQueue(actual,&expected));
};

void test_creation_of_double_circular_queue(){
	CircularQueue* actual = create(sizeof(double),3);
	double exp_arr[] = {0.0,0.0,0.0};
	CircularQueue expected = {exp_arr,-1,-1,3,sizeof(double)};
	ASSERT(compareQueue(actual,&expected));
};

void test_creation_of_String_circular_queue(){
	CircularQueue* actual = create(sizeof(String),3);
	String exp_arr[] = {"","",""};
	CircularQueue expected = {exp_arr,-1,-1,3,sizeof(String)};
	ASSERT(compareQueue(actual,&expected));
};

void test_inserting_an_integer_element_in_circular_queue(){
	CircularQueue* actual = create(sizeof(int),3);
	int element  = 10;
	int exp_arr[] = {element,0,0};
	CircularQueue expected = {exp_arr,0,0,3,sizeof(int)};
	int res = enQueue(actual,&element);
	ASSERT(1 == res);
	ASSERT(compareQueue(actual,&expected));
};

void test_inserting_an_character_element_in_circular_queue(){
	CircularQueue* actual = create(sizeof(char),3);
	char element  = 'a';
	char exp_arr[] = {element,0,0};
	CircularQueue expected = {exp_arr,0,0,3,sizeof(char)};
	int res = enQueue(actual,&element);
	ASSERT(1 == res);
	ASSERT(compareQueue(actual,&expected));
};

void test_inserting_an_float_element_in_circular_queue(){
	CircularQueue* actual = create(sizeof(float),3);
	float element  = 10.0f;
	float exp_arr[] = {element,0.0f,0.0f};
	CircularQueue expected = {exp_arr,0,0,3,sizeof(float)};
	int res = enQueue(actual,&element);
	ASSERT(1 == res);
	ASSERT(compareQueue(actual,&expected));
};

void test_inserting_an_double_element_in_circular_queue(){
	CircularQueue* actual = create(sizeof(double),3);
	double element  = 10.0f;
	double exp_arr[] = {element,0.0f,0.0f};
	CircularQueue expected = {exp_arr,0,0,3,sizeof(double)};
	int res = enQueue(actual,&element);
	ASSERT(1 == res);
	ASSERT(compareQueue(actual,&expected));
};

void test_inserting_an_String_element_in_circular_queue(){
	CircularQueue* actual = create(sizeof(String),3);
	String element  = "abc";
	String exp_arr[] = {"abc","",""}; // "abc" instead of element
	CircularQueue expected = {exp_arr,0,0,3,sizeof(String)};
	int res = enQueue(actual,&element);
	ASSERT(1 == res);
	ASSERT(compareQueue(actual,&expected));
};

void test_inserting_elements_equal_to_size_of_queue(){
	CircularQueue* cQueue = create(sizeof(int),2);
	int element1 = 10;
	int element2 = 20;
	int res = enQueue(cQueue,&element1);
	res = enQueue(cQueue,&element2);
	ASSERT(1 == res);
};

//-----------------------isFull-----------

void test_user_should_be_informed_when_queue_is_full(){
	int exp_arr[] = {10,0,0};
	CircularQueue cQueue = {exp_arr,0,2,3,sizeof(int)};
	int res = isFull(&cQueue);
	ASSERT(1 == res);
};

void test_check_full_stack_when_front_is_not_pointing_to_first_element_of_array(){
	int exp_arr[] = {10,0,0};
	CircularQueue cQueue = {exp_arr,2,1,3,sizeof(int)};
	int res = isFull(&cQueue);
	ASSERT(1 == res);
};

//------inserting when queue is full-----------

void test_it_should_not_allow_to_insert_an_element_when_stack_is_full(){
	int exp_arr[] = {10,0,0};
	CircularQueue cQueue = {exp_arr,0,2,3,sizeof(int)};
	int element = 10;
	int res = enQueue(&cQueue,&element);
	ASSERT(0 == res);
};

//----------------deQueue-------------------------

void test_deleting_an_element_from_the_queue(){
	int exp_arr[] = {10,20,0};
	CircularQueue expected = {exp_arr,1,1,3,sizeof(int)};
	CircularQueue* cQueue = create(sizeof(int),3);
	int element1 = 10;
	int element2 = 20;
	int* firstElement;
	int res = enQueue(cQueue,&element1);
	res = enQueue(cQueue,&element2);
	firstElement = deQueue(cQueue);
	ASSERT(10 == *firstElement);
	ASSERT(compareQueue(cQueue,&expected));
};

void test_ensuring_circular_behaviour_of_queue(){
	int i;
	float exp_arr[] = {40.0f,20.0f,30.0f};
	CircularQueue expected = {exp_arr,1,0,3,sizeof(float)};
	float element1 = 10.0f;
	float element2 = 20.0f;
	float element3 = 30.0f;
	float element4 = 40.0f;
	float* firstElement;
	CircularQueue* actual = create(sizeof(float),3);
	int res;
	res = enQueue(actual,&element1);
	res = enQueue(actual,&element2);
	res = enQueue(actual,&element3);
	ASSERT(1 == res);
	firstElement = deQueue(actual);
	res = enQueue(actual,&element4);
	ASSERT(1 == res);
	ASSERT(compareQueue(actual,&expected));
};

void test_to_check_behaviour_when_deleting_all_elements(){
	char exp_arr[] = {'a','b'};
	CircularQueue expected = {exp_arr,-1,-1,2,sizeof(char)};
	CircularQueue* actual = create(sizeof(char),2);
	char element1 = 'a';
	char element2 = 'b';
	char* firstElement;
	int res;
	res = enQueue(actual,&element1);
	res = enQueue(actual,&element2);
	firstElement = deQueue(actual);
	firstElement = deQueue(actual);
	ASSERT(compareQueue(actual,&expected));
};

//---------------isEmpty-----------------------

void test_user_should_be_informed_when_queue_is_empty(){
	CircularQueue *actual = create(sizeof(int),3);
	int res = isEmpty(actual);
	ASSERT(1 == res);	
};

void test_user_should_be_informed_when_queue_is_not_empty(){
	int exp_arr[] = {0,0,0};
	CircularQueue expected = {exp_arr,0,0,2,sizeof(int)};
	int res = isEmpty(&expected);
	ASSERT(0 == res);
};