typedef int (*CompareFunc)(void *first,void *second);
void mSort(void **base,int start,int end,int length,CompareFunc compare);