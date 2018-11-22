#include<stdio.h>
#include<stdlib.h>
/*Anmerkungen zur letzten Aufgabe - Vor- und Nachteile der Implementierung:
Naheliegend: Verdopplung macht Sinn, wenn davon auszugehen ist, dass noch viele weitere Einträge folgen. Dann wird Arbeit minimiert (die Reallokation)
Minimale Vergrößerung spart generell Speicherplatz.
*/

typedef struct Dynarray{
	int *arr;
	int len;
	int max;
} Dynarray;

typedef struct Minarray{
	int *arr;
	int len;
	int max;
} Minarray;

void dyn_array_add(Dynarray *d, int input){
	if(d->len >= d->max){
		d->max *= 2;
		
		/* CodeEmil - realloc in neues Array, Übergabe des reallocs in d-arr
		int *newArg = realloc(d->arr, d->max*sizeof(int));
		
		if(newArg){
			d->arr = newArg;
		}else{
			puts("fehler");
		}*/
		
		//Code Johannes - realloc direkt in d->arr
		d->arr = realloc(d->arr, d->max*sizeof(int));
	}	
	
	d->arr[d->len] = input;
	d->len ++;
}

void min_array_add(Minarray *m, int input){
	if(m->len >= m->max){
		m->max++;
	}	
	
	/* CodeEmil - realloc in neues Array, Übergabe des reallocs in d-arr
	int *newArg = realloc(d->arr, d->max*sizeof(int));
	Code Emil: Übergabe des reallocs in d-arr
	int *newArg = realloc(m->arr, m->max*sizeof(int));
	if(newArg){
		m->arr = newArg;
	}else{
		puts("fehler");
	}*/
	
	//Code Johannes - realloc direkt in m->arr
	m->arr = realloc(m->arr, m->max*sizeof(int));
	
	m->arr[m->len] = input;
	m->len++;
}


int main(void){
	Dynarray dynarray;
	dynarray.len = 0;
	dynarray.max = 1;
	dynarray.arr = malloc(dynarray.max*sizeof(int));
	
	Minarray minarray;
	minarray.len = 0;
	minarray.max = 1;
	minarray.arr = malloc(minarray.max*sizeof(int));
	
	int end = 0;
	while(end == 0){
		printf("Bitte weiteren Int-Wert fuers Array eingeben (Nicht-Zahl oder '0', um zu beenden): ");
		int i = 0;
		scanf("%i", &i);
		dyn_array_add(&dynarray, i);
		min_array_add(&minarray, i);
		if(i == 0){end = 1;}
	}
	
	printf("\nMAXARRAY: LEN = %i, MAX = %i", dynarray.len, dynarray.max);
	printf("\nMINARRAY: LEN = %i, MAX = %i\n", minarray.len, minarray.max);
	for(int i = 0;i < dynarray.len; i++){
		printf("\nMAXArray[%i] = %i", i, dynarray.arr[i]);
	}
	printf("\n");
	for(int i = 0;i < minarray.len; i++){
		printf("\nMINArray[%i] = %i", i, minarray.arr[i]);
	}
	free(dynarray.arr);
	free(minarray.arr);
	return 0;
}
