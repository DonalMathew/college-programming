/*
Name: Donal Mathew P T
Roll no: 20

question: 

Implement a Queue using arrays with the operations:
1.Insert elements to the Queue.
2.Delete elements from the Queue.
3.Display the contents of the Queue after each operation.

*/

#include<stdio.h>
#include<stdlib.h>
int front = -1;
int rear = -1;
int Q[100];
void enqueue(int size)
{
    if(rear == size-1)
    printf("Queue full\n");
    else
    {
        printf("Enter value to be added :");
        int value;
        scanf("%d",&value);
        if(front == -1)
        {
        front = 0;
        }
        rear = rear+1;
        Q[rear] = value;
    }
}
void dequeue()
{
    if(front == -1 || front>rear)
    printf("Queue empty\n");
    else
    {
        printf("Deleted element is :%d",Q[front]);
        front = front+1;
        printf("\n");
    }
}
void display()
{
    if(front == -1 || front>rear)
    printf("Queue empty\n");
    else
    {
        printf("Elements in queue are :");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",Q[i]);
        }
        printf("\n");
    }
}
int main()
{
    int size;
    printf("Enter size of queue :");
    scanf("%d",&size);
    printf("MENU\n");
    printf("1.Add elements to queue\n2.Delete elements from queue\n3.Display elements\n4.Quit\n");
    int c;
    while(1)
    {
        printf("Enter choice :");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            enqueue(size);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
        }
    }
}
