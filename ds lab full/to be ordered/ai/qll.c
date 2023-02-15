//ADITHYA PRAKASH
#include <stdio.h>
#include <stdlib.h>
struct linkedlist
{
	int data;
	struct linkedlist *link;
};

typedef struct linkedlist list;

list* create();
list* enqueue(list *head,int data);
list* dequeue(list *head);
void display(list *head);

int main()
{
	list *head=NULL;
	int choice;
	do
	{
		printf("\nEnter choice:\n 1 for enqueue.\n 2 for dequeue.\n 3 for display.\n Any other number to exit.\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			int data;
			printf("Enter number to insert:\n");
			scanf("%d",&data);
			head=enqueue(head,data);
			printf("QUEUE:  ");
			display(head);
		}
		else if(choice==2)
		{
			head=dequeue(head);
			printf("QUEUE:  ");
			display(head);
		}
		else if(choice==3)
		{
			printf("QUEUE:  ");
			display(head);
		}
		else
		{
			printf("END.\n");
		}
	}while(choice==1 || choice==2 || choice==3);
	return (0);
}
list* create()
{
	list *x=(list*)malloc(sizeof(list));
	return x;
}
list* enqueue(list *head,int data)
{
	list* newnode=create();
	newnode->data=data;
	if(head==NULL)
	{
		newnode->link=head;
		head=newnode;
	}
	else
	{
		list *temp=head;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=newnode;
		newnode->link=NULL;
	}
	return head;
}
list* dequeue(list *head)
{
	if(head->link == NULL)
	{
		head=head->link;
		printf("Queue is empty.\n");
	}
	else
	{
		head=head->link;
	}
	return head;
}
void display(list *head)
{
	if(head != NULL)
	{
		while(head->link != NULL)
		{
			printf("%d ", head->data);
			head=head->link;
		}
		printf("%d ", head->data);
	}
}

