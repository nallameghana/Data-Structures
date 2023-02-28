#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int n;
int array[MAX];
int linearsearch(int [], int);
void main()
{
	int ch, key, i, res;
        printf("\nEnter no of elements : ");
	scanf("%d", &n);
	printf("\nEnter the elements of array : ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	while(1) {
	printf("1.Linear search\n2.Exit\nEnter choice : ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: printf("\nEnter the key to be searched : ");
			scanf("%d", &key);
			res = linearsearch(array, key);
			if(res == 0)
				printf("\nKey not found");
			else
				printf("\nKey present at position : %d", res + 1);
			break;
		case 2: printf("\nExited");
			exit(0);
		default: printf("\nInvalid choice!");
	}
	}
}
int linearsearch(int a[10],int k)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(a[i] == k) {
			return i;
			break;
		}

	}
	return 0;
}

	



	

