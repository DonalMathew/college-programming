/* Circular Queue Operations
author:Aasiya yasir
rollno:301*/
*/

#include <stdio.h>
void enq(int *front,int *rear,int size,int *arr)
{
	int n,begin,end;
	if((*rear+1)%size==*front)
	{
		printf("Queue Full");
	}
	else
	{
		printf("Enter element to be inserted:\n");
		scanf("%d",&n);
		if(*rear==-1 && *front==-1)
		{
			*front++;
		}
		*rear=(*rear+1)%size;
		*(arr+*rear)=n;
	}
}

void dq(int *front,int *rear,int size,int *arr)
{
	if((*front==-1 && *rear==-1))
	{
		printf("Queue Empty");
	}
	else
	{
		if(*front==*rear)
		{
			*front=-1;
			*rear=-1;
		}
		else
		{
			*front=(*front+1)%size;
		}
	}
}

void display(int *front,int *rear,int size,int *arr)
{
	int begin,end;
	begin=*front;
	end=*rear;
	if((*front==-1 && *rear==-1))
	{
		printf("Queue Empty");
	}
	else
	{
		while ((begin)%size!=end)
		{
			begin=(begin)%size;
			printf("%d\t",*(arr+begin));
			begin++;
		}
		begin=(begin)%size;
		printf("%d\t",*(arr+begin));
		printf("\n");
	}
}

int main()
{
	printf("Circular Queue Using Arrays\n");
	int n,op,front=-1,rear=-1,flag=0;
	printf("Enter Size of Queue:\n");
	scanf("%d",&n);
	int arr[n];
	while(flag==0)
	{
		printf("Choose an Operation:\n 1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1 :
				enq(&front,&rear,n,arr);
				break;
			case 2:
				dq(&front,&rear,n,arr);
				break;
			case 3:
				display(&front,&rear,n,arr);
				break;
			case 4:
				flag=1;
				break;
		}
	}
}

