#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initializegenerator() {
    srand(time(NULL));
}

int getKarte() {
    // Sie koennen Zufallszahlen generieren, indem Sie die Funktion rand() aufrufen
    // z.B. int zufall = rand();
    return (rand() % 9) + 2;
}

void printCards(int cards[], int size){
    for ( int i = 0; i < size; i++){
        printf("%d, ", cards[i]);
    }
    printf("\n");
}

int sum(int arg[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arg[i];
    }
    return sum;
}

void displayWinner(int playerWon){
    if(playerWon){
        printf("Spieler hat gewonnen");
    }else{
        printf("Dealer hat gewonnen");
    }
}
int main() {
    initializegenerator();
    // Code fuer den Spielablauf

    int dealerCards[12];
    int dealerIndex = 1;
    dealerCards[0] = getKarte();

    int playerCards[12];
    int playerIndex = 0;
    printf("Karte vom Dealer: %i\n", dealerCards[0]);
    char input;
    while(1){
        printf("Willst du eine Karte ziehen? (y/n)\n");
        int check = scanf("%c", &input);
        if(check != 1 || (input != 'y' && input != 'n')){
            printf("falscher Input.");
        }else{
            if(input == 'y'){
                int newKart = getKarte();
                playerCards[playerIndex] = newKart;
                playerIndex++;
                printf("Deine Karten: ");
                printCards(playerCards, playerIndex);
                if(sum(playerCards, playerIndex) > 21){
                    printf("Ueber 21\n");
                    displayWinner(0);
                    return 0;
                }
            }else{
                break;
            }
        }
    }
    while(sum(dealerCards, dealerIndex) <= 16){
        dealerCards[dealerIndex] = getKarte();
        dealerIndex++;
        printf("Dealer Karten: ");
        printCards(dealerCards, dealerIndex);
        if(sum(dealerCards, dealerIndex) > 21){
            displayWinner(1);
            return 0;
        }
    }

    if(sum(dealerCards, dealerIndex) > sum(playerCards, playerIndex)){
        displayWinner(0);
    }else if(sum(dealerCards, dealerIndex) < sum(playerCards, playerIndex)){
        displayWinner(1);
    }else{
        printf("Unentschieden");
    }

    return 0; 
}