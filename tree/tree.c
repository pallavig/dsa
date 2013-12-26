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

TreeNode* getTreeNode(List* list,void* parent,compareFunc cmp){
	TreeNode *tn;
	Iterator it = getIterator(list);
	while(it.hasNext(&it)){
		tn = it.next(&it);
		if(0 == cmp(tn->data,parent))
			return tn;
		if(tn->list)
			return getTreeNode(tn->list,parent,cmp);
	}
	return NULL;
};

TreeNode* traverse(void* tree,void *parent){
	TreeNode *treeNode = ((Tree*)tree)->root;
	if(0==((Tree*)tree)->compare(treeNode->data,parent))
		return treeNode;
	return getTreeNode(treeNode->list,parent,((Tree*)tree)->compare);
};

void* searchTreeNode(Tree *tree,void* parent){
	TreeNode* tn;
	tn = traverse(tree,parent);
	return tn;
};

int search(void* tree,void* parent){
	void *matchedNode = searchTreeNode(tree,parent);
	if(matchedNode) return 1;
	return 0;
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
	if(it->hasNext(it)){
		result = ((Node*)(it->current))->data;
		it->current = ((Node*)(it->current))->next;
	}
	if(result)
		return result->data;
	return result;
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
	it.list = matchedNode->list;
	if(it.list == NULL) it.current = NULL;
	else it.current = ((List*)it.list)->head;
	it.next = getCurrentTreeNode;
	it.hasNext = hasCurrentTreeNode;
	return it;
};

int getIndex(List* list,void* data,compareFunc cmp){
	int i = 0;
	TreeNode *tn;
	Iterator it = getIterator(list);
	while(it.hasNext(&it)){
		i = i + 1;
		tn = (TreeNode*)it.next(&it);
		if(0 == cmp(tn->data,data))
			return i;
	}
	return i;
};

int removeTreeNode(Tree *tree,void* data){
	TreeNode *matchedNode = searchTreeNode(tree,data);
	List* list;
	int index;
	if(!matchedNode) return 0;
	list = matchedNode->parent->list;
	index = getIndex(list,data,tree->compare);
	remove(list,index);
	return 1;
};