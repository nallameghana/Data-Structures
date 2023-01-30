#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int que[MAX];
static int r = -1;
static int f = -1;
int is_empty();
int is_full();
void enq(int);
void de();
void display();
void len();
void main()
{
    while(1)
    {
    int ch, x;
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Length\n5.Exit\nEnter choice : ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1: printf("\nEnter an element : ");
                scanf("%d", &x);
                enq(x);
                break;
        case 2 :de();
                break;
        case 3: printf("Elements of queue are : ");
                display();
                break;
        case 4: printf("Length of queue till now is : ");
                len();
                break;
        case 5: printf("Exited");
                exit(0);
                break;
        default: printf("Invalid choice!!");
    }
}
}
int is_empty()
{
    if(f == -1)
      return 1;
    else
      return 0;
}
int is_full()
{
    if(r == (MAX - 1))
    return 1;
    else
    return 0;
}
void enq(int n)
{
    if(is_empty())
    {
        r = r + 1;
        que[r] = n;
        f++;
    }
    else if(is_full())
    {
        printf("\nQueue is full, can't insert the given element\n");
    }
    else
    {
        r = r + 1;
        que[r] = n;
    }
}
void de()
{
    if(is_empty())
    {
        printf("\nQueue is empty\n");
    }
    else if(r == f)
    {
        printf("Deleted element : %d", que[f]);
        r = f = -1;
    }
    else
    {
        printf("Deleted element : %d", que[f]);
        f = f + 1;
    }
}
void display()
{
    int i;
    for(i = f; i <= r; i++)
    {
        if(f > -1)
        printf("%d\t", que[i]);
    }
    if(is_empty())
    {
        printf("There are no elements in Queue!\n");
    }
}
void len()
{
    int i, count = 0;
    for(i = f; i <= r; i++)
    {
        if(i > -1)
        count++;
    }
    printf("%d", count);
}

