#include <stdlib.h>

#pragma once

typedef int TYPE;
struct DynArrayImpl;
typedef struct DynArrayImpl *DynArray;

DynArray DynArray_new(size_t capacity);
void DynArray_delete(DynArray vector);
int DynArray_add(DynArray vector, TYPE val);
TYPE DynArray_get(DynArray vector, size_t index);
void DynArray_set(DynArray vector, size_t index, TYPE value);
size_t DynArray_size(DynArray vector);
void DynArray_print(DynArray vector);