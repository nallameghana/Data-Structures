#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int n;
int array[MAX];
int linearsearch(int [], int);
int binarysearch(int [], int, int, int);
void bubblesort(int [], int);
void insertionsort(int [], int);
void selectionsort(int [], int);
void main()
{
	int ch, key, key1, i, res, r;
    printf("\nEnter no of elements : ");
	scanf("%d", &n);
	printf("\nEnter the elements of array : ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	while(1) {
	printf("\n1.Linear search\n2.Binary search\n3.Bubble sort\n4.Insertion sort\n5.Selection sort\n6.Exit\nEnter choice : ");
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
		case 2: printf("Enter the key to be searched : ");
		        scanf("%d", &key1);
		        r = binarysearch(array, 1, n, key1);
			    if(r == 0)
			    printf("\nKey not found");
			    else
			    printf("\nKey present at position : %d", r + 1);
			    break;
		case 3: bubblesort(array, n);
		        break;
		case 4: insertionsort(array, n);
		        break;
		case 5: selectionsort(array, n);
		        break;
	    case 6: printf("\nExited");
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
int binarysearch(int a[10], int low, int high, int key1)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        if(a[mid] == key1)
           return mid;
        else if(key1 > a[mid])
           return binarysearch(a, mid, n, key1);
        else if(key1 < a[mid])
           return binarysearch(a, 1, mid, key1);
    }
    return 0;
}
void bubblesort(int a[10], int n)
{
    int count, i, j, temp;
    for(int i = 0; i < n; i++)
    {
        count = 0;
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                count++;
            }
        }
        if(count == 0)
          break;
    }
    printf("\nElements after sorting : ");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
void insertionsort(int a[10], int n)
{
    int i, j, temp;
    for(i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while((j >= 0) && (a[j] > temp))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("\nElements after sorting : ");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
void selectionsort(int a[10], int n)
{
    int i, j, temp, min;
    for(i = 0; i < n; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
              min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("\nElements after sorting : ");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
