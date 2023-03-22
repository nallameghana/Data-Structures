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
Node *getminnode(Node *);
Node *getmaxnode(Node *);
void main()
{
	int ch, k, m, m1;
	while(1) {
		printf("\nMenu in Binary Search Tree\n1.Insert\n2.Inorder\n3.Inorder predecessor\n4.Inorder successor\n5.Exit\nEnter choice : ");
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
			case 3: printf("\nEnter element to which you want to find Inorder predecessor : ");
				    scanf("%d", &m);
				    Node *o = search(root, m);
				    Node *n = getmaxnode(o->left);
				    printf("Inorder predecessor of %d is : %d", m,  n->value);
			        break;
			case 4: printf("\nEnter element to which you want to find Inorder successor : ");
				    scanf("%d", &m1);
				    Node *o1 = search(root, m1);
				    Node *n1 = getminnode(o1->right);
				    printf("Inoder sucessor of %d is : %d", m1, n1->value);
			        break;
			case 5: printf("\nExited");
				    exit(0);
				    break;
		   default :printf("\nInvalid choice");
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
	{	
	     inorder(node->left);
		printf(" %d\t", node->value);
		inorder(node->right);
	}
	
}
Node *search(Node *node, int key)
{
	if(node->value == key)
	{
		return node;
	}
	else if(node == NULL)
	{
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
Node *getminnode(Node *node)
{
    while(node->left != NULL)
    {
        node = node->left;
    }
    return node;
}
Node *getmaxnode(Node *node)
{
    while(node->right != NULL)
    {
        node = node->right;
    }
    return node;
}
