#include <stdio.h>
#include <stdlib.h>
#define MAX 7
int G[MAX][MAX];
int visited[MAX] = {0};
void depthfirstsearch(int G[][MAX], int s, int n)
{
    visited[s] = 1;
    printf("%d\t", s);
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] != 1 && G[s][i] == 1)
        {
            depthfirstsearch(G, i, n);
        }
    }
    return ;
    
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
    depthfirstsearch(G, 1, n);
}