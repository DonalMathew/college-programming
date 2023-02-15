/*
Name: Donal Mathew P T
Roll no: 20

question: write a program to implement
1.1bubble sort
1.2 selection sort
1.3insertion sort
*/
#include<stdio.h>

void bubble()
{
int n,i,j,temp;int a[20];
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("The sorted array is:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
void insertion()
{
int n,i,j;
	int a[20];
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	printf("The sorted array is:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
void selection()
{
int n,i,j,temp,pos=0,min;int a[20];
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}

	printf("The sorted array is:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
int main()
{
	printf("\nenter any number:\n 1-bubble\n2-insertion\n3-selection");
	int x;
	scanf("%d",&x);
	switch(x)
	{
		case 1:
		bubble();
		break;
		
		case 2:
		insertion();
		break;
		
		case 3:
		selection();
		break;
		
		default:
		printf("invalid input");
	}					
	return(1);
}
