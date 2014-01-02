#include "BSTree.h"
#include <stdlib.h>

typedef struct bstreenode{
	void *data;
	struct bstreenode *left;
	struct bstreenode *right;
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
	if(0 < compare(node->data,parentData) && node->left !=NULL)
		return searchSpecificNode(node->left,parentData,compare);
	if(0 > compare(node->data,parentData) && node->right !=NULL)
		return searchSpecificNode(node->right,parentData,compare);
	return NULL;
};

BSTreeNode* searchNode(BSTree *tree, void *parentData){
	BSTreeNode *root;
	if(tree->root == NULL) return NULL;
	root = tree->root;
	return searchSpecificNode(root,parentData,tree->compare);
};

void *getLeft(BSTree *tree, void *parentData){
	BSTreeNode *node = searchNode(tree,parentData);
	BSTreeNode *matchedNode = node->left;
	return matchedNode->data; //if left is null
};

int search(BSTree *tree,void *data){
	if(searchNode(tree,data)) return 1;
	return 0;
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

BSTreeNode* getParent(BSTreeNode* node,void *data,CompareFunc compare){
	BSTreeNode *left = node->left;
	BSTreeNode *right = node->right;
	if(left && 0 == compare(left->data,data))
		return node;
	if(right && 0 == compare(right->data,data))
		return node;
	if(0 < compare(node->data,data) && node->left !=NULL)
		return getParent(node->left,data,compare);
	if(0 > compare(node->data,data) && node->right !=NULL)
		return getParent(node->right,data,compare);
	return NULL;	
};

int isLeafNode(BSTreeNode *node){
	if(node->left == NULL && node->right == NULL)
		return 1;
	return 0;
};

int getNumberOfChildren(BSTreeNode *nodeToBeDeleted){
	int counter = 0;
	if(nodeToBeDeleted->left)
		counter++;
	if(nodeToBeDeleted->right)
		counter++;
	return counter;
};

int removeLeafNode(BSTreeNode *parent,BSTreeNode *nodeToBeDeleted,CompareFunc compare){
	int comparisonResult = compare(parent->data,nodeToBeDeleted->data);
	if (comparisonResult > 0)
		parent->left = NULL;
	else
		parent->right = NULL;
	free(nodeToBeDeleted);
	return 1;
};

BSTreeNode *getReplacementNode(BSTreeNode *nodeToBeDeleted,CompareFunc compare,BSTreeNode *parent){
	int numberOfChildren = getNumberOfChildren(nodeToBeDeleted);
	BSTreeNode *replacement;
	if(numberOfChildren == 1){
		if(nodeToBeDeleted->left)
			return nodeToBeDeleted->left;
		return nodeToBeDeleted->right;
	}
	if(numberOfChildren == 2){
		replacement = nodeToBeDeleted->left;
		while(replacement->right){
			replacement = replacement->right;
		}
		return replacement;
	}
	return NULL;
};

int removeWhenNodeHasOneChild(BSTreeNode *nodeToBeDeleted,BSTreeNode *parent,CompareFunc compare){
	BSTreeNode *replacementNode;
	replacementNode = getReplacementNode(nodeToBeDeleted,compare,parent);
	if(0 > compare(parent->data,nodeToBeDeleted->data))	
		parent->right = replacementNode;
	else
		parent->left = replacementNode;
	free(nodeToBeDeleted);
	return 1;
};

int removeWhenTwoChildren(BSTreeNode *nodeToBeDeleted,BSTreeNode *parent,CompareFunc compare){
	BSTreeNode *replacementNode;
	replacementNode = getReplacementNode(nodeToBeDeleted,compare,parent);
	if(0 > compare(parent->data,nodeToBeDeleted->data))
		parent->right = replacementNode;
	else
		parent->left = replacementNode;
	replacementNode->left = nodeToBeDeleted->left;
	replacementNode->right = nodeToBeDeleted->right;
	free(nodeToBeDeleted);
	return 1;
};

int remove(BSTree *tree,void *data){
	BSTreeNode *node = tree->root;
	BSTreeNode *nodeToBeDeleted;
	BSTreeNode *parent;
	BSTreeNode *replacementNode;
	int leafNode,numberOfNodes;
	int comparisonResult;
	if(0 == tree->compare(node->data,data)){
		free(tree->root);
		tree->root = NULL;
		return 1;
	}
	nodeToBeDeleted = searchNode(tree,data);
	parent = getParent(tree->root,data,tree->compare);
	leafNode = isLeafNode(nodeToBeDeleted);
	if(leafNode) //use getNumberOfChildren
		return removeLeafNode(parent,nodeToBeDeleted,tree->compare);
	numberOfNodes = getNumberOfChildren(nodeToBeDeleted);
	if(numberOfNodes == 1)
		return removeWhenNodeHasOneChild(nodeToBeDeleted,parent,tree->compare);
	return removeWhenTwoChildren(nodeToBeDeleted,parent,tree->compare);
	return 0;
};