#include <stdio.h>

int main()
{
    int n=1;
    int teiler[100]={0};
    int nummer=0;
    int erg=0;
    printf("Eine natürliche Zahl heißt,\n• vollkommen (auch perfekt), wenn sie gleich der Summe aller ihrer (positiven) echten Teiler ist (die Summe aller Teiler ohne die Zahl selbst).\n• defizient, wenn ihre echte Teilersumme kleiner ist als die Zahl selbst.\n\n");
    printf("n=");
    scanf("%i",&n);
    printf("\n");
    

    for (int i=1; i<=(n/2);i++)
    {
        if (n%i==0)
        {
            teiler[nummer]=i;
            nummer+=1;
        }
   
    }

    for (int i=0; i<=nummer-1; i++)
    {
        printf("%i ", teiler[i]);
    }
        printf("\n");

    for (int i=0; i<=nummer-1; i++)
    {
        printf("+ %i ", teiler[i]);
        erg=erg+teiler[i];
    }
        printf("= %i\n", erg);

    if (erg==n)
    {
        printf("%i ist keine defizitäre Zahl\n", n);
    }
    else if (erg<n)
    {
        printf("%i ist eine defizitäre Zahl\n", n);
    }
    return 0;
}
