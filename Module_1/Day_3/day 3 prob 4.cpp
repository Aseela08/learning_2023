#include <stdio.h>

int deleteDigit(int num, int digitPos) {
    int divisor = 1;
    
    // Find the divisor for the digit to be deleted
    for (int i = 0; i < digitPos; i++) {
        divisor *= 10;
    }
    
    int leftPart = num / (divisor * 10);  // Extract the left part of the number
    int rightPart = num % divisor;        // Extract the right part of the number
    
    return (leftPart * divisor) + rightPart;  // Combine the left and right parts
}

int findLargestNumber(int num) {
    int largestNum = 0;
    
    // Iterate through each digit position
    for (int i = 0; i < 4; i++) {
        int currentNum = deleteDigit(num, i);
        
        if (currentNum > largestNum) {
            largestNum = currentNum;
        }
    }
    
    return largestNum;
}

int main() {
    int num;
    
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    
    int largestNumber = findLargestNumber(num);
    
    printf("Largest number after deleting a digit: %d\n", largestNumber);
    
    return 0;
}
