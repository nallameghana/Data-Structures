#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *head = NULL;
node *temp = NULL;
node *getnode();
void insert_at_beg();
void display();
void insert_at_end();
void insert_at_pos();
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert at begining\n2.Display\n3.Insert at end\n4.Insert at a given position\n5.exit\nEnter choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\nInserting  the element ");
                    insert_at_beg();
                    break;
            case 2: printf("\nDisplaying the elements : ");
                    display();
                    break;
            case 3: printf("\nInsertion at end ");
                    insert_at_end();
                    break;
            case 4: printf("Insertion at a given position");
                    insert_at_pos();
                    break;
            case 5: printf("Exited");
                    exit(0);
            default: printf("Invalid choice");
        }
    }
}
void insert_at_beg()
{
    node *new = getnode();
    if(head == NULL) {
    temp = new;
    head = new;
    }
    else
    {
        new->next = head;
        head = new;
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
void display()
{
    node *curr = head;
    while(curr != NULL)
    {
        printf("%3d", curr->data);
        curr = curr->next;
    }
}
void insert_at_end()
{
    node *new = getnode();
    if(head == NULL)
    {
        temp = new;
        head = new;
    }
    else
    {
        temp->next = new;
        temp = new;
    }
}
void insert_at_pos()
{
    node *new = getnode();
    
}