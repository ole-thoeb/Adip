#include <stdio.h>

int main() 
{
    for (int i=1; i<=9; i++)
    {
        for (int j=1; j<=9; j++)
        {
            printf("%i·%i=%i\n", j, i, (i*j));
// Exitkey für TAB
        }
        printf("\n");
    }

    return 0;
}
