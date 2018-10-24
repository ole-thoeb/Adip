#include <stdio.h>

int main(void)
{

    int n=0;
    int x=2;
    int erg=0;


    printf("n=");
    scanf("%i", &n);
    printf("\n");

    while (x<n)
    {
        for(int i=1; i<x; ++i)
        {
            if (i*i==x)
            {
                erg=erg+x;
            }  
        }  
        x+=1;  
    }
    
    printf("Die Summe der Quadratzahlen von 1 bis %i ist:\n%i\n", n, erg);


return 0;
}

