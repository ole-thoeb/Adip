#include <stdio.h>

int isVollkommen(unsigned int n){
	unsigned long sumOfTeiler = 0;
	for(int i = 1; i < n; i++){
		if(n % i == 0){
			sumOfTeiler += i;
		}
	}

	return sumOfTeiler == n;
}

int main(int argc, char const *argv[]){
	int number;
	puts("Bitte gib eine positive, ganze Zahl ein: ");
	int check = scanf("%i", &number);
	//wenn die Eingabe das falsche Format hat oder die Eingabe nicht positiv ist
	if (check != 1 || number < 1){
		puts("Fehlerhafte Eingabe!");
		return 1;
	}
	
	printf("Diese Zahlen sind kleiner als %i und vollkommen:");
	for(int i = 1; i < number; i++){
		if (isVollkommen(i)) {
			printf("%i\n", i);
		}
	}
	
	return 0;
}