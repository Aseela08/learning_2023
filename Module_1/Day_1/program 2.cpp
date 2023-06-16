#include<stdio.h>
int main()
{
	int mark;
	scanf("%d",&mark);
	if(mark>=90 && mark<=100)
	printf("The Grade is A");
	else if (mark>=75 && mark<=89) 
	printf("The Grade is B");
	else if(mark>=60 && mark<=74)
	printf("The Grade is C");
	else if(mark>=50 && mark<=59)
	printf("The Grade is D");
	else if (mark>=0 && mark<=49)
	printf("The Grade is F");
	else 
	printf("invalid mark");
	return 0;
}