/*
Name: Donal Mathew P T
Roll no: 20

question: 

Using stack convert an infix expression to a postfix
expression and evaluate the postfix expression.

*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
void push(int );
int pop();
void getLine(char *, int );
int isAlpha(char );
int isOp(char );
int priority(char );
int infixToPostfix(char *, char *, int *);
int power(int a, int b);
void display();
int stack[MAXSIZE];
int top=-1;
void main() 
{
    char infix[MAXSIZE], postfix[MAXSIZE];
    int values[MAXSIZE], pf_len, n, a, b;
    printf("Enter the infix expression: ");
    getLine(infix,MAXSIZE);
    pf_len=infixToPostfix(infix,postfix,&n);

    printf("Enter the values for the operands: ");
    for(int i=0;i<n;i++)
        scanf("%d",&values[i]);
    top=-1;

    printf("Expression in postfix: ");
    for(int pf=0,val=0;pf<pf_len;pf++) 
    {
        printf("%c",postfix[pf]);
        if(isAlpha(postfix[pf])) 
        {
            push(values[val++]);
        } else 
        {
            a=pop();
            b=pop();
            switch(postfix[pf]) 
            {
                case '+':
                    push(b+a);
                    break;
                case '-':
                    push(b-a);
                    break;
                case '*':
                    push(b*a);
                    break;
                case '/':
                    push(b/a);
                    break;
                case '^':
                    push(power(b,a));
                    break;
            }
        }
    }

    printf("\n");
    printf("Result: %d\n",pop());
}
void push(int item) 
{
    if(top>=MAXSIZE) 
    {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top]=item;
}

int pop() 
{
    if(top==-1) 
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[top--];
}

void getLine(char *str, int limit) 
{
    char c;
    int i=0;
    while ((c=getchar()) != '\n' && i<limit-1) 
    {
        str[i++]=c;
    }
    str[i]='\0';
    while(c!='\n')
    {
        c=getchar();
    }
}

int isAlpha(char c) 
{
    if(c>='A' && c<='Z' || c>='a' && c<='z')
        return 1;
    return 0;
}

int isOp(char c) 
{
    if (c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return 1;
    return 0; 
}

int priority(char c) 
{
    switch (c) 
    {
        case '^':
            return 4;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 1;
    }
}

int infixToPostfix(char *infix, char *postfix, int *n) 
                                                                                                         {
    char x;
    int pf=0;
    *n=0;
    top=0;
    push('(');
    while(*infix!='\0') 
    {
        x=pop();
        if(isAlpha(*infix)) 
        {
            push(x);
            postfix[pf++]=*infix;
            (*n)++;
        } 
        else if (isOp(*infix)) 
        {
            if(priority(*infix)>priority(x)) 
            {
                push(x);
                push(*infix);
            } 
            else 
            {
                while(priority(*infix)<=priority(x)) 
                {
                    postfix[pf++]=x;
                    x=pop();
                }
                push(x);
                push(*infix);
            }
        
        } 
        else if (*infix=='(') 
        {
            push(x);
            push(*infix);
        } 
        else if (*infix==')') 
        {
            while(x!='(') 
            {
                postfix[pf++]=x;
                x=pop();
            }
        } 
        else 
        {
            push(x);
        }
        infix++;
    }
    if(top!=-1) 
    {
        while((x=pop())!='(')
        {
            postfix[pf++]=x;
        }
    }

    return pf;
}

int power(int a, int b) 
{
    if(b==0)
        return 1;
    return (a*power(a,b-1));
}

void display() 
{
    for(int i=0;i<=top;i++)
        printf("%d",stack[i]);
    printf("\n");
}



