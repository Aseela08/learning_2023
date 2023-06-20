#include <stdio.h>

void printBits(unsigned int num) {
    int i;
    int size = sizeof(num) * 8; // Number of bits in an unsigned int
    
    for (i = size - 1; i >= 0; i--) {
        unsigned int mask = 1u << i; // Create a mask with only the i-th bit set
        
        if (num & mask) {
            printf("1");
        } else {
            printf("0");
        }
    }
    
    printf("\n");
}

int main() {
    unsigned int num;
    
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);
    
    printf("Bits: ");
    printBits(num);
    
    return 0;
}
