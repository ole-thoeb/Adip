#include "Array_util.h"
#include <assert.h>
#include <stdio.h>

int fun(int it){
	return it * 2;
}

int charToInt(void *element){
	char c = *((char*)element);
	return (int)c;
}

int main(int argc, char const *argv[]){
	int *arg = Array_new(10, fun);
	Array_print(arg, 10);
	int arg2[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
	assert(1 == Array_equals(arg, 10, arg2, 10));
	int *argMap = Array_map(arg, 10, fun);
	Array_transform(arg, 10, fun);
	Array_print(arg, 10);
	Array_print(argMap, 10);
	printf("%i\n", Array_sum(arg, 10));
	char arg3[5] = {'a', 'b', 'c', 'd', 'e'};
	printf("%i\n", Array_sumBy(arg3, 5, sizeof(char), charToInt));
	return 0;
}
