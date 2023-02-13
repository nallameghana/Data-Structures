#include <stdio.h>
#include<stdlib.h>
#define MAX 50
char tree[MAX] = {'\0'};
int n = 15;
void root(char );
void left(char, int);
void right(char, int);
void print_tree();
void main()
{
   while(n != 0) {
        int ch, p1, p2;
        char v, v1, v2;
        printf("\n1.Insert root\n2.Insert left node\n3.Insert right node\n4.Display\n5.Exit\nEnter choice : ");
        scanf(" %d", &ch);
        switch(ch)
        {
          case 1: printf("Enter character value : ");
                  scanf(" %c", &v);
                  root(v);
                  break;
          case 2: printf("Enter character and its parent index : ");
                  scanf(" %c%d", &v1, &p1);
                  left(v1, p1);
                  break;
          case 3: printf("Enter character and its parent index : ");
                  scanf(" %c%d", &v2, &p2);
                  right(v2, p2);
                  break;
          case 4: print_tree();
                  break;
          case 5: printf("Exited");
                  exit(0);
         default: printf("\nInvalid choice!!");
        }
        n--;
    }
}
void root(char key)
{
  if(tree[0] != '\0')
  {
    printf("\nRoot already exists ");
  }
else
{
    tree[0] = key;
}
}
void left(char key, int parent)
{
  if(tree[parent] == '\0')
  {
    printf("\nParent doesnot exist");
  }
  else
  {
    tree[2*parent + 1] = key;
  }
}
void right(char key, int parent)
{
  if(tree[parent] == '\0')
  {
    printf("\nParent doesnot exist");
  }
  else
  {
    tree[2*parent + 2] = key;
  }
}
void print_tree()
{
  int i;
  for(i = 0; i < 15; i++)
  {
    printf("%c\t", tree[i]);
  }
}
