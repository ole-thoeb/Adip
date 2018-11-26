#include <stdio.h>
#include <stdlib.h>
#include "List.h"

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

void List_delete(List list){
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
		printf("%i -> ", currentNode->value);
		currentNode = currentNode->next;
	}
	printf("NULL\n");
}