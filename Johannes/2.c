#include<stdio.h>
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

//Anmerkung: Neues Array wird erstellt und alles rüberkopiert (wie auf Blatt) - Versuch über realloc produziert seltsame Fehler
Dynarray dyn_array_add(Dynarray d, int input){
	int i = d.len;
	if(d.len >= d.max){
		d.max = 2*d.len;
	}	
	
	Dynarray dynarray;
	dynarray.len = d.len + 1;
	dynarray.max = d.max;
	dynarray.arr = malloc(dynarray.max*sizeof(int));
	for(int k = 0; k < i; k++){
		dynarray.arr[k] = d.arr[k];
	}
	dynarray.arr[i] = input;

	free(d.arr);
return dynarray;
}

Minarray min_array_add(Minarray m, int input){
	int i = m.len;
	if(m.len >= m.max){
		m.max++;
	}	
	
	Minarray minarray;
	minarray.len = m.len + 1;
	minarray.max = m.max;
	minarray.arr = malloc(minarray.max*sizeof(int));
	for(int k = 0; k < i; k++){
		minarray.arr[k] = m.arr[k];
	}
	minarray.arr[i] = input;

	free(m.arr);
return minarray;
}

main(void){
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
		dynarray = dyn_array_add(dynarray, i);
		minarray = min_array_add(minarray, i);
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