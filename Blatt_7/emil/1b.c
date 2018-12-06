#include "List.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
	List l = List_new();
	List_insert(l, 2.0, 0);
	List_prepend(l, 1.234);
	List_insert(l, 3.3423, 1);
	List_append(l, 4.2342);
	List_insert(l, 6.2342, 2);
	List_delete(l, 4);
	List_print(l);
	List_printBack(l);
	List l2 = List_reversCon(l);
	List_print(l2);
	List_revers(l);
	printf("%lf\n", List_get(l, 1));
	List_print(l);
	return 0;
}
