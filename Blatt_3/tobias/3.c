#include <stdio.h>

int main()
{
    int zahl=0;
    int dez=0;
    /*char zahlwort[20]="test1";
    char dezwort[20]="test2";*/
    char zahlen[10][12]={{"null"}, {"ein"}, {"zwei"}, {"drei"}, {"vier"}, {"fünf"}, {"sechs"}, {"sieben"}, {"acht"}, {"neun"}};

    printf("geben Sie eine Zahl zwischen 20 und 69 ein…\nzahl=");
    int check=scanf("%i", &zahl);
    printf("\n");

    if (check != 1 || zahl <20 || zahl > 69)
    {
        printf("unzulässige Eingabe\n");
        return 0;
    }

    dez=zahl/10;
    zahl=zahl-(dez*10);
    
    
    printf("%i%i\n", dez, zahl);
    

    if(zahl>0)
    {
        printf("%s", zahlen[zahl]);
    }

    if (dez>0)
    {
            if (zahl>0)
            {
                printf("-und-");
            }
            if (dez==2)
            {
                printf("zwanzig");
            }
            else if (dez==6)
            {
                printf("%s\bzig", zahlen[dez]);
            }
            else if (dez==3)
            {
                printf("%sßig",zahlen[dez]);
            }
            else
            {
                printf("%szig", zahlen[dez]);
            }
    }
    printf("\n");
    
    
    return 0;
}
