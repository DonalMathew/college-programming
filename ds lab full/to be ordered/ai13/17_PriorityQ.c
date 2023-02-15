//afsal ts r3b 313
//prio queue
#include<stdio.h>
#include<limits.h>
#define MAX 100
int idx = -1;
int pqVal[MAX];
int pqPriority[MAX];
int isEmpty(){
    return idx == -1;
}
int isFull(){
    return idx == MAX - 1;
}
void enqueue(int data, int priority)
{
    if(!isFull()){
        
        idx++;
 
        pqVal[idx] = data;
        pqPriority[idx] = priority;
    }
}
int peek()
{
    int maxPriority = INT_MIN;
    int indexPos = -1;
 
    for (int i = 0; i <= idx; i++) { 
        if (maxPriority == pqPriority[i] && indexPos > -1 && pqVal[indexPos] < pqVal[i]) 
        {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
        
        else if (maxPriority < pqPriority[i]) {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
    }
    
    return indexPos;
}
void dequeue()
{
    if(!isEmpty())
    {
        int indexPos = peek();
        for (int i = indexPos; i < idx; i++) {
            pqVal[i] = pqVal[i + 1];
            pqPriority[i] = pqPriority[i + 1];
        }
 
        idx--;
    }
}
void display(){
    for (int i = 0; i <= idx; i++) {
        printf("(%d, %d)\n",pqVal[i], pqPriority[i]);
    } 
}
int main()
{
    printf("Priority Queue Using Arrays\n");
    int el,prio;
    int flag=0,co;
    int k=0,op;
    while(k!=1)
    {
    printf("Choose an Operation:\n 1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    scanf("%d",&op);
    switch(op)
    {
   	case 1:
   		while (flag!=1)
  			{
   			printf("Enter element and Priority: ");
   				scanf("%d %d",&el,&prio);
    				enqueue(el,prio);
    				printf("Do you want to continue:(press yes-0||no-1 ");
    				scanf("%d",&co);
    				if(co==0)
    				{
    					flag=0;
    				}
    				else
    				{
    					flag=1;
    				}
    			}	
    			break;
    		case 2:
    			printf("Priority Queue Before Dequeue : \n");
 			display();
			dequeue();
			printf("\nPriority Queue After Dequeue : \n");
    			display();
    			break;
   		case 3:
   			display();
   			break;
   		case 4:
   			k=1;
   			break;
   	}
   }
}
