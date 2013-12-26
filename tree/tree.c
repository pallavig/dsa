#include "tree.h"
#include "treePrivate.h"
#include "memory.h"
#include <stdlib.h>

Tree createTree(compareFunc cmp){
	Tree tree;
	tree.compare = cmp;
	tree.root = NULL;
	return tree;
};

TreeNode* createTreeNode(void* child){
	TreeNode *node = calloc(1,sizeof(TreeNode));
	node->data = child;
	node->list = NULL;
	node->parent = NULL;
	return node;
};

void* traverse(void* tree,Iterator* it,void *parent){
	TreeNode *treeNode = ((Tree*)tree)->root;
	TreeNode *result;
	TreeNode *finalResult;
	Iterator it1;
	TreeNode *tn;
	if(0==((Tree*)tree)->compare(treeNode->data,parent))
		return treeNode;
	while(it->hasNext(it)){
		tn = (TreeNode*)it->next(it);
		((Tree*)tree)->root = tn;
		it1 = getIterator(tn->list);
		return traverse(tree,&it1,parent);
	}
	return NULL;
};

void* searchTreeNode(Tree *tree,void* parent){
	Iterator it = getIterator(((TreeNode*)tree->root)->list);
	TreeNode* tn;
	tn = traverse(tree,&it,parent);
	return tn;
};

int insertTreeNode(Tree *tree,void *parent,void *child){
	TreeNode *node = createTreeNode(child);
	TreeNode *matchedTreeNode;
	List* list;
	if(parent == NULL){
		tree->root = node;
		return 1;
	}
	matchedTreeNode =  searchTreeNode(tree,parent);
	node->parent = matchedTreeNode;
	if(matchedTreeNode->list == NULL){
		list = create();//creation of list who will dispose it
		matchedTreeNode->list = list;
	}
	list = matchedTreeNode->list;
	insert(list,node,1);
	return 1;
};

void* getRootNode(Iterator* it){
	TreeNode *root = (TreeNode*)it->list;
	return root->data;
};

int hasCurrentTreeNode(Iterator* it){
	return ((Node*)(it->current)) != NULL;
};

void* getCurrentTreeNode(Iterator *it){
	TreeNode* result = NULL;
	if(it->hasNext(it))
		result = ((Node*)(it->current))->data;
	it->current = ((Node*)(it->current))->next;
	return result->data;
};

Iterator getChildren(Tree *tree,void* parent){
	Iterator it;
	TreeNode *matchedNode;
	if(parent == NULL){
		it.list = tree->root;
		it.current = NULL;
		it.hasNext = NULL; //has next should have some function definition
		it.next = getRootNode;
		return it;
	}
	matchedNode = searchTreeNode(tree,parent);
	printf("%p\n",matchedNode);
	it.list = matchedNode->list;
	if(it.list == NULL) it.current = NULL;
	else it.current = ((List*)it.list)->head;
	it.next = getCurrentTreeNode;
	it.hasNext = hasCurrentTreeNode;
	return it;
};