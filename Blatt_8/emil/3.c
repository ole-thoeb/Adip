#include "Tree.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
	Tree t = Tree_new(6);
	Tree_insertSorted(t, 3);
	Tree_insertSorted(t, 9);
	Tree_insertSorted(t, 5);
	Tree_insertSorted(t, 7);
	Tree_insertSorted(t, 1);
	Tree_insertSorted(t, 10);
	
	Tree_printInorder(t);
	putchar('\n');
	Tree_printPostorder(t);
	putchar('\n');
	Tree_printPreorder(t);
	putchar('\n');

	Tree_levelorder(t);
	putchar('\n');
	puts("done");

	return 0;
}
