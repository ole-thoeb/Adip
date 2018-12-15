#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Tree.h"
#include "DynArray.h"

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

void Tree_printInorder(Tree tree){
	if(tree->left != NULL) Tree_printInorder(tree->left);
	printf("%i, ", tree->value);
	if(tree->right != NULL) Tree_printInorder(tree->right);
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

char nToS(int n){
	switch(n){
		case 0: return '0';
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		default: return 'e';
	}
}

int power(int x, int n){
    int k = 1;
    if(n == 0){
        return 1;
    }
    while(n > 1){
        if((n % 2) != 0){
            n--;
            k *= x;
        }else{
            n /= 2;
            x *= x;
        }
    }
    return x * k;
}

char* fixedNumberString(int n, int length){
	char *s = malloc((length  + 1)* sizeof(char));
	s[length] = 0;
	
	for(int i = 0; i < length; i++){
		int expo = power(10, length - 1 -i);
		int stelle = n / expo;
		if(stelle > 0) n %= (stelle * expo);
		s[i] = nToS(stelle);
	}
	
	return s;
}

char* fixedErrorString(int length){
	char *s = malloc((length  + 1)* sizeof(char));
	s[length] = 0;

	for(int i = 0; i < length; i++){
		s[i] = 'e';
	}
	
	return s;
}

typedef struct TreeArray{
	Tree *el;
	int size;
}TreeArray;

struct d2TreeArrayImpl{
	TreeArray **el;
	int size;
};

typedef struct d2TreeArrayImpl d2TreeArray;

void print2dArray(d2TreeArray *arg){
	for(size_t i = 0; i < arg->size; i++){
		for(size_t j = 0; j < arg->el[i]->size; j++){
			Tree t = arg->el[i]->el[j];
			if(t != NULL) printf("%i, ", t->value);
			else printf("0, ");
		}
		putchar('\n');
	}
}

d2TreeArray* Tree_asArray(Tree tree){
	int depth = Tree_depth(tree);
	
	d2TreeArray *arg = malloc(sizeof(struct d2TreeArrayImpl));
	arg->el = malloc(sizeof(TreeArray*) * depth);
	arg->size = depth;

	for(size_t i = 0; i < depth; i++){
		//puts("malloc");
		int amount = power(2, i);
		//printf("a %i\n", amount);
		TreeArray *targ = malloc(sizeof(TreeArray));
		targ->el = malloc(sizeof(Tree) * amount);
		//standartmäßig auf NULL setzten
		for(int k = 0; k < amount; k++)
			targ->el[k] = NULL;

		targ->size = amount;
		arg->el[i] = targ;
	}
	//print2dArray(arg);

	arg->el[0]->el[0] = tree;
	for(size_t i = 1; i < depth; i++){
		for(size_t j = 0; j < arg->el[i - 1]->size; j++){
			Tree t = arg->el[i - 1]->el[j];
			if (t != NULL) {
				arg->el[i]->el[2 * j] = t->left;
				arg->el[i]->el[2 * j + 1] = t->right;
			}
		}
	}
	//print2dArray(arg);
	return arg;
}

void Tree_display(Tree tree, int numberLength){
	int treeDepth = Tree_depth(tree);
	int half = (numberLength + 1) / 2;
	int factor = numberLength + 1;
	d2TreeArray *targ = Tree_asArray(tree);
	char* errorString = fixedErrorString(numberLength);

	for(int i = 0; i < treeDepth; i++){
		if(i != treeDepth - 1){
			for(int j = 0; j < factor * power(2 , treeDepth - i - 2) - half; j++){
				putchar('*');
			}
		}
		
		if(targ->el[i]->el[0] != NULL){
			char* s = fixedNumberString(targ->el[i]->el[0]->value, numberLength);
			printf("%s", s);
			free(s);
		}else{
			printf("%s", errorString);
		}

		for(int j = 1; j < targ->el[i]->size; j++){
			for(int k = 0; k < (factor * power(2 , treeDepth - i - 1)) - numberLength; k++){
				putchar('*');
			}
				
			if(targ->el[i]->el[j] != NULL){
				char* s = fixedNumberString(targ->el[i]->el[j]->value, numberLength);
				printf("%s", s);
				free(s);
			}else{
				printf("%s", errorString);
			}

		}
		putchar('\n');
	}

	free(errorString);
	for(size_t i = 0; i < targ->size; i++){
		free(targ->el[i]);
	}
	free(targ->el);
	free(targ);
}