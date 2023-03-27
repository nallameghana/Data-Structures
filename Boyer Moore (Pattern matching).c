#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lastoccur(char p1[50], char k, int m)
{
    for(int i = m - 1; i >= 0; i++)
    {
        if(p1[i] == k)
        {
            return i;
        }
    }
    return -1;
}
int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}
int boyremoore(char t1[50], char p1[50])
{
    int n = strlen(t1);
    int m = strlen(p1);
    int i = m - 1;
    int j = m - 1;
    while(i <= n - 1)
    {
        if(t1[i] == p1[j])
        {
            if(j == 0)
            {
               return i;
            }
            
            else
            {
                i = i - 1;
                j = j - 1;
            }
        }
        else
        {
            int lst = lastoccur(p1, t1[j], m);
            i = i + m - min(j, 1 + lst);
            j = m - 1;
        }
    }
    return -1;
}
void main()
{
    char t[50], p[50];
    puts("Enter the text : ");
    gets(t);
    puts("Enter the pattern : ");
    gets(p);
    int res = boyremoore(t, p);
    if(res == -1)
    {
       printf("Pattern not found in the given text"); 
    }
    else
    {
        printf("Pattern present in text at position : %d", res);
    }
    
}
