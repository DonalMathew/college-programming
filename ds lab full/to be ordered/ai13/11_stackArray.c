//afsal ts r3b 313
//stack array
#include <stdio.h>
void main(){
	int a[10];
	int top = -1;
	int temp = top;
	int ch =1 ;
	int con = 1;
	int op = 1;
	while(con){
		
		printf("1.pop\n2.push\n3.display \n");
		scanf("%d",&ch);
		printf("\n");
		switch(ch){
			case 1:
				{
			if(top==-1)
			printf("stack is empty\n");
			else
			{printf("%d deleted",a[top]);
			top--;}
			break;
			}
			case 2:
				{
			if(top == 9)
			printf("stack is full\n");
			else
				while(op)
				{top++;
				printf("Enter data: ");
			 	scanf("%d",&a[top]);
			 	printf("%d inserted\n",a[top]);
			 	printf("do you want to continue ?: ");
			 	scanf("%d",&op);}
			break;
			}
			case 3:
			{
			temp = top;
			if(temp == -1)
			printf("empty\n");
			while(temp>=0){
			printf("[%d]\n",a[temp]);
			temp--;
			}
			break;
			}
		}
		printf("\nDo you want to continue?: ");
		scanf("%d",&con);
	}
}


