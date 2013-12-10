typedef const void* ConstVoidPtr;
ConstVoidPtr bsearch(ConstVoidPtr key,ConstVoidPtr base,int nitems,int size,int (*compare)(ConstVoidPtr,ConstVoidPtr));