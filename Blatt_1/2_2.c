#include <stdio.h>

int main(int argc, char const *argv[]){
    int number;
    puts("Bitte gib ein positive, ganze Zahl ein: ");
    int check = scanf(" %u", &number);
    if (check != 1 || number < 1) {
        puts("Fehlerhafte Eingabe!");
        return 1;
    }
    /*
    unsigned long long quad = 0;
    for(unsigned int i = 1; i <= number; i++){
        quad += i * i;
    }*/
    //großer Gauß
    unsigned long long quad = (number * (number + 1) * (number * 2 + 1)) / 6;
    printf("Die Summe der Quadrate von 1 bis %i ist %llu.\n", number, quad);
    return 0;
}