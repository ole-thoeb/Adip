#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include <assert.h>

typedef struct NodeImp Node;

struct NodeImp{
	Node *next;
	Node *prev;
	TYPE value;
}NodeImp;

struct ListImpl{
	Node *head;
	Node *tail;
	int size;
}ListImpl;

List List_new(){
	List list = malloc(sizeof(struct ListImpl));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

int List_insert(List list, TYPE data, int position){
	if(position > list->size) return 0;
	if(position == 0) return List_prepend(list, data);
	if(position == list->size) return List_append(list, data);

	Node *temp = malloc(sizeof(Node));
	if(!temp) return 0;

	Node *currentNode = list->head;
	for(size_t i = 0; i < position -1; i++){
		currentNode = currentNode->next;
	}
	Node *nextNode = currentNode->next;

	temp->value = data;
	temp->next = nextNode;
	temp->prev = currentNode;
	currentNode->next = temp;
	nextNode->prev = temp;
	list->size++;
	return 0;
}

int List_append(List list, TYPE data){
	Node *temp = malloc(sizeof(Node));
	if(!temp) return 0;

	if(list->size == 0){
		list->head = temp;
		list->tail = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}else{
		temp->next = NULL;
		temp->prev = list->tail;
		list->tail->next = temp;
		list->tail = temp;
	}
	temp->value = data;
	list->size++;
	return 1;
}

int List_prepend(List list, TYPE data){
	Node *temp = malloc(sizeof(Node));
	if(!temp) return 0;

	if(list->size == 0){
		list->head = temp;
		list->tail = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}else{
		temp->next = list->head;
		temp->prev = NULL;
		list->head->prev = temp;
		list->head = temp;
	}
	temp->value = data;
	list->size++;
	return 1;
}

void List_free(List list){
	Node *currentNode = list->head;
	Node *nextNode;
	while(currentNode != NULL){
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}
	free(list);
}

void List_print(List list){
	Node *currentNode = list->head;
	printf("HEAD -> ");
	while(currentNode != NULL){
		printf("%lf -> ", currentNode->value);
		currentNode = currentNode->next;
	}
	printf("NULL\n");
}

void List_printBack(List list){
	Node *currentNode = list->tail;
	printf("TAIL -> ");
	while(currentNode != NULL){
		printf("%lf -> ", currentNode->value);
		currentNode = currentNode->prev;
	}
	printf("NULL\n");
}

TYPE List_get(List list, int index){
	assert(list->size > index);
	if(index < list->size / 2){
		Node *cur = list->head;
		for(size_t i = 0; i < index; i++){
			cur = cur->next;
		}
		return cur->value;
	}else{
		Node *cur = list->tail;
		for(size_t i = 0; i < list->size - index - 1; i++){
			cur = cur->prev;
		}
		return cur->value;
	}
}

void List_deleteFirst(List list){
	if(list->size == 1){
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}else{
		Node *next = list->head->next;
		free(list->head);
		next->prev = NULL;
		list->head = next;
	}
	list->size--;
}

void List_deleteLast(List list){
	if(list->size == 1){
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}else{
		Node *pref = list->tail->prev;
		free(list->tail);
		pref->next = NULL;
		list->tail = pref;
	}
	list->size--;
}

void List_delete(List list, int index){
	assert(list->size > index);

	if(index == list->size-1) return List_deleteLast(list);
	if(index == 0) return List_deleteFirst(list);
	
	Node *cur = (index < list->size / 2) ? list->head : list->tail;
	if(index < list->size / 2){
		for(size_t i = 0; i < index; i++){
			cur = cur->next;
		}
	}else{
		for(size_t i = 0; i < list->size - index - 1; i++){
			cur = cur->prev;
		}
	}
	Node *prev = cur->prev;
	Node *next = cur->next;
	free(cur);
	prev->next = next;
	next->prev = prev;
	list->size--;
}

List List_reversCon(List list){
	List rev = List_new();
	Node *cur = list->head;
	for(size_t i = 0; i < list->size; i++){
		List_prepend(rev, cur->value);
		cur = cur->next;
		//printf("i %i, v %lf\n", i, cur->value);
	}
	return rev;
}

void List_revers(List list){
	Node *cur = list->head;
	for(size_t i = 0; i < list->size; i++){
		Node *n = cur->next;
		cur->next = cur->prev;
		cur->prev = n;
		cur = cur->prev;
	}
	Node *h = list->head;
	list->head = list->tail;
	list->tail = h;
}