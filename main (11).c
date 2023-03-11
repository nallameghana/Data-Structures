#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int value;
	struct Node *right;
	struct Node *left;
}Node;
Node *root = NULL;
Node *getnode(int key)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->value = key;
	new->left = NULL;
	new->right = NULL;
	return new;
}
Node *insert(Node *node, int key)
{

	if(node == NULL)
	{       Node * new=getnode(key);
		node = new;
	}
	else if(key < node->value)
	{
		node->left = insert(node->left, key);
	}
	else if(key > node->value)
	{
		node->right = insert(node->right, key);
	}
	return node;
}
void inorder(Node *node)
{
	if(node!=NULL)
	{	
	     inorder(node->left);
		printf(" %d\t", node->value);
		inorder(node->right);
	}
	
}
void mirror(Node *node)
{
    Node *temp;
    if(node != NULL)
    {
        mirror(node->left);
        mirror(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
void main()
{
    int n, v, v1;
    printf("\nEnter no of elements to be inserted : ");
    scanf("%d", &n);
    printf("\nEnter the value to be inserted : ");
    scanf("%d", &v);
    if(root == NULL)
    root = insert(root, v);
    for(int i = 0; i < n - 1; i++)
    {
        printf("\nEnter the value to be inserted : ");
        scanf("%d", &v1);
        insert(root, v1);
    }
    printf("\nInorder traversal of bst : ");
    inorder(root);
    mirror(root);
    printf("\nInorder traversal of mirror image of bst : ");
    inorder(root);
}