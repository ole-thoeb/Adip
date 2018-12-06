#pragma once

typedef double TYPE;
typedef struct ListImpl *List;

List List_new();
int List_insert(List list, TYPE data, int position);
int List_append(List list, TYPE data);
int List_prepend(List list, TYPE data);
void List_print(List list);
void List_free(List list);
TYPE List_get(List list, int index);
void List_delete(List list, int index);
List List_reversCon(List list);
void List_printBack(List list);
void List_revers(List list);