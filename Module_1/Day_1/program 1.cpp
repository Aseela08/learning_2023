 #include<stdio.h>
 int conditional(int a , int b)
 {
    if(a>b)
 	printf("%d\n",a);
	else 
	printf("%d\n",b);
 	return 0;
 }
 int ternary(int a,int b)
 {
 	printf("%d",(a>b)?a:b);
 	return 0;
 }
 int main()
 {
 	int a,b;
 	scanf("%d %d",&a,&b);
 	conditional(a,b);
 	ternary(a,b);
 	return 0;
}