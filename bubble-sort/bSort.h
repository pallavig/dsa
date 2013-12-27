typedef int (*compareFunc)(void *first,void *second);
void bSort(void **base,int numberOfElements,compareFunc compare);