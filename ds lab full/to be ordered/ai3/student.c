/*Student directory
author:Abhilash.S
rollno:303*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    int rllno;
    char name[100];
    float tm;
    struct Student *next;
    
}* head;


void insert(int rollnumber, char* name, float mark)
{
    
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rllno = rollnumber;
    strcpy(student->name, name);
    student->tm = mark;
    student->next = NULL;
    
    if(head==NULL){
        head = student;
    }
    else{
        student->next = head;
        head = student;
    }
    
}
void search(int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->rllno==rollnumber){
            printf("Roll Number: %d\n", temp->rllno);
            printf("Name: %s\n", temp->name);
            printf("Total Marks: %0.2f\n", temp->tm);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}

void Delete(int rollnumber)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head; 
    while(temp1!=NULL){
        
        if(temp1->rllno==rollnumber){
            
            printf("Record Found\n");
            
            if(temp1==temp2){
                
                head = head->next;
                free(temp1);
            }
            else{
                temp2->next = temp1->next;
                free(temp1); 
            }
            
            printf("Record Deleted \n");
            return;
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
        
    }
    printf("Roll number %d not found\n", rollnumber);
    
}
void display()
{
    struct Student * temp = head;
    while(temp!=NULL){
        
        printf("Roll Number: %d\n", temp->rllno);
        printf("Name: %s\n", temp->name);
        printf("Total Marks: %0.2f\n\n", temp->tm);
        temp = temp->next;
        
    }
}

void sort()
{
	struct Student * curr = head, *index=NULL;
	int tRn;
	char tCh[100];
	float tMark;
	if(head == NULL){
		printf("Empty list");	
		return;
	}
	else{
		while(curr!=NULL){
			index= curr->next;
			while(index!=NULL)
			{
				if(curr->rllno>index->rllno){
					tRn = curr->rllno;
					strcpy(tCh,curr->name);
					tMark= curr->tm;
					
					curr->rllno = index->rllno;
					strcpy(curr->name,index->name);
					curr->tm=index->tm;
					
					index->rllno= tRn;
					strcpy(index->name,tCh);
					index->tm=tMark;
				}
				index=index->next;
			}
			curr=curr->next;
		}
	}	
}

int main(){
    head = NULL;
    int choice;
    char name[100];
    int rollnumber;
    float percentage;
    
    do
    {
    	printf("1:Insert student details\n2:Search for student details\n3:Delete student details\n4:Sort List\n5:Display all student details\n0:exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter Total marks: ");
                scanf("%f", &percentage);
                insert(rollnumber, name, percentage);
                break;
            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                break;
            case 3:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollnumber);
                Delete(rollnumber);
                display();
                break;
            case 4:
            	sort();
            	display();
            	printf("Sorted\n");
            	break;
            case 5:
                display();
                break;
        }
        
    } while (choice != 0);
}
