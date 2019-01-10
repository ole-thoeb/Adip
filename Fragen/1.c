#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node * next;
    int wert;
}node;

void printList(node * head)
{
    node * current=head;

    if (head==NULL)
    {
        printf("Der head ist NULL\n");
        return;
    }
    else
    {
        while(current!=NULL)
        {
            printf("%i\n", current->wert);
            current=current->next;
        }
    }
    return;
}

node * insertLast(node * head, int c)
{
        if(head==NULL){
//            head=malloc(sizeof(node));
//            head->wert=c;
//            head->next=NULL;
            node *new=malloc(sizeof(node));
            new->wert=c;
            new->next=NULL;
            return new;
        }
        else{
            node *current=head;
            node *new=malloc(sizeof(node));
            new->wert=c;
            new->next=NULL;
            while(current->next!=NULL){
                current=current->next;
            }
            current->next=new;
            return head;
        }
}

    int getFirst(node **head)
    {
        //für int get first **
        node *vorueb=*head;
        *head=vorueb->next;
        int x=vorueb->wert;
        free(vorueb);
        return x;
    }




int main()
{
//a
    node * head=NULL;
//b    
    printList(head);
//c
    head=insertLast(head, 5); 
    printList(head);
    head=insertLast(head, 3); 

            //debug
            /*
            head=malloc(sizeof(node));
            head->wert=5;
            head->next=NULL;
                insertLast(head, 5); 
            printList(head);
            */
            
            
            
//d
    printf("got %i\n", getFirst(&head));
    printList(head);
    printf("got %i\n", getFirst(&head));
    printList(head);
        

    return 0;
}
