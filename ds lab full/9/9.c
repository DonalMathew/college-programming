/*
Name: Donal Mathew P T
Roll no: 20

question: 

Create a Doubly Linked List from a string taking each
character from the string. Check if the given string is
palindrome in an efficient method

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char c;
    struct node *Rlink,*Llink;
};
struct node* insert(struct node* head,char c)
{
    struct node* ptr = NULL;
    struct node* new = malloc(sizeof(struct node));
    new->c = c;
    new->Llink = NULL;
    new->Rlink = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        ptr = head;
        while(ptr->Rlink != NULL)
            ptr = ptr->Rlink;

        ptr->Rlink = new;
        new->Llink = ptr;    
    }
    return(head);
}
int check(struct node* head)
{
    struct node* start = head;
    struct node* end = head;
    int flag = 0;
    while(end->Rlink != NULL)
        end = end->Rlink;
    while (start != end)
    {
        if (start->c == end->c)
        {
            flag = 1;
            start = start->Rlink;
            end = end->Llink;
        }
        else
        {
            return(0);
        }
    }
    return(flag);
}
int main()
{
    struct node* head = NULL;
    char str[20],c;
    int l,i;
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    l = strlen(str);
    for (i = 0; i < l ; i++)
    {
        c = str[i];
        head = insert (head,c);
    }
    l = check(head);
    if (l == 1)
        printf("Its a Pallindrome");
    else
        printf("Not a Pallindrome"); 
    return(0);
}
