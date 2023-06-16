#include <stdio.h>

void exponent(double x) {
    // Obtain the binary representation of the double variable
    unsigned long long bits = *(unsigned long long*)&x;
    
    // Extract the exponent part from the binary representation
    unsigned int exponent_bits = (bits >> 52) & 0x7FF;

    // Convert the exponent part to hexadecimal and binary format
    printf("Exponent in hexadecimal: 0x%X\n", exponent_bits);
    printf("Exponent in binary: 0b");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (exponent_bits >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x;
    scanf("%lf",&x);
    exponent(x);
    return 0;
}
