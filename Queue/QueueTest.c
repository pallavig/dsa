#include "testUtils.h"
#include "Queue.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareQueue(Queue* actual,Queue* expected){
	return (actual->elementSize == expected->elementSize) && 
	(actual->queueCapacity == expected->queueCapacity) &&
	(actual->rear == expected->rear) && 
	(0 == memcmp(expected->base,actual->base,expected->queueCapacity*expected->elementSize));
}

//------------------------create---------------------------

void test_creation_of_queue_with_integers(){
	Queue* actual = create(sizeof(int),3);
	int exp_arr[] = {0,0,0};
	Queue expected = {exp_arr,-1,3,sizeof(int)};
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
}

void test_creation_of_queue_with_characters(){
	Queue* actual = create(sizeof(char),3);
	char exp_arr[] = {0,0,0};
	Queue expected = {exp_arr,-1,3,sizeof(char)};
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
}

void test_creation_of_queue_with_floats(){
	Queue* actual = create(sizeof(float),3);
	float exp_arr[] = {0.0f,0.0f,0.0f};
	Queue expected = {exp_arr,-1,3,sizeof(float)};
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
}

void test_creation_of_queue_with_doubles(){
	Queue* actual = create(sizeof(double),3);
	double exp_arr[] = {0.0,0.0,0.0};
	Queue expected = {exp_arr,-1,3,sizeof(double)};
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
}

void test_creation_of_queue_with_Strings(){
	Queue* actual = create(sizeof(String),3);
	String exp_arr[] = {"","",""};
	Queue expected = {exp_arr,-1,3,sizeof(String)};
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
}

//-------------------------isFull-------------------------------

void test_user_should_be_informed_when_stack_is_full(){
	int arr[] = {10,10,10};
	Queue queue = {arr,2,3,sizeof(int)};
	int res = isFull(&queue);
	ASSERT(1 == res);
};

void test_user_should_be_informed_when_stack_is_not_full(){
	int arr[] = {10,10,0};
	Queue queue = {arr,1,3,sizeof(int)};
	int res = isFull(&queue);
	ASSERT(0 == res);
};

//-----------------------------inserting----------------------

void test_inserting_an_integer_element_in_queue(){
	Queue* actual = create(sizeof(int),3);
	int element = 10;
	int exp_arr[] = {element,0,0};
	int res = enQueue(actual,&element);
	Queue expected = {exp_arr,0,3,sizeof(int)};
	ASSERT(res == 1);
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
}

void test_inserting_an_character_element_in_queue(){
	Queue* actual = create(sizeof(char),3);
	char element = 'a';
	char exp_arr[] = {element,0,0};
	int res = enQueue(actual,&element);
	Queue expected = {exp_arr,0,3,sizeof(char)};
	ASSERT(res == 1);
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
}

void test_inserting_an_float_element_in_queue(){
	Queue* actual = create(sizeof(float),3);
	float element = 10.0f;
	float exp_arr[] = {element,0.0f,0.0f};
	int res = enQueue(actual,&element);
	Queue expected = {exp_arr,0,3,sizeof(float)};
	ASSERT(res == 1);
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
};

void test_inserting_an_String_element_in_queue(){
	Queue* actual = create(sizeof(String),3);
	char element[256] = "abc";
	char exp_arr[][256] = {"abc","",""};
	int res = enQueue(actual,&element);
	Queue expected = {exp_arr,0,3,sizeof(String)};
	ASSERT(res == 1);
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
};

void test_inserting_an_element_when_queue_is_full(){
	Queue* queue = create(sizeof(float),3);
	float element = 10.0f;
	int res = enQueue(queue,&element);
	res = enQueue(queue,&element);
	res = enQueue(queue,&element);
	res = enQueue(queue,&element);
	ASSERT(res == 0);
	ASSERT(queue->rear == 2);
	dispose(queue);
};

//---------------------isEmpty----------------------------

void test_user_should_be_informed_when_queue_is_empty(){
	int arr[] = {0,0,0};
	Queue queue = 	{arr,-1,3,sizeof(int)};
	int res = isEmpty(&queue);
	ASSERT(1 == res);
}

void test_user_should_be_informed_when_queue_is_not_empty(){
	int arr[] = {0,0,0};
	Queue queue = 	{arr,0,3,sizeof(int)};
	int res = isEmpty(&queue);
	ASSERT(0 == res);
}

//------------------deleting------------------------------

void test_deleting_an_integer_element_from_queue(){
	Queue* actual = create(sizeof(int),3);
	int exp_arr[] = {20,30,30};
	Queue expected = {exp_arr,1,3,sizeof(int)};
	int element1 = 10,element2= 20,element3=30;
	int* firstElement;
	int res = enQueue(actual,&element1);
	res = enQueue(actual,&element2);
	res = enQueue(actual,&element3);
	firstElement = (int*)deQueue(actual);
	ASSERT(element1 == *firstElement);
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
};

void test_deleting_an_character_element_from_the_queue(){
	Queue* actual = create(sizeof(char),3);
	char exp_arr[] ={'b',0,0};
	Queue expected = {exp_arr,0,3,sizeof(char)};
	char i;
	char element1 = 'a';
	char element2 = 'b';
	char* firstElement;
	int res = enQueue(actual,&element1);
	res = enQueue(actual,&element2);
	firstElement = deQueue(actual);
	ASSERT(element1 == *firstElement);
	ASSERT(actual->rear == 0);
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
};

void test_deleting_an_float_element_from_the_queue(){
	Queue* actual = create(sizeof(float),3);
	float exp_arr[] ={0.0f,0.0f,0.0f};
	Queue expected = {exp_arr,-1,3,sizeof(float)};
	float i;
	float element1 = 10.5f;
	float* firstElement;
	int res = enQueue(actual,&element1);
	firstElement = deQueue(actual);
	ASSERT(element1 == *firstElement);
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
};

void test_deleting_an_double_element_from_the_queue(){
	Queue* actual = create(sizeof(double),3);
	double exp_arr[] ={0.0,0.0,0.0};
	Queue expected = {exp_arr,-1,3,sizeof(double)};
	double i;
	double element1 = 10.5;
	double* firstElement;
	int res = enQueue(actual,&element1);
	firstElement = deQueue(actual);
	ASSERT(element1 == *firstElement);
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
};

void test_deleting_an_String_element_from_the_queue(){
	Queue* actual = create(sizeof(String),3);
	String exp_arr[] ={"","",""};
	Queue expected = {exp_arr,-1,3,sizeof(String)};
	String i;
	String element1 = "abc";
	String* firstElement;
	int res = enQueue(actual,&element1);
	firstElement = deQueue(actual);
	ASSERT(0 == strcmp("abc",*firstElement));
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
};

void test_deleting_an_String_element_from_the_queue_fail(){
	Queue* actual = create(sizeof(String),3);
	String exp_arr[] ={"","",""};
	Queue expected = {exp_arr,-1,3,sizeof(String)};
	String i;
	String element1 = "abc";
	String* firstElement;
	int res = enQueue(actual,&element1);
	firstElement = deQueue(actual);
	ASSERT(0 == strcmp(element1,*firstElement));
	ASSERT(compareQueue(actual,&expected));
	dispose(actual);
};

void test_deleting_an_element_when_queue_is_empty(){
	Queue* queue = create(sizeof(int),1);
	int* firstElement;
	firstElement = deQueue(queue);
	ASSERT(firstElement == NULL);
};