//afsal ts r3b 313
//stack linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct lifo
{	
	int st[20];
	int top;
}stack;

int main()
{
	stack A;
	create(&A);
	int n, n1, val[20],choice;
	do
	{
		printf("1 Push\n2 Pop\n3 Exit.\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			
				if(isfull(&A))
				{
					printf("Stack Overflow.\n");
				
				}
				else
				{
			
					printf("\nEnter element: \n");
					scanf("%d",&val[i]);
					push(&A,val[i]);
					printf("Stack: \n");
					display(&A);
			
				
			}
		}
		else if(choice==2)
		{
			
				if (isempty(&A))
				{
					printf("Stack Underflow.\n");
					
				}
				else
				{
					printf("Popped: %d\n",pop(&A));
					printf("Stack:\n");
					display(&A);
				}
			
		}
		else
			continue;
	}while(choice==0 || choice==1);
	return (0);
}

void create(stack *s)
{
	s->top=-1;
}
void push(stack *s,int element)
{
	s->top++;
	s->st[s->top]=element;
}
int pop(stack *s)
{
	return(s->st[s->top--]);
	
}
int isempty(stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
int isfull(stack *s)
{
	if(s->top==19)
		return 1;
	else
		return 0;
}
void display(stack *s)
{
	for(int i=0;i<=(s->top);i++)
	printf("%d\n",(s->st[i]));
	printf("\n");
	
}
