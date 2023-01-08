#include <stdio.h>
#include <stdlib.h>
typedef struct que
{
    int data;
    struct que *next;
}que;
que *f = NULL;
que *r = NULL;
que *getnode();
void enq();
void display();
void de();
void len();
void main()
{
    int ch;
    while(1)
    {
    printf("\n1.Enqueue\n2.Display\n3.Dequeue\n4.Length\n5.Exit\nEnter choice : ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1: enq();
                break;
        case 2: printf("\nElements of queue till now are : ");
                display();
                break;
        case 3: de();
                break;
        case 4: printf("\nLength of queue till now is : ");
                len();
                break;
        case 5: printf("Exited");
                exit(0);
                break;
        default: printf("Invalid choice!!");
    }
    }
}
que *getnode()
{
    que *new = (que *)malloc(sizeof(que));
    printf("\nEnter an element to be inserted : ");
    scanf("%d", &new->data);
    new->next = NULL;
    return new;
}
void enq()
{
    que *new = getnode();
    if(f == NULL)
    {
        r = f = new;
    }
    else if(r == f)
    {
        f->next = new;
        r = new;
    }
    else
    {
        r->next = new;
        r = new;
        
    }
}
void display()
{
    que *temp = f;
    if(f == NULL)
    {
        printf("There are no elements in queue!");
    }
    else
    {
    while(temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    }
}
void de()
{
    que *temp1;
    temp1 = f;
    if(f == NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("Element deleted is : %d", f->data);
        f = f->next;
        free(temp1);
    }
}
void len()
{
    que *temp2 = f;
    int count = 0;
    if(f == NULL)
    {
        printf("There are no elements to display!");
    }
    else
    {
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
        count++;
    }
    printf("%d", count + 1);
    }
}

