#include <stdio.h>

int main ()
{
    long a=0;
    int n=0;
    long erg=1;
    int schritt=0;

    printf("a^n\na=");
    scanf("%ld", &a);
    printf("\n");
    printf("%ld^n\nn=", a);
    scanf("%i", &n);
    printf("\n");


    if (n==0)
    {
        erg=1;
        schritt+=1;
    }
    else if (n%2==0)
    {
        for (int i=1; i<=(n/2); i++)
        {
        erg=a*erg;
        schritt+=1;  
        }
        erg=erg*erg;
        schritt+=1; 
    }
    else if (n%2!=0)
    {
        for (int i=1; i<=((n-1)/2); i++)
        {
        erg=a*erg;
        schritt+=1;  
        }
        erg=a*erg*erg;
        schritt+=1; 
    }

    printf ("%ld^%i=%ld\n%i Schritte\n", a, n, erg, schritt);

//2^17 brauchte beim Test 9 Schritte


    return 0;
}
