#include "Tree.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
	Tree t = Tree_new(14);
	Tree_insertSorted(t, 7);
	Tree_insertSorted(t, 26);
	Tree_insertSorted(t, 17);
	Tree_insertSorted(t, 18);
	Tree_insertSorted(t, 27);
	Tree_insertSorted(t, 5);
	Tree_insertSorted(t, 10);
	Tree_insertSorted(t, 12);
	Tree_insertSorted(t, 15);
	Tree_printInorder(t);
	putchar('\n');
	//printf("depth: %i\n", Tree_depth(t));
	Tree_display(t, 2);
	return 0;
}