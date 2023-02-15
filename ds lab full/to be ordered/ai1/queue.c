/* Queue Operatins
author:Aasiya yasir
rollno:301*/
*/
#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;
void Display ()
{
    if(front == NULL)
    {
        printf("\nqueue is empty\n");
        return ;
    }
    printf("\nelements of queue are:\n");
    for(struct node* i=front; i!=NULL;i=i->next)
    {
        printf("%d\t",i->data);
    }
}

struct node* enqueue()
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data :");
    scanf("%d",&new->data);
    if(rear == NULL)                    //insertion to an empty queue
    {
        front = new;
        rear = new;
        return 0 ;
    }
    rear->next = new;
    rear = new;
    return 0;
    //return rear;
}

struct node* dequeue()
{
    if(front == NULL)                             // empty queue
        printf("\nQueue is empty\n");
    else
    {
        struct node* ptr = front;
        if(front->next == NULL)                   //single element in queue
        {
            front = NULL;
            rear = NULL;
            free(ptr);
        }
        else
        {
            front = front->next;
            free(ptr);
        }
        Display();
    }
    return 0;
    //return front;
}



int main()
{
    int flag = 0,choice;
   

    while(flag==0)
    {
        
        printf("\nEnter your choice:\n\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t4.Exit\nChoice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                enqueue();
                //rear=enqueue();
                break;
            }
            case 2:
            {
                dequeue();
                //front=dequeue();
                break;
            }
            case 3:
            {
                Display();
                break;
            }
            case 4:
            {
                flag=1;
                break;
            }
            default:
            {
                printf("\nChoice is invalid\n");
                break;
            }
        }
    }
    return 0;
}
