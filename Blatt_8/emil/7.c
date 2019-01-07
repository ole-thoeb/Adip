/*
Definition: Die Kinder haben immer einen kleineren Schlüssel als das Elternteil.
*/

#include <stdio.h>
#include <stdlib.h>

struct MaxHeapImpl{
	int *el;
	int len;
	int mem;
};

typedef struct MaxHeapImpl *MaxHeap;

void Array_print(int *array, int size){
	for(size_t i = 0; i < size; i++){
		if (i != 0) {
			printf(", ");
		}
		printf("%i", array[i]);
	}
	putchar('\n');
}

int left(int i){
	return 2 * i + 1;
}

int right(int i){
	return 2 * i + 2;
}

void swap(MaxHeap heap, int pos1, int pos2){
	int temp = heap->el[pos1];
	heap->el[pos1] = heap->el[pos2];
	heap->el[pos2] = temp;
}

void MaxHeapify(MaxHeap heap, int pos){
	int max = pos;
	if (left(pos) < heap->len && heap->el[left(pos)] > heap->el[max]){
		max = left(pos);
	}
	if (right(pos) < heap->len && heap->el[right(pos)] > heap->el[max]){
		max = right(pos);
	}
	//Array_print(heap->el, heap->len);
	//printf("max %i, len %i\n", max, heap->len);
	if (max != pos) {
		swap(heap, pos, max);
		MaxHeapify(heap, max);
	}
}

void pushback(MaxHeap heap){
	if(heap->mem > heap->len){
		for(int i = heap->len - 1; i >= 0; i--){
			heap->el[i + 1] = heap->el[i];
		}
		return;
	}

	heap->mem++;
	int *temp = malloc(heap->mem * sizeof(int));
	
	for(size_t i = 0; i < heap->len; i++){
		temp[i + 1] = heap->el[i];
	}
	free(heap->el);
	heap->el = temp;
}

void InsertMax(MaxHeap heap, int value){
	pushback(heap);
	heap->el[0] = value;
	heap->len++;
	MaxHeapify(heap, 0);
}

void RemoveMax(MaxHeap heap){
	int lastIndex = heap->len - 1;
	swap(heap, 0, lastIndex);
	heap->len--;
	MaxHeapify(heap, 0);
}

int main(int argc, char const *argv[]){
	MaxHeap h = malloc(sizeof(struct MaxHeapImpl));
	h->el = malloc(sizeof(int));
	h->len = 0;
	h->mem = 1;

	InsertMax(h, 3);
	InsertMax(h, 1);
	InsertMax(h, 6);
	InsertMax(h, 4);
	InsertMax(h, 8);
	InsertMax(h, 7);

	Array_print(h->el, h->len);
	RemoveMax(h);
	RemoveMax(h);
	Array_print(h->el, h->len);
	return 0;
}
