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
			tree->right = temp;
			return 1;
		}else{
			return Tree_insertSorted(tree->right, data);
		}
	}else{
		if(tree->left == NULL){
			Tree temp = Tree_new(data);
			//printf("leftInsert %i\n", data);
			tree->left = temp;
			return 1;
		}else{
			return Tree_insertSorted(tree->left, data);
		}
	}
}

int Tree_contains(Tree tree, TYPE data){
	if(tree->value == data){
		return 1;
	}
	if(tree->value < data){
		return Tree_contains(tree->right, data);
	}else{
		return Tree_contains(tree->left, data);
	}
}

void Tree_printInorder(Tree tree){
	if(tree->left != NULL) Tree_printInorder(tree->left);
	printf("%i, ", tree->value);
	if(tree->right != NULL) Tree_printInorder(tree->right);
}

void Tree_printPostorder(Tree tree){
	if(tree->left != NULL) Tree_printPostorder(tree->left);
	if(tree->right != NULL) Tree_printPostorder(tree->right);
	printf("%i, ", tree->value);
}

void Tree_printPreorder(Tree tree){
	printf("%i, ", tree->value);
	if(tree->left != NULL) Tree_printPreorder(tree->left);
	if(tree->right != NULL) Tree_printPreorder(tree->right);
}

int Tree_depth(Tree tree){
	//printf("depth: %i\n", tree->value);
	int leftD = 0, rightD = 0;
	if(tree->left != NULL) {
		leftD = Tree_depth(tree->left);
	}
	if(tree->right != NULL) {
		rightD = Tree_depth(tree->right);
	}
	//printf("node: %i, left %i, right %i\n", tree->value, leftD, rightD);
	return 1 + (leftD > rightD? leftD : rightD);
}

typedef struct qNode{
	struct qNode *next;
	Tree value;
}qNode;

typedef struct Queue{
	qNode *head;
	qNode *tail;
}Queue;

Queue* Queue_new(){
	Queue *temp = malloc(sizeof(Queue));
	temp->head = NULL;
	temp->tail = NULL;
	return temp;
}

void Queue_add(Queue *q, Tree t){
	qNode *n = malloc(sizeof(qNode));
	n->next = NULL;
	n->value = t;
	if(!q->tail){
		q->head = n;
		q->tail = n;
	}else{
		q->tail->next = n;
		q->tail = n;
	}
}

Tree Queue_pop(Queue *q){
	if(!q->head) return NULL;
	qNode *n = q->head;
	if(q->head == q->tail){
		q->head = NULL;
		q->tail = NULL;
	}else{
		q->head = n->next;
	}
	Tree t = n->value;
	free(n);
	return t;
}

void Tree_levelorder(Tree tree){
	Queue *q = Queue_new();
	Queue_add(q, tree);
	while(q->head != NULL){
		Tree t = Queue_pop(q);
		if(t != NULL){
			printf("%i ", t->value);
			Queue_add(q, t->left);
			Queue_add(q, t->right);
		}
	}
}