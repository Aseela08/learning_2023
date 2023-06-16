#include<stdio.h>
int main()
{
	int rollno;
	char name[50];
	int phy,math,chem;
	float percentage ,total;
	printf("enter name of student:");
	gets(name);
	printf("\nenter roll no:");
	scanf("%d",&rollno);
	printf("\nenter physics mark:");
	scanf("%d",&phy);
	printf("\nenter chemistry mark:");
	scanf("%d",&chem);
	printf("\nenter maths mark:");
	scanf("%d",&math);
	total=phy+chem+math;
	percentage=(total/300)*100;
	puts(name);
	printf("\nroll no:%d",rollno);
	printf("\ntotal is:%.2f",total);
	printf("\npercentage is:%.2f",percentage);
	return 0;
}
