#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]){
    int number;
    puts("Bitte gib ein positive, ganze Zahl ein: ");
    int check = scanf(" %u", &number);
    if (check != 1 || number < 1) {
        puts("Fehlerhafte Eingabe!");
        return 1;
    }
    
    for(unsigned int i = 2; i <= sqrt(number); i++){
        if (number % i == 0) {
            puts("Nein");
            //printf("%i ist keine Primzahl", number);
            return 0;
        }
    }
    puts("Ja");
    return 0;
}