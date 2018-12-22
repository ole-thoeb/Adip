#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Array_print(int *array, int size){
	for(size_t i = 0; i < size; i++){
		if (i != 0) {
			printf(", ");
		}
		printf("%i", array[i]);
	}
	putchar('\n');
}

void swap(int *arg, int pos1, int pos2){
	int temp = arg[pos1];
	arg[pos1] = arg[pos2];
	arg[pos2] = temp;
}

int minPos(int *arg, int from, int to){
	int minP = from;
	int minV = arg[from];
	for(size_t j = from + 1; j < to; j++){
		if (minV > arg[j]) {
			minV = arg[j];
			minP = j;
		}
	}
	return minP;
}

void selectionSort(int *arg, int size){
	for(size_t i = 0; i < size; i++){
		swap(arg, i, minPos(arg, i, size));
	}
}

void insertionSort(int *arg, int size){
	for(size_t i = 1; i < size; i++){
		for(int j = i; arg[j - 1] > arg[j] && j > 0; j--){
			swap(arg, j - 1, j);
		}
	}
}

void bubbleSort(int *arg, int size){
	for(int i = size - 1; i > 0; i--){
		int swapped = 0;
		for(size_t j = 0; j < i; j++){
			if(arg[j] > arg[j + 1]){
				swapped = 1;
				swap(arg, j, j + 1);
			}
		}
		if(!swapped) break;
	}
}

void _quickSort(int *arg, int from, int to){
	if(from == to) return;
	//int pivot = arg[to];
	int pIndex = to;
	int direction = 1;

	for(size_t i = from; i != pIndex; i += direction){
		if(direction == 1){
			if(arg[i] > arg[pIndex]){
				swap(arg, i, pIndex);
				int temp = i;
				i = pIndex;
				pIndex = temp;
				direction = -1;
			}
		}else{
			if(arg[i] < arg[pIndex]){
				swap(arg, i, pIndex);
				int temp = i;
				i = pIndex;
				pIndex = temp;
				direction = 1;
			}
		}
		//printf("d %i, i %i, p %i\n", direction, i, pIndex);
	}
	if(pIndex > from) _quickSort(arg, from, pIndex -1);
	if(pIndex < to) _quickSort(arg, pIndex + 1, to);
}

void quickSort(int *arg, int size){
	_quickSort(arg, 0, size - 1);
}

void merge(int* data, int start, int haelfte, int ende) {
	int pos1 = start; //laufvariable für vorderes array
	int pos2 = haelfte + 1; //laufvariable für hinteres array
	int i = 0; //laufvariable für neues array (temp)
	int temp[ende - start + 1];
	while(pos1 <= haelfte || pos2 <= ende) {
		//fälle wenn eine Liste schon leer ist
		if(pos2 > ende) {
			temp[i++] = data[pos1++];
		} else if (pos1 > haelfte) {
			temp[i++] = data[pos2++];
		//normale Fälle: kleineres Element wird zuerst eingefügt (Teillisten sind schon sortiert)
		} else if (data[pos1] < data[pos2]) {
			temp[i++] = data[pos1++];
		} else {
			temp[i++] = data[pos2++];
		}
	}
	//temp rüber in data copieren
	for(i=0; i< ende - start + 1; i++) {
		data[start + i] = temp[i];
	}
}

void _mergeSort(int* data, int start, int ende) {
	if (start == ende) return;

	int haelfte = (start + ende) / 2;
	_mergeSort(data, start, haelfte);
	_mergeSort(data, haelfte + 1, ende);
	merge(data, start, haelfte, ende);
}

void mergeSort(int *arg, int size){
	_mergeSort(arg, 0, size - 1);
}

int* randomArray(int size){
	int *arg = malloc(sizeof(int) * size);
	for(size_t i = 0; i < size; i++){
		arg[i] = rand();
	}
	return arg;
}

int* copyArg(int *arg, int size){
	int *newArg = malloc(sizeof(int) * size);
	for(size_t i = 0; i < size; i++){
		newArg[i] = arg[i];
	}
	return newArg;
}

int main(int argc, char const *argv[]){
	srand(time(NULL));
	int size = 100000;
	int *arg0 = randomArray(size);
	int *arg1 = copyArg(arg0, size);
	int *arg2 = copyArg(arg0, size);
	int *arg3 = copyArg(arg0, size);
	int *arg4 = copyArg(arg0, size);

	clock_t t1, t2;
	float diff;

	t1 = clock();
	selectionSort(arg0, size);
	t2 = clock();
	diff = ((float)(t2 - t1) / CLOCKS_PER_SEC) * 1000;
	printf("selection %f\n",diff);

	t1 = clock();
	insertionSort(arg1, size);
	t2 = clock();
	diff = ((float)(t2 - t1) / CLOCKS_PER_SEC) * 1000;
	printf("insert %f\n",diff);

	t1 = clock();
	bubbleSort(arg2, size);
	t2 = clock();
	diff = ((float)(t2 - t1) / CLOCKS_PER_SEC) * 1000;
	printf("bubble %f\n",diff);

	t1 = clock();
	quickSort(arg3, size);
	t2 = clock();
	diff = ((float)(t2 - t1) / CLOCKS_PER_SEC) * 1000;
	printf("quick %f\n",diff);

	t1 = clock();
	mergeSort(arg4, size);
	t2 = clock();
	diff = ((float)(t2 - t1) / CLOCKS_PER_SEC) * 1000;
	printf("merge %f\n",diff);
	return 0;
}
