/*
Name: Donal Mathew P T
Roll no: 20

question: 

Write a program to reverse the content of string using
stack

*/

#include<stdio.h>
#include<string.h>
#define size 50
int stack[50];
int top=-1;
char push(char );
char pop();
int main()
{
	char str[20];
	char rev[20];
 	int i;
	printf("Enter the string : \n" );
	fgets(str,sizeof(str),stdin);
	int l=strlen(str);
 	for(i=0;i<l;i++)
 	{
   		push(str[i]);
  	}
 	for(i=0;i<strlen(str);i++)
  	{
     	str[i]=pop(); 
  	}
 	printf("Reversed string is : ");
 	puts(str);
}
char push(char ch)
{
    	if(top==(size-1))
    	printf("Stack is Overflow\n");
    	else
    	stack[++top]=ch;
}
char pop()
{
	if(top==-1)
    	printf("Stack is Underflow\n");
    	else
    	return stack[top--];
}
