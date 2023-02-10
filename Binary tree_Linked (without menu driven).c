#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char value;
    struct node *left;
    struct node *right;
}node;
node *root = NULL;
node *getnode()
{
    node *new = (node*)malloc(sizeof(node));
    printf("\nEnter a value : ");
    scanf(" %c", &new->value);
    new->left = NULL;
    new->right = NULL;
  return new;
}
void insert_root()
{
  node *new = getnode();
  if(root == NULL)
  {
    root = new;
  }
}
void insert_left(node *root)
{
  node *new = getnode();
  if(root->left == NULL)
  {
    root->left = new;
  }
}
void insert_right(node *root)
{
  node *new = getnode();
  if(root->right == NULL)
  {
    root->right = new;
  }
}
void preorder(node *root)
{
    if(root != 0) 
    {
      printf("%c\t", root->value);
      preorder(root->left);
      preorder(root->right);
    }
}
void inorder(node *root)
{
    if(root != 0)
    {
        inorder(root->left);
        printf("%c\t", root->value);
        inorder(root->right);
    }
}
void postorder(node *root)
{
    if(root != 0)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c\t", root->value);
    }
}

int main()
{
    insert_root();
    insert_left(root);
    insert_right(root);
    insert_left(root->left);
    insert_right(root->left);
    insert_left(root->right);
    insert_right(root->right);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
  return 0;
}
