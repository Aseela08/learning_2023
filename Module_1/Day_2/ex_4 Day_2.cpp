#include <stdio.h>

int countSetBits(unsigned int num) {
    int count = 0;
    while (num != 0) {
        if (num & 1)
            count++;
        num >>= 1;
    }
    return count;
}

int getTotalSetBits(unsigned int arr[], int size) {
    int totalBits = 0;
    for (int i = 0; i < size; i++) {
        totalBits += countSetBits(arr[i]);
    }
    return totalBits;
}

int main() {
    unsigned int arr[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = getTotalSetBits(arr, size);
    printf("Total number of set bits: %d\n", result);

    return 0;
}