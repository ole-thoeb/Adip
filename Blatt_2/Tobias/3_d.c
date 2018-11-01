#include <stdio.h>


int main()
{

    unsigned long long r=1;
    int anzahl=0;


    printf("geben Sie eine natürliche Zahl ein\nr=");
    scanf("%llu",&r);
    printf("\n");
    

   for (unsigned long long j=1; j< r; j++)
    {
            //printf("\tj=%llu", j);
    unsigned long long erg=0;
    int nummer=0;
    unsigned long long teiler[100]={0};
      for (unsigned long long i=1; i<j; i++)
        {
        
            //printf("\ti=%llu", i);

            if (j%i==0)
            {
                teiler[nummer]=i;
                nummer+=1;
            }
        }
        /*
        //zum Testen
        if (nummer>0)
        {
        printf("Teiler von %llu:\n", j);
        for (unsigned long long i=0; i<=nummer-1; i++)
        {
            printf("%llu ", teiler[i]);
        }
            printf("\n");
        }
        */
        if (nummer>0)
        { 
            for (unsigned long long i=0; i<=nummer-1; i++)
            {
            //    printf("+ %llu ", teiler[i]);
                erg=erg+teiler[i];
            }
            //    printf("= %llu\n", erg);
        }
        
        /*
        if (erg==j)
        {
            printf("%llu ist eine vollkommene Zahl\n", j);
        }
        */
        if (erg<j)
        {
            ++anzahl;
        }

        //printf("Iterationsende\n\n");
    }

    //printf("Es gibt %i vollkommene Zahlen < als die natürliche Zahl %llu\n", anzahl, r);

    printf("Es gibt %i defiziente Zahlen < als die natürliche Zahl %llu\n", anzahl, r);

    return 0;
}
