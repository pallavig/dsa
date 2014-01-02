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

BSTreeNode* searchNode(BSTree *tree, void *parentData){
	BSTreeNode *root = tree->root;
	BSTree subTree;
	if(0 == tree->compare(root->data,parentData))
		return root;
	if(0 < tree->compare(root->data,parentData)){
		subTree.compare = tree->compare;
		subTree.root = root->left;
		return searchNode(&subTree,parentData);
	}
	if(0 > tree->compare(root->data,parentData)){
		subTree.compare = tree->compare;
		subTree.root = root->right;
		return searchNode(&subTree,parentData);	
	}
	return NULL;
};

void *getLeft(BSTree *tree, void *parentData){
	BSTreeNode *node = searchNode(tree,parentData);
	BSTreeNode *matchedNode = node->left;
	return matchedNode->data; //if left is null
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