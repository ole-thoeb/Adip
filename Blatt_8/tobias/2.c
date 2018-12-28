#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{

    int data;
    struct NODE *next;
}NODE;

NODE * push(NODE * head, int wert)
{
    if (head==NULL)
    {
        head=malloc(sizeof(NODE));
        head->data=wert;
        head->next=NULL;
    }
    else
    {
        NODE * temp=malloc(sizeof(NODE));
        temp->data=wert;
        temp->next=head;
        head=temp;
    }
    return head;
}

int pop(NODE ** head)
{
    NODE * current= *head;
    int werttemp=0;
    NODE * tempnode=NULL;
    if (*head==NULL)
    {
        printf ("der Stapel ist leer ");
        return 0;
    }
    else
    {
        werttemp=current->data;
        tempnode=current;
        current=current->next;
        *head=current;
        free(tempnode);        
    }
    
    return werttemp;
}

int peek(NODE * head)
{
    return head->data;
}

int isempty(NODE * head)
{
    int empty=0;
    if (head==NULL)
    {
        empty=1;
    }
    return empty;
}

void print(NODE * head)
{
    NODE * current=head;
    while(current!=NULL)
    {
        printf("%i\n", current->data);
        current=current->next;
    }
    return;
}

int main()
{
    NODE * stapel1=NULL;

    stapel1=push(stapel1, 4);
    stapel1=push(stapel1, 2);
    stapel1=push(stapel1, 1);
    printf("peek…\t%i\n", peek(stapel1));
    print(stapel1);
    printf("pop…\t%i\n", pop(&stapel1));
    printf("Is empty?\t%i\n", isempty(stapel1));
    printf("pop…\t%i\n", pop(&stapel1));
    printf("pop…\t%i\n", pop(&stapel1));
    printf("Is empty?\t%i\n", isempty(stapel1));

printf("\n\nUm auf der obigen Basis eine Queue zu implementieren, wären zwei Vorgehensweisen möglich. Entweder muss zum Entnehmen eines Wertes die gesamte Queue durchlaufen werden, oder es werden zwei Pointer verwendet. Der zweite Pointer sollte immer auf das zweite Element (Second in) zeigen, sodass bei der Funktion pop() current-next auf NULL gesetzt werden kann, nachdem der Wert current->next->data entnommen und free(current->next) durchgeführt wurde.\n");
// Um auf der obigen Basis eine Queue zu implementieren wären zwei Vorgehensweisen möglich. Entweder muss zum Entnehmen eines Wertes die gesamte Queue durchlaufen werden, oder es werden zwei Pointer verwendet. Der zweite Pointer sollte immer auf das zweite Element zeigen, sodass bei der Funktion pop() current-next auf NULL gesetzt werden kann, nachdem der Wert current->next->data entnommen und free(current->next) durchgeführt wurde.

    return 0;
}
