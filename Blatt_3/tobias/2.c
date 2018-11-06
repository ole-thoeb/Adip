#include <stdio.h>

double mittel(int var, double array[])
{
    double xmit=0;

    for (int i=1; i<=var; i++)
    {
        xmit=xmit+array[(i-1)];
    }
    xmit=xmit/var;
    
    return xmit;
}

double varianz(int var, double xmit, double array[])
{
    double s2=0;
    for (int i=1; i<=var; i++)
    {
        s2=s2+((array[(i-1)]-xmit)*(array[(i-1)]-xmit));
    }
    s2=s2/(var-1);
    printf("%lf", s2);
    return s2;
}

int main()
{
    int n=0;
    double wert=0;
    double wertarray[100]={0};
    printf ("Geben Sie bitte die Größe der Stichprobe an…\nn=");
    int check = scanf ("%i", &n);
    printf ("\n");
    if (check != 1 || n <=1)
    {
        printf("unzulässige Eingabe\n");
        return 0;
    }

    for (int i=0; i<=(n-1); i++)
    {
            printf ("Geben Sie bitte Wert %i ein\nWert%i=", (i+1), (i+1));
            check=scanf ("%lf", &wert);                
                if (check != 1)
                {
                    printf("unzulässige Eingabe\n");
                    //i-=1; continue;
                    return 0;
                }
            wertarray[i]=wert;
            printf ("\n");
    }

    for (int i=0; i<=(n-1);i++)
    {
        printf("%lf ", wertarray[i]);
    }
        printf("\n");


    double xmit=mittel(n, wertarray);
    printf("Das Arithmetische Mittel ist\n x̄ = %lf\n", xmit);


    printf("Die korrigierte Stichprobenvarianz ist\n s² = %lf\n", varianz(n, xmit, wertarray));

    
    return 0;
}
