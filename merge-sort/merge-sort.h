typedef int (*CompareFunc)(void *first,void *second);
void mSort(void **base,int length,CompareFunc compare);