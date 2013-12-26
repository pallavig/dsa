#include "bTreePrivate.h"
typedef int (*CompareFunc)(void* first,void* second);
typedef struct {
	void *root;
	CompareFunc cmp;
} BinaryTree;

BinaryTree createBinaryTree(CompareFunc cmp);
int insert(BinaryTree* tree,void *data,void *parent);
BinaryTreeNode* search(BinaryTreeNode* treenode,void* data,CompareFunc cmp);
void* getLeft(BinaryTree* tree,void* parent);
void* getRight(BinaryTree* tree,void* parent);