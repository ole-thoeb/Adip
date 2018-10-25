#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]){
    int number;
    puts("Bitte gib ein positive, ganze Zahl ein: ");
    int check = scanf("%i", &number);
    //wenn die Eingabe das falsche Format hat oder die Eingabe negativ ist
    if (check != 1 || number < 1) {
        puts("Fehlerhafte Eingabe!");
        return 1;
    }
    //reicht bis Wurzel n zu laufen, da danach die Faktoren nur danach andersherum währen
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