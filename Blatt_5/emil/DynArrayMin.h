#include <stdlib.h>

#pragma once

typedef int TYPE;
struct DynArrayMinImpl;
typedef struct DynArrayMinImpl *DynArrayMin;

DynArrayMin DynArrayMin_new(size_t capacity);
void DynArrayMin_delete(DynArrayMin vector);
int DynArrayMin_add(DynArrayMin vector, TYPE val);
TYPE DynArrayMin_get(DynArrayMin vector, size_t index);
void DynArrayMin_set(DynArrayMin vector, size_t index, TYPE value);
size_t DynArrayMin_size(DynArrayMin vector);
void DynArrayMin_print(DynArrayMin vector);