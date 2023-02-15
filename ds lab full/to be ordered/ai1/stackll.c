/*Stack using linked list
author:Aasiya Yasir
roll no:301*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* top = NULL;

struct node* Push(){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element to be pushed into the stack:\n");
    scanf("%d",&new->data);
    new->next = top;
    top = new;
    return top;
}

struct node* Pop()
{
    if(top == NULL)
    {
        printf("\nStack underflow\n");
        return top; 
    }
    else
    {
        struct node* temp = top;
        printf("\nElement being popped is %d\n",temp->data);
        top = top->next;
        free(temp);
    }
    return top;
}

void Display()
{   
    if(top==NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nStack elements:\n");
        for(struct node* i = top; i != NULL; i=i->next)
        {
            printf("%d\t",i->data);
        }
    }
    
}

int main()
{   
    int flag = 0,choice;
    while(flag==0){
        printf("\nEnter your choice:\n\t1.Push\n\t2.Pop\n\t3.Display\n\t4.Exit\nChoice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                top=Push(top);
                break;
            }
            case 2:
            {
                top=Pop(top);
                break;
            }
            case 3:
            {
                Display(top);
                break;
            }
            case 4:
            {
                flag=1;
                break;
            }
            default:
            {
                printf("\nInvalid choice\n");
                break;
            }
        }
    }
    return 0;
}
