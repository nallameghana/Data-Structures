#include <stdio.h>
#define MAX 10
int G[MAX][MAX];
void main()
{
	int n, i, j;
	printf("\nEnter no of vertices : ");
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
           for(j = 1; j <= n; j++)
	   {
		  printf("Enter the edge(%d, %d)", i, j);
		  scanf("%d", &G[i][j]);
	   }
	}
	for(i = 1; i <= n; i++)
        {
           for(j = 1; j <= n; j++)
           {
                  printf("%d\t", G[i][j]);
           }
	   printf("\n");
        }

}

