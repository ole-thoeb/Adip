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



    for(int i=0; i<=n; i++)
    {
        if (i>0)
        {
            erg=a*erg;
            schritt+=1;

        }
        //oder hier?     schritt+=1;

    
    }
    printf ("%ld^%i=%ld\n%i Schritte\n", a, n, erg, schritt);

//2^17 brauchte beim Test 17 Schritte

    return 0;
}
