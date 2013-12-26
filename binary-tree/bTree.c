#include "bTree.h"
#include "bTreePrivate.h"
#include <stdlib.h>

BinaryTree createBinaryTree(CompareFunc cmp){
	BinaryTree tree;
	tree.root = NULL;
	tree.cmp = cmp;
	return tree;
};

BinaryTreeNode* createBinaryTreeNode(void* data){
	BinaryTreeNode *node = calloc(1,sizeof(BinaryTreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
};

BinaryTreeNode* search(BinaryTreeNode* treenode,void* data,CompareFunc cmp){
	BinaryTreeNode *left,*right;
	printf("-->%d\n**%d\n",*(int*)treenode->data,*(int*)data);
	if(0 == cmp(treenode->data,data)){
		return treenode;
	}
	if(!treenode->left && !treenode->right)
		return NULL;
	return search(treenode->left,data,cmp);
	printf("Entred\n");
	return search(treenode->right,data,cmp);
};

void* getLeft(BinaryTree* tree,void* parent){
	BinaryTreeNode *root = tree->root;
	BinaryTreeNode *matchedNode;
	matchedNode = search(root,parent,tree->cmp);
	printf("%p\n",matchedNode->left);
	return ((BinaryTreeNode*)matchedNode->left)->data;
};

void* getRight(BinaryTree* tree,void* parent){
	BinaryTreeNode *root = tree->root;
	BinaryTreeNode *matchedNode;
	matchedNode = search(root,parent,tree->cmp);
	return ((BinaryTreeNode*)matchedNode->right)->data;
};

int insert(BinaryTree* tree,void *data,void *parent){
	BinaryTreeNode* node = createBinaryTreeNode(data);
	BinaryTreeNode *parentNode;
	BinaryTreeNode *root = tree->root;
	if(root == NULL){
		tree->root = node;
		return 1;
	}
	parentNode = search(root,parent,tree->cmp);
	printf("%p\n",parentNode);
	if(parentNode->left == NULL){
		parentNode->left = node;
		return 1;
	}
	if(parentNode->right == NULL){
		parentNode->right = node;
		return 1;
	}
	return 0;
};