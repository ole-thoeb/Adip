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


void print_arg(int *d, int len){
	printf("arg");
	for(int i = 0; i < len; i++){
		printf("%i, ", d[i]);
	}
	putchar('\n');
}

void print_dy(Dynarray *d){
	printf("Leange %i \n", d->len);
	for(int i = 0; i < d->len; i++){
		printf("%i, ", d->arr[i]);
	}
	putchar('\n');
}

void print_min(Minarray d){
	for(int i = 0; i < d.len; i++){
		printf("%i, ", d.arr[i]);
	}
	putchar('\n');
}

//Anmerkung: Neues Array wird erstellt und alles rüberkopiert (wie auf Blatt) - Versuch über realloc produziert seltsame Fehler
void dyn_array_add(Dynarray *d, int input){
	if(d->len >= d->max){
		d->max *= 2;
		printf("before ");
		print_arg(d->arr, d->len);
		int *newArg = realloc(d->arr, d->max*sizeof(int));
		printf("after ");
		print_arg(newArg, d->len);

		if(newArg){
			d->arr = newArg;
			printf("after allocation ");
			print_arg(d->arr, d->len);
		}else{
			puts("fehler");
		}
	}	
	
	d->arr[d->len] = input;
	d->len ++;

	print_dy(d);
}

Minarray min_array_add(Minarray m, int input){
	int i = m.len;
	if(m.len >= m.max){
		m.max++;
	}	
	
	Minarray minarray;
	minarray.len = m.len + 1;
	minarray.max = m.max;
	minarray.arr = realloc(m.arr, minarray.max*sizeof(int));
	minarray.arr[i] = input;

	print_min(m);
	free(m.arr);
return minarray;
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
		//minarray = min_array_add(minarray, i);
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