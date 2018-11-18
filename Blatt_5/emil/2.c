#include "DynArray.h"
#include "DynArrayMin.h"
#include "IntVector.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
	IntVector iv = IntVector_new(1);
	for(int i = 0; i < 100; i++){
		if(IntVector_push_back(iv, i)){
			puts("fehler");
			break;
		}
		printf("%i\n", IntVector_get(iv, i));
	}
	IntVector_print(iv);

	DynArray dyn = DynArray_new(1);
	
	for(int i = 0; i < 100; i++){
		if(DynArray_add(dyn, i)){
			puts("fehler");
			break;
		}
		printf("%i\n", DynArray_get(dyn, i));
	}
	DynArray_print(dyn);
	printf("%i\n", DynArray_size(dyn));
	
	for(int i = 0; i < 100; i++)
	{
		DynArray_set(dyn, i, i);
	}
	DynArray_print(dyn);
	
	puts("Min Array");
	DynArrayMin dynm = DynArrayMin_new(1);
	
	for(int i = 0; i < 100; i++)
	{
		DynArrayMin_add(dynm, i);
	}
	DynArrayMin_print(dynm);
	
	return 0;
}
