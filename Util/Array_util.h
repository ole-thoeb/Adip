#pragma once

//returns array of given size. entsInitialised with function
int* Array_new(int size, int (*function)(int index));
//prints array to console
void Array_print(int *array, int size);
//returns 1 if the two array contain the same elements in the same order, 0 otherwise.
int Array_equals(int *array1, int size1, int *array2, int size2);
//applys the function on every element of the list
void Array_transform(int * array, int size, int (*function)(int element));
//returns a new array with the function applyed on all elements
int* Array_map(int * array, int size, int (*function)(int element));
//returns a new array with the function applyed on all elements.
//transform function also has Index of element transformed
int* Array_mapWithIndex(int * array, int size, int (*function)(int element, int index));
//returns sum of all elements
int Array_sum(int *array, int size);
//return sum of all elements given by the sumFunction
int Array_sumBy(void *array, int size, int typeSize, int (*sumFunction)(void *element));