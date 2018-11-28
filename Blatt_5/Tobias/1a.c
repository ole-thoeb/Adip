#include <stdio.h>
#include <ctype.h>

int palindrom(char wort[])
{
    size_t strlen(const char *str);
    int tolower(int c);

    char trow[strlen(wort)];

    for (int i=0, j=strlen(wort)-1; i<=strlen(wort); i++)
    {
        trow[j]=wort[i];
        j--;
    }
    for (int i=0; i<=strlen(wort); i++)
    {
        printf("%c", trow[i]);
    }
        printf("\n");
    int palindrom=1;
    for (int i=0; i<=strlen(wort); i++)
    {
        if (tolower(trow[i])!=tolower(wort[i]))
        {
            palindrom=0;
            printf("%s ist kein Palindrom\n", wort);
            return palindrom;
        }
    }
    printf("%s ist ein Palindrom\n", wort);
    return palindrom;
}

int main()
{
    // {} bei mehr als einem Element?
    char wort[]={"Ebbe"};
    char wort2[]={"Hand"};
    palindrom(wort);
    palindrom(wort2);
    char customwort[50]={0};
    
    printf("\nGeben Sie ein Wort ein:\n");
    fgets(customwort, 50, stdin);
        //tolower()
    for (int i=0; customwort[i]!=0; i++)
    {
        if(customwort[i]=='\n')
        {
            customwort[i]=customwort[i+1];
        }
    }
    palindrom(customwort);
    
    return 0;
}
