#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
    int data;
    int power;
    struct node *next;
}node;
node *head = NULL;
node *temp = NULL;
node *getnode();
void insert_a_node();
void display();
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert an element in polynomial\n2.Display\n3.Exit\nEnter choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insert_a_node();
                    break;
            case 2: printf("\nDisplaying the elements : ");
                    display();
                    break;
            case 3: printf("Exited");
                    exit(0);
            default : printf("Invalid choice!!");
                      
        }
    }
}
void insert_a_node()
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
node *getnode()
{
    node *new = (node*)malloc(sizeof(node));
    printf("\nEnter element : ");
    scanf("%d", &new->data);
    puts("\nEnter power : ");
    scanf("%d", &new->power);
    new->next = NULL;
    return new;
}
void display()
{
    node *curr = head;
    while(curr != NULL)
    {
        if(curr->power == 0) {
            printf("%d", curr->data);   
        }
        else {
        printf("%d", curr->data);
        printf("x^%d\t", curr->power);
        printf("+\t");
        }
        curr = curr->next;
    }
}
