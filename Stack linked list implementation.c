#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *head = NULL;
node *top = NULL;
void push();
void display();
void pop();
void peek();
void len();
node *getnode();
void main()
{
    int ch;
    int x;
    while(1)
    {
    printf("\n1.push\n2.Display\n3.Pop\n4.Peek\n5.Length\n6.Exit\nEnter choice : ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1: printf("Insertion of an element");
                push();
                break;
        case 2: printf("Displaying elements in stack : ");
                display();
                break;
        case 3: printf("Pop an element in stack");
                pop();
                break;
        case 4: printf("Peek element is : ");
                peek();
                break;
        case 5: printf("Length of stack till now is : ");
                len();
                break;
        case 6: printf("Exited");
                exit(-1);
                break;
        default: printf("Invaild choice!!");
    }
    }
}
node *getnode()
{
    node *new = (node *)malloc(sizeof(node));
    printf("\nEnter an element : ");
    scanf("%d", &new->data);
    new->next = NULL;
    return new;
}
void push()
{
    node *new = getnode();
    if(top == NULL)
    {
        top = new;
        head = new;
    }
    else
    {
        top->next = new;
        top = new;
    }
}
void display()
{
    node *curr = head;
    while(curr->next != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("%d", curr->data);
}
void pop()
{
    node *temp = head;
    node *t = top;
    while(temp->next != top)
    {
        temp = temp->next;
    }
    top = temp;
    temp->next = NULL;
    free(t);
}
void peek()
{
    printf("%d", top->data);
}
void len()
{
    node *temp1 = head;
    int count = 0;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
        ++count;
    }
    printf("%d", count + 1);
}