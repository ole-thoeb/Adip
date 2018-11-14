#include <stdio.h>
#include <stdlib.h>


unsigned long long aFakult(unsigned long long n)
{
    unsigned long long erg=1;
    //unsigned long long nAlt=1;
    for(int i= 1; i<=n; i++)
    {
        erg=erg*i;  
        if (erg<0)
        {
            puts("overflow error");
            exit(1);
        }
    }
    return erg;
}

unsigned long long bBinko(unsigned long long n, unsigned long long k)
{
    unsigned long long erg=1;

   // while(k!=0)
   // {
        if (0<=k && k<=n)
        {
            erg=aFakult(n)/(aFakult(k)*(aFakult(n-k)));
        }
        else if (0<=n && n<k)
        {
            erg=0;
        }
  /*      else
        {
            break;
        }
 }  */ 

    return erg;
}

unsigned long long cLotto(unsigned long long n, unsigned long long k)
{
    unsigned long long erg=1;
    
    erg=(bBinko(n,k)*aFakult(k));
    return erg;
}

int main()
{
    unsigned long long n=0;
    printf("Bitte geben Sie eine natürliche Zahl ein\nn=");
    int check=scanf("%llu", &n);
    printf("\n");
    if (check != 1 || n<0)
    {
        puts("Nicht akzeptierte Eingabe");
        return 0;
    }
    check=1;
    unsigned long long k=0;
    printf ("Bitte geben Sie eine natürliche Zahl ein\nk=");
    check=scanf("%llu", &k);
    printf("\n");
    if (check !=1 || k <0)
    {
        puts("Nicht akzeptierte Eingabe");
        return 0;
    }


    printf("a)\t(%llu)!=%llu\n", n, aFakult(n));


    printf("b)\t(%llu über %llu)=%llu\n", n, k, bBinko(n, k));

// Achtung! Vielleicht brauche ich doubles. bei dem Bruch müsste es doch Nachkommastellen geben. Auf der anderen Seite funktioniert doch nicht das Konzept des Binomialkoeffizienten mit Kommazahlen.


    printf("c)\t(%llu über %llu)(%llu)!=%llu", n, k, k, cLotto(n, k));
    printf("\n");
    return 0;
}
