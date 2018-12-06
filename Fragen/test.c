#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("%i\n", 10%11);
    printf("%i\n", -1%26);
    printf("%li\n", malloc(0));
    return 0;
}
