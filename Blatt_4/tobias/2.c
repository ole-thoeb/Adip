#include <stdio.h>

// Gibt den Nachfolger des übergebenen Wertes zurück
int succ(int x) {
    return ++x;
}

// Gibt den Vorgänger des übergebenen Wertes zurück
int pre(int x) {
    return --x;
}


// addiert x und y
int add(int x, int y)
{
/*
    if (y>0)
    {
        x=succ(x);
        y=pre(y);
    }
*/
    if (y>0)
    {
     return add(succ(x),pre(y));

    }
    else if(y==0)
    {
        return x;
    }
   // add(x,y);

}

int sub(int x, int y)
{
    if (y>0)
    {
        return (sub(pre(x),pre(y)));
    }
    else if(y==0)
    {
        return x;
    }
}

int mult(int x, int y)
{
    if (y>1)
    {
        return (add(x, mult(x, pre(y))));

    }
    else
    {
        return x;
    }
}

int main ()
{
    int x=0, y=0;

    printf("Bitte geben Sie eine Ganze Zahl ein\nx=");
    scanf("%i",&x);
    printf("\n");
    printf("Bitte geben Sie eine Natürliche Zahl ein\ny=");
    scanf("%i",&y);
    printf("\n");
    

printf("Summe=%i\n",add(x, y));
printf("Differenz=%i\n",sub(x, y));
printf("Produkt=%i\n",mult(x, y));
    return 0;
}
