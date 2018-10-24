#include <stdio.h>

int main(void)
{

    int n=0;
    int x=1;
    int erg=0;

    printf("n=");
    scanf("%i", &n);
    printf("\n");

    while (x<n)
    {
        erg=erg+x;
        x+=1;  
    }
    
    printf("Die Summe der ganzen Zahlen von 1 bis %i ist:\n%i\n", n, erg);


return 0;
}

