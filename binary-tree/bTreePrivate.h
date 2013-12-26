#ifndef _TREE
#define _TREE
typedef struct binaryTreeNode{
	void* data;
	struct binaryTreeNode* left;
	struct binaryTreeNode* right;
} BinaryTreeNode;
#endif