#include <stdio.h>

int main(void)
{
    int n=0;
    int erg=1;
    int primfaktoren[100]={0};
    int faktornummer=0;
    int prim=0;

    printf("Bitte geben Sie eine positive ganze Zahl ein...\nn=");
    scanf("%i", &n);
    printf("\n");


    if (n<0)
    {
        printf("Fehler. n darf nicht negativ sein.\n");
        return 0;
    }
    else if(n==1)
    {
        printf("0! = 1\n");
        return 0;
    }

    erg=n;
    while(erg>1)
    {

        prim=0;
        int i=2;

        while (i<erg&&prim==0||prim==0)
        {
            if(erg%i==0)
            {

                if (i==2)
                {
                    prim=1;
                }  
                else
                {
                    for (int j=1; j<i; ++j)
                    {   
    
                        if(i%j!=0)
                        {
                            prim=1;
                        }
                    }
                }
                if (prim==1)
                {
                    erg=erg/i;
                    primfaktoren[faktornummer]=i;
                    faktornummer+=1;
                }
            }
         i++;       
        }
        if (erg==1)
        {
            break;
        }
        
        
    }


    if (primfaktoren[0]==0||primfaktoren[0]==n)
    {
        printf("%i ist prim\n", n);
        return 0;
    }


    for (int i=0; i<faktornummer; ++i)
    {
        printf("%i", primfaktoren[i]);
        if (i<faktornummer-1)
        {
            printf("·");
        }
    }
    printf("\n");

    return 0;
}
