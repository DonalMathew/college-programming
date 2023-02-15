//ADITHYA PRAKASH-309
//STRING REVERSAL
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Stack {
	int top;
	unsigned capacity;
	char* array;
};



struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack= (struct Stack*)malloc(sizeof(struct Stack));
stack->capacity = capacity;
stack->top = -1;
stack->array= (char*)malloc(stack->capacity * sizeof(char));
return stack;
}

int isFull(struct Stack* stack)
{
return stack->top == stack->capacity - 1;
}


int isEmpty(struct Stack* stack)
{
return stack->top == -1;
}



void push(struct Stack* stack, char item)
{
if (isFull(stack))
return;
stack->array[++stack->top] = item;
}



char pop(struct Stack* stack)
{
 if (isEmpty(stack))
 return 0;
 return stack->array[stack->top--];
}


void reverse(char str[])
{


int n = strlen(str);
struct Stack* stack = createStack(n);


int i;
for (i = 0; i < n; i++)
push(stack, str[i]);



for (i = 0; i < n; i++)
str[i] = pop(stack);
}


int main()
{
int i;
char w[20];
printf("Enter a word: ");
scanf("%s",&w);

reverse(w);
printf("\nReversed word: %s", w);

return 0;
}
