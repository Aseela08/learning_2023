
#include <stdio.h>
int main()
{
	char ch;
	int a, b;
	
	printf("enter number 1:");
	scanf("%d",&a);
	printf("enter operation: ");
	scanf(" %c" ,&ch);
	printf("enter number 2:");
	scanf("%d",&b);
	switch (ch) {

		case '+':
			printf("%d + %d = %d\n", a, b, a + b);
			break;
		case '-':
			printf("%d - %d = %d\n", a, b, a - b);
			break;

		case '*':
			printf("%d * %d = %d\n", a, b, a * b);
			break;

			printf("%d / %d = %d\n", a, b, a / b);
			break;

		default:
			printf("invalid operator\n");
		}

		return 0;

	}
