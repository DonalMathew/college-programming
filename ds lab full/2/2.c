/*
Name: Donal Mathew P T
Roll no: 20

question: Write a program to read two polynomials and store them in
an array. Calculate the sum of the two polynomials and
display the first polynomial, second polynomial and the
resultant polynomial.
*/

#include<stdio.h>
struct poly
{
int exp;
int coeff;
}poly1[100],poly2[100],poly3[100];
int main()
{
int i,j,k;
printf("enter num of terms in poly1\n");
int npoly1;
scanf("%d",&npoly1);
printf("\nenter elements starting from lowest power\n");
for(i=0;i<npoly1;i++)
{
printf("enter power\n");
scanf("%d",&poly1[i].exp);
printf("enter coeff\n");
scanf("%d",&poly1[i].coeff);
}


printf("enter num of terms in poly2\n");
int npoly2;
scanf("%d",&npoly2);
printf("enter elements starting from lowest power\n");
for(i=0;i<npoly2;i++)
{
printf("enter power\n");
scanf("%d",&poly2[i].exp);
printf("enter coeff\n");
scanf("%d",&poly2[i].coeff);
}


i=0,j=0,k=0;
while((i<npoly1)&&(j<npoly2))
{

if(poly1[i].exp==poly2[j].exp)
{
	poly3[k].exp=poly1[i].exp;
	poly3[k].coeff=poly1[i].coeff+poly2[j].coeff;
	i++,j++,k++;
}
else if(poly1[i].exp>poly2[j].exp)
{
	poly3[k].exp=poly1[i].exp;
	poly3[k].coeff=poly1[i].coeff;
	i++,k++;
}
else if(poly2[j].exp>poly1[i].exp)
{
	poly3[k].exp=poly2[j].exp;
	poly3[k].coeff=poly2[j].coeff;
	j++,k++;
}
}


if(i>=npoly1)
{
while(j<npoly2)
{
	poly3[k].exp=poly2[j].exp;
	poly3[k].coeff=poly2[j].coeff;
	j++,k++;
}
}

if(j>=npoly2)
{
while(i<npoly1)
{
	poly3[k].exp=poly1[i].exp;
	poly3[k].coeff=poly1[i].coeff;
	i++,k++;
}
}


printf("resultant\n");
for(i=0;i<k;i++)
{

printf(" %dx^%d ",poly3[i].coeff,poly3[i].exp);
if(i!=(k-1))
{
printf("+");
}
}


return 0;
}
