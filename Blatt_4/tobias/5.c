#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void initializegenerator() {
srand(time(NULL));
}





int main()
{

    initializegenerator();

    int muenzwerte[6]= {50, 20, 10, 5, 2, 1};
    int betrag=rand()%10000;
    int n=0;
    int differ=0;

    printf("Bitte geben Sie eine Ganze Zahl > %i ein\nn=", betrag);
    int check=scanf("%i", &n);
    printf("\n");

    if (check !=1||n<betrag)
    {
        puts("Eingabe nicht akzeptiert");
    }

    differ=n-betrag;
    printf("Rückgeld: €%i\n", differ);
    int i=0;
    while(differ>0)
    {

        if (differ-muenzwerte[i]>0||differ-muenzwerte[i]==0)
        {
            printf("€%i\n", muenzwerte[i]);
            differ=differ-muenzwerte[i];
        }
        else
        {
            ++i;
        }
        
    }

    return 0;
}
