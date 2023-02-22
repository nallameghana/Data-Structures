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
void preorder(Node *);
void postorder(Node *);
Node *search(Node *, int);
Node *getminnode(Node *);
Node *getmaxnode(Node *);
Node *deletenode(Node *, int);
int height(Node *);
void main()
{
	int ch, k, m, l, h;
	while(1) {
		printf("\nMenu in Binary Search Tree\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Delete\n7.Height\n8.Exit\nEnter choice : ");
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
			case 3: preorder(root);
			        break;
			case 4: postorder(root);
			        break;
			case 5: printf("\nEnter key to be searched : ");
				    scanf("%d", &m);
				    search(root, m);
			        break;	
			case 6: printf("\nEnter element to be deleted : ");
			        scanf("%d", &l);
			        deletenode(root, l);
			        break;
			case 7: h = height(root);
			        printf("Height of BST till now : %d", h);
			        break;
			case 8: printf("\nExited");
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
void preorder(Node *node)
{
    if(node!=NULL)
    {
        printf("%d\t", node->value);
        preorder(node->left);
        preorder(node->right);
        
    }
}
void postorder(Node *node)
{
    if(node!=NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->value);
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
Node *deletenode(Node *node, int key)
{
    if(node == NULL)
    {
        return NULL;
    }
    else if(key < node->value)
    {
        node->left = deletenode(node->left, key);
    }
    else if(key > node->value)
    {
        node->right = deletenode(node->right, key);
    }
    else if(node->left == NULL)
    {
        Node *temp = node->right;
        free(node);
        return temp;
    }
    else if(node->right == NULL)
    {
        Node *temp = node->left;
        free(node);
        return temp;
    }
    else if((node->left != NULL) && (node->right != NULL))
    {
        Node *minnode = getminnode(node->right);
        node->value = minnode->value;
        node->right = deletenode(minnode, minnode->value);
    }
    return node;
}
int height(Node *node)
{
    int l, r;
    if(node == NULL)
        return 0;
    else
    {
        l = height(node->left);
        r = height(node->right);
        
        if(l > r)
        {
            return l + 1;
        }
        else
        {
            return r + 1;
        }
    }
}