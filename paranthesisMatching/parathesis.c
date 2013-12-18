#include "parathesis.h"
#include "C:/Users/pallavig/Dropbox/step_pallavi/cWorkspace/arrayUtil/arrayUtilLib.h"
#include "C:/Users/pallavig/Dropbox/step_pallavi/cWorkspace/stack/Stack.h"
#include <string.h>

ArrayUtil initialize(){
	ArrayUtil util = create(sizeof(char),6);
	char *actual = (char*)util.base;
	actual[0] = '{';
	actual[1] = '(';
	actual[2] = '[';
	actual[3] = '}';
	actual[4] = ')';
	actual[5] = ']';
	return util;
}

int areParanthesisCorrect(char* data){
	ArrayUtil util = initialize();
	char *actual = (char*)util.base;
	char ch;
	int length = strlen(data);
	int i,found,res;
	char* topElement;
	Stack *stack = New(sizeof(char),20);
	for(i=0;i<length;i++){
		ch = data[i];
		found = findIndex(util,&ch);
		if(found>-1 && found<3)
			res = push(stack,&ch);
		if(found>=3 && found<6){
			topElement = (char*)top(stack);
			if(topElement != NULL){
				if(*topElement == actual[found-3]){
					topElement = (char*)pop(stack);
				}
				else{
					dispose(util);
					disposeStack(stack);
					return 0;
				}
			}
			else
				return 0;
		}
	}
	if(isEmpty(stack)){
		dispose(util);
		disposeStack(stack);
		return 1;
	}
	dispose(util);
	disposeStack(stack);
	return 0;
}