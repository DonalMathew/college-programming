#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left,*right;
};
struct node* getNode(int key)
{
	struct node* new=malloc(sizeof(struct node));
	new->data=key;
	new->left=NULL;
	new->right=NULL;
	return(new);
}
struct node*create()
{
	struct node* new;
	int n,data;
	printf("Enter 1 to create nodes or 0 to stop: ");
	scanf("%d",&n);
	if(n==0)
	return(NULL);
	else
	{
		new=malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&data);
		new->data=data;
		printf("For left child of %d\n",data);
		new->left=create();
		printf("For right child of %d\n",data);
		new->right=create();
		return(new);
	}
}
void Inorder(struct node* root)
{
	if(root==NULL)
	return;
	Inorder(root->left);
	printf("%d\t",root->data);
	Inorder(root->right);
}
void insert(struct node*root, int key)
{
	struct node* prev;
	while(root!=NULL)
	{
		prev=root;
		if(root->data == key)
		{
			printf("Element already present so no insertion");
			return;
		}
		else
		{
			if(root->data > key)
				root=root->left;
			else
				root=root->right;
		}
	}
	struct node* new=getNode(key);
	if(key> prev->data)
	prev->right=new;
	else
	prev->left=new;
}
int main()
{
	struct node* root;
	root=create();
	int key;
	printf("Enter element to be inserted: ");
	scanf("%d",&key);
	insert(root,key);
	Inorder(root);return(0);
}
