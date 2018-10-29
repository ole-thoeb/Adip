#include <stdio.h>

long fib_rec(long n);

long fib_50();

long fib_rec(long n)
{
    long erg=0;
    long f1=0;
    long f2=0;
    for (long i=0; i<=n; i++)
    {
        if (i==0)
        {
            erg=0;
        }
        else if (i==1)
        {
            erg=1;
        }
        else if (i>=2)
        {
           erg=f1+f2;
        }
    f1=f2;
    f2=erg;

 //
    }
    return erg;
}

long fib_50()
{
    long erg=0;
    long f1=0;
    long f2=0;
    for (int i=0; i<=50; i++)
    {
        //
        if (i==0)
        {
            erg=0;
        }
        else if (i==1)
        {
            erg=1;
        }
        else if (i>=2)
        {
           erg=f1+f2;
        }
        printf ("%ld ", erg);
        f1=f2;
        f2=erg;
    }
    printf ("\n");
    return erg;
}

int main(void)
{
    long n= 0;
    printf("n=");
    scanf("%ld", &n);
    printf("\n");

    fib_50();


    printf("%ld\n", fib_rec(n));

    return 0;
}
