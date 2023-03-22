#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    char t[50], p[50];
    printf("Enter the text : ");
    gets(t);
    printf("\nEnter the pattern : ");
    gets(p);
    int n = strlen(t);
    int m = strlen(p);
    int i = 0, j = 0, count = 0;
    while(i <= n - m)
    {
    if(t[i + j] == p[j])
    {
        if(j < m - 1)
        {
            j++;
            count++;
        }
        else if(j == m - 1)
        {
            count++;
            printf("Pattern matched in the given text at position : %d", i);
            break;
        }
    }
    else
    {
        if(i < n - m)
        {
            i++;
            j = 0;
            count++;
        }
        else if(i == n - m)
        {
            count++;
            printf("Pattern not matched in the given text");
            break;
        }
    }
    }
    printf("\nNo of Comparisions : %d", count);
}
