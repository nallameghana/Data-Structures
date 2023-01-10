#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int cq[MAX];
int f = -1;
int r = -1;
void insert();
int is_empty();
int is_full();
void display();
void del();
void len();
void main()
{
	int ch;
	while(1)
	{
        printf("\nMenu in Circular Queue\n1.Enqueue\n2.Display\n3.Dequeue\n4.Length\n5.Exit\nEnter choice : ");
        scanf("%d", &ch);
        switch(ch)
	{
		case 1: insert();
			break;
		case 2: printf("\nDisplaying the elements in circular queue : ");
			display();
			break;
		case 3: del();
			break;
		case 4: printf("\nLength of circular queue till now is : ");
			len();
			break;
		case 5: printf("\nExited");
			exit(0);
			break;
		default: printf("\nInvalid choice!!");
	}
	}
}
int is_empty()
{
	if(r == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int is_full()
{
	if(f == ((r + 1) % MAX))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void insert()
{
	int ele;
	printf("\nEnter an element : ");
	scanf("%d", &ele);
	if(is_empty())
	{
		f = (f + 1)%(MAX);
		r = (r + 1)%(MAX);
		cq[r] = ele;
	}
	else if(is_full())
	{
		printf("\nCircular Queue is full, Can't insert the above element");
	}
	else
	{
		r = (r + 1)%(MAX);
		cq[r] = ele;
	}
}
void display()
{
	int i;
	if(r > f)
	{
		for(i = f; i <= r; i++)
		{
			printf("%d\t", cq[i]);
		}
	}
	else
	{
		for(i = f; i <= (MAX - 1); i++)
		{
			printf("%d\t", cq[i]);
		}
		for(i = 0; i <= r; i++)
		{
			printf("%d\t", cq[i]);
		}
	}
} 
void del()
{
	if(is_empty())
	{
		printf("\nCircular Queue is empty!");
	}
	else if(r == f)
	{
		printf("\nElement deleted is : %d", cq[f]);
		r = f = -1;
	}
	else
	{
		printf("\nElement deleted is : %d", cq[f]);
		f = (f + 1)%(MAX);
	}
}
void len()
{
	int count = 0;
	int i;
	if(r == -1)
	{
		count = 0;
	}
	else if(r > f)
        {
                for(i = f; i <= r; i++)
                {
			count++;
                }
        }
        else
        {
                for(i = f; i <= (MAX - 1); i++)
                {
			count++;
                }
                for(i = 0; i <= r; i++)
                {
			count++;
                }
        }
	printf("%d", count);
}









