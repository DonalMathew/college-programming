//ADITHYA PRAKASH
//ROLL NO.: 309
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;  
} Node;

struct Node* top = NULL;

void push(int val)
{
    Node *new;
    new = (Node*)malloc(sizeof(Node));
    new->data = val;
    if (top == NULL) 
    {
        new->next = NULL;
    }
    else
    {
        new->next = top;
    }
    top = new;
    printf("Node Inserted");
}

int pop()
{
    if (top == NULL) 
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *temp = top;
        int val = top->data;
        top = top->next;
        free(temp);
        return val;
    }
}

void display()
{
    if (top == NULL) 
    {
        printf("Empty Stack\n");
    }
    else
    {
        printf("The Stack is \n");
        struct Node *temp = top;
        while (temp->next != NULL)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

int main()
{
    int op, value,x=1;
    while (x)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter Operation: ");
        scanf("%d", &op);
        printf("\n");
        switch (op)
        {
            case 1:
            {
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                push(value);
                printf("\n\n");
                break;
            }
            
            case 2:
            {
                if (top != NULL)
                {
                    printf("Popped element is: %d\n", pop());
                }
                else
                {
                    pop();
                }
                printf("\n");
                break;
            }
            
            case 3:
            {
                display();
                printf("\n");
                break;
            }
            
            case 4:
            {
                x=0;
                break;
            }
            default:
            {
                printf("Invalid Input\n");
                printf("\n");
            }
        }
    }
    printf("Program Terminated");
}
