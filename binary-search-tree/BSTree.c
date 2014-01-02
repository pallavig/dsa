#include "BSTree.h"
#include <stdlib.h>

typedef struct bstreenode{
	void *data;
	struct bstreenode *left;
	struct bstreenode *right;
	struct bstreenode *parent;
} BSTreeNode;

BSTree createBinarySearchTree(CompareFunc compare) {
	BSTree BStree;
	BStree.root = NULL;
	BStree.compare = compare;
	return BStree;
};

BSTreeNode* createBinarySearchTreeNode(void *data){
	BSTreeNode *node = calloc(1,sizeof(BSTreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
};

BSTreeNode* searchSpecificNode(BSTreeNode *node,void *parentData,CompareFunc compare){
	if(0 == compare(node->data,parentData))
		return node;
	if(0 < compare(node->data,parentData)){
		return searchSpecificNode(node->left,parentData,compare);
	}
	if(0 > compare(node->data,parentData)){
		return searchSpecificNode(node->right,parentData,compare);
	}
	return NULL;
};

BSTreeNode* searchNode(BSTree *tree, void *parentData){
	BSTreeNode *root = tree->root;
	return searchSpecificNode(tree->root,parentData,tree->compare);
};

void *getLeft(BSTree *tree, void *parentData){
	BSTreeNode *node = searchNode(tree,parentData);
	BSTreeNode *matchedNode = node->left;
	return matchedNode->data; //if left is null
};

int search(BSTree *tree,void *data){
	return (searchNode(tree,data))?1:0;
};

void *getRight(BSTree *tree, void *parentData){
	BSTreeNode *node = searchNode(tree,parentData);
	BSTreeNode *matchedNode = node->right;
	return matchedNode->data; //if right is null
};

int insertNode(BSTreeNode *subtree,BSTreeNode *node,CompareFunc compare){
	if(0 > compare(subtree->data,node->data)){
		if(subtree->right)
			return insertNode(subtree->right,node,compare);
		subtree->right = node;
		return 1;
	}
	if(0 < compare(subtree->data,node->data)){
		if(subtree->left)
			return insertNode(subtree->left,node,compare);
		subtree->left = node;
		return 1;
	}
	return 0;
};

int insert(BSTree* tree,void *data){
	BSTreeNode *node = createBinarySearchTreeNode(data);
	if(tree->root == NULL) {
		tree->root = node;
		return 1;
	}
	return insertNode(tree->root,node,tree->compare);
};