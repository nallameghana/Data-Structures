#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *head = NULL;
node *temp = NULL;
node *headr = NULL;
node *getnode();
void display();
void insert_a_node();
void rev();
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Creation of LL\n2.Display\n3.Reverse the linked list\n4.exit\nEnter choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insert_a_node();
                    break;
            case 2: printf("\nDisplaying the elements : ");
                    display();
                    break;
            case 3: printf("\nAfter reversing the LL elements are :");
                    rev();
                    exit(0);
            case 4: printf("Exited");
                    exit(0);
            default : printf("Invalid choice!!");
                      
        }
    }
}
node *getnode()
{
    node *new = (node*)malloc(sizeof(node));
    printf("\nEnter element : ");
    scanf("%d", &new->data);
    new->next = NULL;
    return new;
}
void insert_a_node()
{
    node *new = getnode();
    if(head == NULL)
    {
        temp = new;
        head = new;
        headr = new;
    }
    else
    {
        temp->next = new;
        temp = new;
    }
}
void display()
{
    node *current = head;
    while(current->next != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("%d", current->data);
}
void rev()
{
   node *prev, *curr;
   node *t;
   if(headr != NULL)
   {
       prev = headr;
       curr = headr->next;
       headr = headr->next;
       prev->next = NULL;
       while(headr != NULL)
       {
           headr = headr->next;
           curr->next = prev;
           prev = curr;
           curr = headr;
       }
       headr = prev;
   }
    t = headr;
    while(t->next != NULL)
    {
        printf("%d->", t->data);
        t = t->next;
    }
    printf("%d", t->data);
}
