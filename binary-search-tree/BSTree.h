typedef int (*CompareFunc)(void *first,void *second);

typedef struct {
	void *root;
	CompareFunc compare;
} BSTree;

BSTree createBinarySearchTree(CompareFunc compare);
int insert(BSTree *tree,void *data);
void* getLeft(BSTree *tree,void *parentData);
void* getRight(BSTree *tree,void *parentData);
int search(BSTree *tree,void *data);
int remove(BSTree *tree,void *data);