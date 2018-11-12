#include <stdio.h>

int main()
{
    //das geht
    int array[5]={0};

    //das geht
    int var=5;
    int arrayb[var];
   
    //das geht NICHT
    int var2=5;
    int arrayc[var2]={0};

    //warum geht das nicht und wie kann man dann mit 0en initialisieren?
    
    return 0;
}
