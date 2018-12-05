#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

struct TreeImpl{
	Tree left;
	Tree right;
	TYPE value;
}TreeImpl;

Tree Tree_new(TYPE data){
	Tree tree = malloc(sizeof(struct TreeImpl));
	tree->left = NULL;
	tree->right = NULL;
	tree->value = data;
	return tree;
}

int Tree_insertSorted(Tree tree, TYPE data){
	if (tree->value < data){
		if(tree->right == NULL){
			Tree temp = Tree_new(data);
			temp->right = temp;
			return 1;
		}else{
			return Tree_insertSorted(tree->right, data);
		}
	}else{
		if(tree->left == NULL){
			Tree temp = Tree_new(data);
			temp->left = temp;
			return 1;
		}else{
			return Tree_insertSorted(tree->left, data);
		}
	}
}