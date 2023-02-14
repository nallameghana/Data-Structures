#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int value;
	struct Node *right;
	struct Node *left;
}Node;
Node *root = NULL;
Node *getnode(int);
Node *insert(Node *, int);
void inorder(Node *);
Node *search(Node *, int);
void main()
{
	int ch, k, m;
	while(1) {
		printf("\nMenu in Binary Search Tree\n1.Insert\n2.Inorder\n3.Search\n4.Exit\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch) 
		{
			case 1: printf("\nEnter value to be inserted : ");
			        scanf("%d",&k);
			        if(root==NULL)
				root=insert(root,k);	
				insert(root, k);
				break;
			case 2: inorder(root);
				break;

			case 3:	printf("\nEnter key to be searched : ");
				scanf("%d", &m);
				search(root, m);
			        break;	
			case 4 :printf("\nExited");
				exit(0);
				break;
		      default : printf("\nInvalid choice");
		}
	}
}
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
		
	{      inorder(node->left);
		printf(" %d\t", node->value);
		inorder(node->right);
	}
	
}
Node *search(Node *node, int key)
{
	if(node->value == key)
	{
		printf("\nKey found");
		return node;
	}
	else if(node->right == NULL)
	{
		printf("\nKey not found");
		return node;
	}
	else if(node->value < key)
	{
		return search(node->right, key);
	}
	else if(node->value > key)
	{
		return search(node->left, key);
	}
}





