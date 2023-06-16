#include <stdio.h>
#include<cstring>

void swap(void* a, void* b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int main() {
    int x ,y;
    printf("Before swap x,y of int: ");
    scanf("%d %d",&x,&y);

    swap(&x, &y, sizeof(int));
    printf("After swap: x = %d, y = %d\n", x, y);

    double a ,b;
    printf("Before swap a,b for double: ");
	scanf("%lf %lf",&a,&b);
    swap(&a, &b, sizeof(double));
    printf("After swap: a = %.2lf, b = %.2lf\n", a, b);
    return 0;
}
