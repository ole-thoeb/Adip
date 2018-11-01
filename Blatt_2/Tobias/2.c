#include <stdio.h>

long long fib_rec(long n);

long long fib_50();

long long fib_rec(long n)
{
    long long erg=0;
    long long f1=0;
    long long f2=0;
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

long long fib_50()
{
    long long erg=0;
    long long f1=0;
    long long f2=0;
    printf("Gerade Fibonacci-Zahlen: (Es entsteht ein Overflow!!!)\n");

    for (int i=0; i<150; i++)
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
           
            //if (erg<(f1+f2)) funktioniert nicht. die Rechenoperation geht natürlich auch nicht.
            if (erg<0)
            {
                printf("\nOverflow-Error\n\n");
                printf("%i\n", i);
                return 0;
            }
            
        }
        if (erg%2==0)
        {
            printf ("%lld ", erg);
        }
        f1=f2;
        f2=erg;
    }
    printf ("\n");
    return erg;
}

int main(void)
{
    long n=0;
    printf("n=");
    scanf("%ld", &n);
    printf("\n");
    if (n>=93)
    {
        printf("n ist zu groß. Es würde zu einem Overflow kommen.\n");
        return 0;
    }

    fib_50();


    printf("f(%ld)=%lld\n", n, fib_rec(n));

    return 0;
}
