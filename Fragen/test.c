#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int arg[2][5]={{0, 1, 2, 3, 4}, {5, 6, 11, 8, 9}};
    printf("%i\n", *(arg[1] + 2));
}
