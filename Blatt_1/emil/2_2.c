#include <stdio.h>

int main(int argc, char const *argv[]){
    int number;
    puts("Bitte gib ein positive, ganze Zahl ein: ");
    int check = scanf("%i", &number);
    //wenn die Eingabe das falsche Format hat oder die Eingabe negativ ist
    if (check != 1 || number < 1) {
        puts("Fehlerhafte Eingabe!");
        return 1;
    }
    //falls die Summe der ersten n Quadratzahlen gemeint war
    /*
    unsigned long long quad = 0;
    for(unsigned int i = 1; i <= number; i++){
        quad += i * i;
    }*/
    //großer Gauß
    //unsigned long long quad = (number * (number + 1) * (number * 2 + 1)) / 6;
    

    unsigned long long quad = 0;
    for(unsigned int i = 1; i * i <= number; i++){
        quad += i * i;
    }
    //%llu ist das Format für ein unsigned long long
    printf("Die Summe der Quadrate von 1 bis %i ist %llu.\n", number, quad);
    
    return 0;
}