#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
    int wert;
    struct tnode * r;
    struct tnode * l;
}tnode;

void printprae(tnode * head)
{
    tnode * current=head;
    //rekursiv!!!
    /*
    while(current!=NULL)
    { 
        printf("%i\n", current->wert);
        current=current->l;
    }
    */

    printf("%i ", current->wert);
    if ((current->l)!=NULL)
    {
        printprae(current->l);
    }
    if(current->r!=NULL)
    {
        printprae(current->r);
    }
    return; 
}
void printpost(tnode * head)
{

    tnode * current=head;
/*
    printf("%i\n", current->wert);
    if (current->l==NULL)
    {
        //return;
    }
*/
    if(current!=NULL)
    {
        printpost(current->l);
        printpost(current->r);
        printf("%i ", current->wert);
    }
    return;
}

void printin(tnode * head)
{
    tnode *current=head;
    if (current!=NULL)
    {
        printin(current->l);
        printf("%i ", current->wert);
        printin(current->r);
    }
    return;
}

int main()
{
    tnode * baum=NULL;//malloc(sizeof(tnode));
//    baum1=NULL;

/*
            4
    2               6
1       3       5       8
*/
    printf("            4\n    2               6\n1       3       5       8\n\n");
    tnode * baumcursor=malloc(sizeof(tnode));
    baumcursor->wert=4;
    baumcursor->r=malloc(sizeof(tnode));
    baumcursor->l=malloc(sizeof(tnode));
    baum=baumcursor;

    baumcursor->r->wert=6;
    baumcursor->l->wert=2;

    baumcursor->r->r=malloc(sizeof(tnode));
    baumcursor->r->r->wert=8;
    baumcursor->r->l=malloc(sizeof(tnode));
    baumcursor->r->l->wert=5;
    baumcursor->l->r=malloc(sizeof(tnode));
    baumcursor->l->r->wert=3;
    baumcursor->l->l=malloc(sizeof(tnode));
    baumcursor->l->l->wert=1;

    printf("pre\t");
    printprae(baum);
    printf("\n");
    printf("post\t");
    printpost(baum);
    printf("\n");
    printf("in\t");
    printin(baum);
    printf("\n");

    printf("Level-Order kann wie folgt umgesetzt werden: Es erscheint äußerst problematisch, den Durchlauf rekursiv zu implementieren.\n Es sollte ein Array verwendet werden, in das die Knoten in der richtigen Reihenfolge eingefügt werden. Man setzt in das Array einen ersten Knoten ein und beginnt, das Array durchzulaufen. Sobald eine Stelle im Array aufgerufen wird, müssen die folgenden current->l und current->r in das Array eingefügt werden, sofern sie nicht NULL sind. Das Array wird weiter durchgelaufen, und die current->l und current->r des jeweiligen current eingefügt, bis man beim letzten Element im Array ankommt, das einen Wert enthält.\n Es kann nun das Array noch einmal durchlaufen werden und der Wert jeder Arraystelle ausgegeben werden. (Alternativ hat man das Ausgeben von jedem Knoten schon durchgeführt, als man current->l und current->r ausgegeben hatte.\n");
    return 0;
}
