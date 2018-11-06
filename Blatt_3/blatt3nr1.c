//Blackjack
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void initializegenerator() {
srand(time(NULL));
}
int karteziehen() {
// Sie koennen Zufallszahlen generieren, indem Sie die Funktion rand() aufrufen
// z.B. int zufall = rand();
// [rand() mod 9 liegt zwischen 0 und 9]
	return rand()%9 + 2;
}
int main() {
initializegenerator();
int end = 1, sum = 0;
// Code fuer den Spielablauf
	//für Spieler
	while(end == 1){
		printf("\nAktueller Stand: %i. '1' fuer weitere Karte, '0' fuer Spielende: ", sum);
		scanf("%i", &end);
		if (end == 1){
			sum += karteziehen();
			if (sum > 21){
				end = 0;
				printf("\nSumme > 21. Spiel verloren.");
				goto Ende;
			}			
		} else if (end > 1){
			printf("\nUngueltige Eingabe. Abbruch");
			goto Ende;
		} else {
			end = 0;
		}
	}
	//für Gegner
	int ki_sum = 0;
	while(ki_sum < 16){
		ki_sum += karteziehen();
	}
	printf("\nErgebnis der Bank: %i", ki_sum);
	if(sum > ki_sum || ki_sum > 21){
		printf("\nSie haben gewonnen.");
	}else{
		printf("\nSie haben verloren.");
	}	
		Ende:
return 0;
}