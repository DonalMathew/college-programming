//ADITHYA PRAKASH
#include<stdio.h>
void enqueue(int* front, int* rear, int size, int* arr)
{
    int element,  begin, end;
    
    if(*rear==size-1)
    {
        printf("\nQueue is full.\n");
    }
    else
    {
        printf("Enter the element to be inserted: ");
        scanf("%d",&element);
        if(*rear==-1 && *front==-1)
        {
            *front=*front+1;
        }
        *rear=*rear+1;
        *(arr+*rear)=element;
    }
}
void dequeue(int* front, int* rear, int size, int* arr)
{
    if((*front==-1 && *rear==-1) || *front>*rear)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        *front=*front+1;
    }
}
void view(int* front, int* rear, int size, int* arr)
{
    int begin, end;
    begin=*front;
    end=*rear;
    if((*front==-1 && *rear==-1) || *front>*rear)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        while (begin<=end)
        {            
            printf("%d\t",*(arr+begin));            
            begin++;
        }
        printf("\n");
    }
}
int main()
{
    
    int n, option, front=-1, rear=-1, flag=0;
    printf("Enter the size of the queue: ");
    scanf("%d",&n);
    int arr[n];
    while(flag==0)
    {
        
        printf("\nChoose an option to perform:\n1)Enqueue\n2)Dequeue\n3)Display\n4)Exit\n\nChoice: ");
        scanf("%d",&option);
        printf("\n----------------------------------------------\n");
        
        switch (option)
        {
        case 1:
            enqueue(&front, &rear, n, arr);
            break;
        case 2:
            dequeue(&front, &rear, n, arr);
            break;
        case 3:
            view(&front, &rear, n, arr);
            break;
        case 4:
            flag=1;
            break;
        }
    }
}



