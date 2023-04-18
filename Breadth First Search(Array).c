#include <stdio.h>
#include <stdlib.h>
#define MAX 7
int que[MAX];
int G[MAX][MAX];
int visited[MAX] = {0};
static int r = -1;
static int f = -1;
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
int de()
{
    if(is_empty())
    {
        printf("\nQueue is empty\n");
    }
    else if(r == f)
    {
        int u = que[f];
        r = f = -1;
        return u;
    }
    else
    {
        int u = que[f];
        f = f + 1;
        return u;
    }
}
void breadthfirstsearch(int G[][MAX], int s, int n)
{
    visited[s] = 1;
    printf("%d\t", s);
    enq(s);
    while(!is_empty())
    {
        int u = de();
        for(int i = 1; i <= n; i++)
        {
            if(visited[i] != 1 && G[u][i] == 1)
            {
                printf("%d\t", i);
                enq(i);
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    int n;
    printf("\nEnter number of vertices : ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("\nEnter the edge (%d, %d) : ", i, j);
            scanf("%d", &G[i][j]);
        }
    }
    breadthfirstsearch(G, 1, n);
}
