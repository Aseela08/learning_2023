#include <stdio.h>

int bit_operations(int no, int type) {
    int result = no;

    switch (type) {
        case 1: 
            result |= 1;  
            break;
        case 2:  
            result &= ~(1 << 31);  
            break;
        case 3:  
            result ^= (1 << 16);  
            break;
        default:
            printf("Invalid operation type\n");
            return no; 
    }

    return result;
}

int main() {
    int no, type;

    printf("Enter an integer (32 bits): ");
    scanf("%d", &no);

    printf("Enter operation type (1, 2, or 3): ");
    scanf("%d", &type);

    int result = bit_operations(no, type);
    printf("Result: %d\n", result);

    return 0;
}
