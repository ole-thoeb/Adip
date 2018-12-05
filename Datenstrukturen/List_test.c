#include <stdio.h>
#include "List.h"

int main(int argc, char const *argv[]){
	List l = List_new();
	List_append(l, 2);
	List_prepend(l, 1);
	List_insert(l, 3, 1);
	List_append(l, 4);
	List_insert(l, 6, 2);
	List_print(l);
	List_delete(l);
	return 0;
}