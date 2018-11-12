#include <stdio.h>

int main()
{
    //das geht
    int array[5]={0};

    //das geht
    int var=5;
    int array[var];
   
    //das geht NICHT
    int var=5;
    int array[var]={0};

    return 0;
}
