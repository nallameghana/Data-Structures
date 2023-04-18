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
void del_at_beg();
void del_at_end();
void del_at_pos();
void len();
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert at begining\n2.Display\n3.Insert at end\n4.Insert at a given position\n5.Deletion at start\n6.Deletion at end\n7.Deletion at a given position\n8.Length of linked list\n9.exit\nEnter choice : ");
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
            case 5: printf("Deletion at start");
                    del_at_beg();
                    break;
            case 6: printf("Deletion at end");
                    del_at_end();
                    break;
            case 7: printf("Deletion at a given position");
                    del_at_pos();
                    break;
            case 8: printf("Length of linked list");
                    len();
                    break;
            case 9: printf("Exited");
                    exit(0);
            default : printf("Invalid choice!!");
                      
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
        temp->next = new;
        temp = new;
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
        new->next = head;
        head = new;
    }
}
void insert_at_pos()
{
    int i;
    int k;
    printf("\nEnter the position to insert an element : ");
    scanf("%d", &k);
    node *new = getnode();
    temp = head;
    for(i = 1; i < k - 1; i++)
    {
        temp = temp->next;
    }
        new->next = temp->next;
        temp->next = new;
    
    
}
void del_at_beg()
{
    node *temp1 = head;
    if(head == NULL)
    {
        printf("\nThere are no nodes to delete!");
    }
    else if(head->next == NULL)
    {
        printf("\nData deleted is : %d", head->data);
        head = NULL;
        temp = NULL;
        free(temp1);
    }
    else
    {
        head = head->next;
        free(temp1);
    }
}
void del_at_end()
{
    node *temp1 = head;
    node *t;
    if(head == NULL)
    {
        printf("There are no nodes to delete!");
    }
    else if(head->next == NULL)
    {
        printf("\nData deleted is : %d", head->data);
        head = NULL;
        temp = NULL;
        free(temp1);
    }
    else
    {
        while(temp1->next != temp)
        {
            temp1 = temp1->next;
        }
            t = temp1->next;
            temp1->next = NULL;
            temp = temp1;
            free(t);
        
    }
}
void del_at_pos()
{
    int i, m;
    node *t;
    node *temp1 = head;
    printf("\nEnter the position in which element be deleted :");
    scanf("%d", &m);
    for(i = 1; i < m - 1; i++)
    {
        temp1 = temp1->next;
    }
    t = temp1->next;
    temp1->next = temp1->next->next;
    free(t);
}
void len()
{
    node *curr = head;
    int count = 0;
    while(curr != NULL)
    {
        curr = curr->next;
        count++;
    }
    printf("\nLength of linked list till now is %d", count);
}
