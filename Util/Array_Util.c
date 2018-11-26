#include <stdio.h>
#include <stdlib.h>
#include "Array_util.h"

int* Array_new(int size, int (*function) (int)){
	int *array = malloc(size * sizeof(int));
	for(size_t i = 0; i < size; i++){
		array[i] = function(i);
	}
	return array;
}

void Array_print(int *array, int size){
	for(size_t i = 0; i < size; i++){
		if (i != 0) {
			printf(", ");
		}
		printf("%i", array[i]);
	}
	putchar('\n');
}

int Array_equals(int *array1, int size1, int *array2, int size2){
	if (size1 != size2) return 0;
	
	for(size_t i = 0; i < size1; i++)
		if (array1[i] != array2[i]) return 0;

	return 1;
}

int* Array_map(int * array, int size, int (*function)(int)){
	int *newArg = malloc(size * sizeof(int));
	for(size_t i = 0; i < size; i++){
		newArg[i] = function(array[i]);
	}
	return newArg;
}

int* Array_mapWithIndex(int * array, int size, int (*function)(int, int)){
	int *newArg = malloc(size * sizeof(int));
	for(size_t i = 0; i < size; i++){
		newArg[i] = function(array[i], i);
	}
	return newArg;
}

void Array_transform(int * array, int size, int (*function)(int)){
	for(size_t i = 0; i < size; i++){
		array[i] = function(array[i]);
	}
}

int Array_sum(int *array, int size){
	int sum = 0;
	for(size_t i = 0; i < size; i++){
		sum += array[i];
	}
	return sum;
}

int Array_sumBy(void *array, int size, int typeSize, int (*sumFunction)(void*)){
	int sum = 0;
	for(size_t i = 0; i < size; i++){
		sum += sumFunction(array + (i * typeSize));
	}
	return sum;
}