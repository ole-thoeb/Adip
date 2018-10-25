#include <stdio.h>

int main(int argc, char const *argv[]){
	int number;
	puts("Bitte gib ein positive, ganze Zahl ein: ");
	int check = scanf("%i", &number);
	//wenn die Eingabe das falsche Format hat oder die Eingabe negativ ist
	if (check != 1 || number < 1){
		puts("Fehlerhafte Eingabe!");
		return 1;
	}
	/*
    unsigned long long sum = 0;
    for(unsigned int i = 1; i <= number; i++){
        sum += i;
    }*/
	//kleiner Gauß
	unsigned long long sum = (number * number + number) / 2;
    //%llu ist das Format für ein unsigned long long
	printf("Die Summe von 1 bis %i ist %llu.\n", number, sum);
	return 0;
}