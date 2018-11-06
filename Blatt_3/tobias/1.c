#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initializegenerator();

int getkarte();

void printintarray(int array[], size_t size);

int summen(int array[], size_t size);

int dealer(int * p);


void initializegenerator() {
    srand(time(NULL));
}

int getkarte() 
{
    int zufall = rand()%9+2;
    return zufall;
}

void printintarray(int array[], size_t size)
{
    for(size_t i=0; i< size; i++)
    {
        printf("%i",array[i]);
        if (i< size -1)
        {
            printf(", ");        
        }
    }
    printf("\n");
}

int summen(int array[], size_t size)
{
    int summe=0;
    for (size_t i=0; i<size; i++)
    {
        summe+=array[i];
    }
    //printf("Summe %i\n", summe);
    return summe;
}

int dealer(int * p)
{
    int kartennr=0;
    int handkartendealer[21]={0};
    while (*p<=16)
    {
         
            int karte=getkarte();
            handkartendealer[kartennr] = karte;
            printf("[♢%i\n| ♢ |\n[  ♢]\n\n",handkartendealer[kartennr]);            
           
            *p=summen(handkartendealer, kartennr+1);
            ++kartennr;
    }
            printf("\n");
            printintarray(handkartendealer, kartennr+1);    

            printf("%i\n", *p);       
        if (*p>21)
        {
            puts("Der Spieler gewinnt");
            return 0;
        }  

}


int main() {
    initializegenerator();
    // Code fuer den Spielablauf
    int karte=0;
    int kartennr=0;
    int kartenwert=0;
    int handkarten[21]={0};
    int kartenwertdealer=0;
    int *p = &kartenwertdealer;

    while (1)
    {    
        int aktion=0;

        printf("1) Karte ziehen\n2) stay\n");
        scanf("%i", &aktion);
        printf("\n");
        if (aktion==1)
        {
            //printf("[♣%i\n| ♣ |\n[  ♣]\n",getkarte());
            karte=getkarte();
            handkarten[kartennr] = karte;
            printf("[♣%i\n| ♣ |\n[  ♣]\n",handkarten[kartennr]);            
            printintarray(handkarten, kartennr+1);    
            kartenwert=summen(handkarten, kartennr+1);
            printf("%i\n", kartenwert);       
            ++kartennr;
        }
        else if(aktion==2) 
        {
            break;   
        }
        
        if (kartenwert>21)
        {
            puts("der Spieler verliert\n");
            return 0;
        }  

    }

    dealer(p);

    
    if (kartenwertdealer<kartenwert)
    {
        printf("Der Spieler gewinnt!\n");
    }
    else if (kartenwertdealer>kartenwert|| *p<=21)
    {
        printf("Der Spieler verliert...\n");
    }
    else if (kartenwertdealer=kartenwert)
    {
        printf("Gleichstand.\n");
    }
    
    return 0; 
}

