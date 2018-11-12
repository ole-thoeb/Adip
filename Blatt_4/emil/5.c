#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initializegenerator() {
    srand(time(NULL));
}

int getRand() {
    return (rand() % 100) + 1;
}

int main(int argc, char const *argv[]){
	initializegenerator();

	int randInt = getRand();

	int number;
    printf("Bitte gib ein Zahl ein, welche groesser als %d ist: ", randInt);
    int check = scanf("%d", &number);
    //wenn die Eingabe das falsche Format hat oder die Eingabe zu klein ist
    if (check != 1 || number < randInt) {
        puts("Fehlerhafte Eingabe!");
        return 1;
    }

	int dif = number - randInt;

	printf("Die Differenz ist %i\n", dif);

	int muenzen[6] = {50, 20, 10, 5, 2, 1};

	while(dif > 0){
		for(int i = 0; i < 6; i++){
			if(dif >= muenzen[i]){
				printf("%d,", muenzen[i]);
				dif -= muenzen[i];
				break;
			}
		}
	}
	
	return 0;
}
