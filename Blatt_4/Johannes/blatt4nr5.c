//Münzen
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void initializegenerator() {
	srand(time(NULL));
}

int main() {
	initializegenerator();
	int start = rand(), input = 0;
	while(input < start){
		printf("Startbetrag = %i. Bitte hoeheren Betrag angeben: ", start);
		scanf("%i", &input);
	}
	input = input - start;
	printf("\nZu zerteilender Betrag: %i", input);
	int muenzen[6] = {1, 2, 5, 10, 20, 50};
	int output[6] = {0,0,0,0,0,0};
	//input ist der zu zerzeilende Betrag. Wird im weiteren zu 0 subtrahiert
	//output speichert die Anzahl benötigter Münzen
	for(int i=5; i>=0; i--){
		while (input>=muenzen[i]){
			input = input - muenzen[i];
			output[i] = output[i] + 1;
		}
	}
	for(int i=5; i>=0; i--){
		printf("\nAnzahl %i-Muenzen: %i", muenzen[i], output[i]);
	}
}