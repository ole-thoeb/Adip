#include "DynArray.h"
#include "DynArrayMin.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
	DynArray dArg = DynArray_new(4);

	for(size_t i = 0; i < 60; i++){
		DynArray_add(dArg, 60-i);
	}
	
	DynArray_print(dArg);

	return 0;
}