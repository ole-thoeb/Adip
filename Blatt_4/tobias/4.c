#include <stdio.h>
#include <math.h>

unsigned long long pythTrip()
{

    for (unsigned long long c=2; c<=500; c++)
    {
        for (unsigned long long b=1; b<c; b++)
        {
            for (unsigned long long a=0; a<b;a++)
            {
                if (pow(a,2)+pow(b,2)==pow(c,2))
                {
                    printf("%llu²+%llu²=%llu²\n", a, b, c);
                }
            }
        }
    }    
    return 0;
}

int main()
{
    pythTrip();

    return 0;
}
