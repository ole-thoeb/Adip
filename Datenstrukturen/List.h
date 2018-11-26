#pragma once

typedef int TYPE;
typedef struct ListImpl *List;

List List_new();
int List_insert(List list, TYPE data, int position);
int List_append(List list, TYPE data);
int List_prepend(List list, TYPE data);
void List_print(List list);
void List_delete(List list);