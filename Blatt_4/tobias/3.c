#include <stdio.h>
#include <math.h>
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


double sin(double x)
{
    double erg=0;
    for (int n=0; n<=5;n++)
    {
        erg=erg+( pow(-1, n)*( pow(x, (2*n+1))/aFakult(2*n+1) ) );
    }
    return erg;
}

double cos(double x)
{
    double erg=0;
    for (int n=0; n<=5; n++)
    {
        erg=erg+(pow(-1,n)*(pow(x, 2*n)/aFakult(2*n)));
    }
    return erg;

}

double exp(double x)
{
    double erg=0;
    for (int n=0; n<=10;n++)
    {
        erg=erg+(pow(x, n)/aFakult(n));
    }
    return erg;
}

int main()
{
    double x=0.0;
    printf("Geben Sie eine Reelle Zahl ein\nx=");
    int check=scanf("%lf", &x);
    if (check!=1)
    {
        puts("Error. Keine akzeptierte Eingabe");
        return 0;
    }
    printf("sin(%lf)=%lf\n", x, sin(x));
    
    printf("cos(%lf)=%lf\n", x, cos(x));

    printf("exp(%lf)=%lf\n", x, exp(x));
    return 0;
}
