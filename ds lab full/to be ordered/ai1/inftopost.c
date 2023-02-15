/* INFIX TO POSTFIX EXPRESSION CONVERSION AND EVALUATION
Author:Aasiya Yasir
rollno:301*/
*/

#include <stdio.h>
#define MAXSIZE 100
struct stack
{
	char st[MAXSIZE];
	int top;
};

typedef struct stack stack;
void create(stack *s);
void push(stack *s, char c);
char pop(stack *s);
int IsEmpty(stack *s);
char topel(stack *s);
int isp(char c);
int icp(char c);
void eval(char exp[100]);
void push2(stack *s,float val);
float pop2(stack *s);
int main()
{
	stack A;
	create(&A);
	char exp[100],pf[100];
	char c;
	int j=0;
	printf("Enter expression:\n");
	scanf("%s",exp);
	for(int i=0;exp[i]!='\0';i++)
	{
		c=exp[i];
		if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
		{
			printf("%c",c);
			pf[j++]=c;
		}
		else if(c==')')
		{
			while(topel(&A)!='(')
			{
				pf[j++]=topel(&A);
				printf("%c",pop(&A));
			}
			pop(&A);
		}
		else
		{
			while(isp(topel(&A))>=icp(c))
			{
				pf[j++]=topel(&A);
				printf("%c",topel(&A));
				pop(&A);
			}
			push(&A,c);
		}
	}
	while(!IsEmpty(&A))
	{
		pf[j++]=topel(&A);
		printf("%c",topel(&A));
		pop(&A);
	}
	pf[j]='\0';
	printf("\n");
	eval(pf);
	return(0);
}
void create(stack *s)
{
	s->top=-1;
}
void push(stack *s, char c)
{
	s->top++;
	s->st[s->top]=c;
}
char pop(stack *s)
{
	return(s->st[s->top--]);
}
int IsEmpty(stack *s)
{
	if(s->top==-1)
	return 1;
	else
	return 0;
}
char topel(stack *s)
{
	return(s->st[s->top]);
}
int isp(char c)
{
	if(c=='+' || c=='-')
	return 2;
	else if(c=='*' || c=='/')
	return 4;
	else if(c=='^')
	return 5;
	else if(c=='(')
	return 0;
}
int icp(char c)
{
	if(c=='+' || c=='-')
	return 1;
	else if(c=='*' || c=='/')
	return 3;
	else if(c=='^')
	return 6;
	else if(c=='(')
	return 9;
	else if(c==')')	
	return 0;
}
void eval(char exp[100])
{
	stack B;
	create(&B);
	char c;
	float val,result=1;
	for(int i=0; exp[i]!='\0';i++)
	{
		c=exp[i];
		if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
		{
			printf("Enter value for your operand, %c: ",c);
			scanf("%f",&val);
			push2(&B,val);
		}
		else
		{
				float op1=pop2(&B);
				float op2=pop2(&B);
				if(c=='+')
				{
					result=op2+op1;
					push2(&B,result);
				}
				else if(c=='-')
				{
					result=op2-op1;
					push2(&B,result);
				}
				else if(c=='*')
				{
					result=op2*op1;
					push2(&B,result);
				}
				else if(c=='/')
				{
					result=op2/op1;
					push2(&B,result);
				}
				else if(c=='^')
				{
					for(int j=1;j<=op2;j++)
					{
						result*=op1;
					}
					push2(&B,result);
				}	
		}
		
	}
	printf("RESULT:\n%0.2f\n",result);
}
void push2(stack *s,float val)
{
	s->top++;
	s->st[s->top]=val;
}
float pop2(stack *s)
{
	return(s->st[s->top--]);
}
