#pragma once

typedef int TYPE;
typedef struct TreeImpl *Tree;

Tree Tree_new(TYPE data);
int Tree_insertSorted(Tree tree, TYPE data);
void Tree_printInorder(Tree tree);
int Tree_depth(Tree tree);
void Tree_display(Tree tree, int numberLength);