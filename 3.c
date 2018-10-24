#include <stdio.h>

int main(void)
{

    int n=0;
    int x=2;
    int erg=0;

    printf("Bitte geben Sie eine positive ganze Zahl ein...\nn=");
    scanf("%i", &n);
    printf("\n");

//soll nur positive Zahl einlesen...
    if (n<0)
    {
        printf("Fehler. n darf nicht negativ sein.\n");
        return 0;
    }
    printf("Ist %i eine Primzahl?\n", n);

    if(n==2||n==1)
    {
        printf("Ja\n");
        return 0;
    }

    for (int i=2; i<n; ++i)
    {
        if (n%i==0)
        {
            printf("Nein\n");
            return 0;
        }
    }    
    printf("Ja\n");

    return 0;
}
