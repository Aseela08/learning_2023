#include <stdio.h>
#include <stdlib.h>

int stringToInteger(char str[]) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // Check for sign
    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    // Process each character of the string
    while (str[i] != '\0') {
        // Convert character to digit
        int digit = str[i] - '0';

        // Check if the character is a valid digit
        if (digit >= 0 && digit <= 9) {
            // Update the result
            result = result * 10 + digit;
        } else {
            // Invalid character encountered
            printf("Invalid input!\n");
            exit(1);
        }

        i++;
    }

    // Apply the sign to the result
    result *= sign;

    return result;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int num = stringToInteger(str);

    printf("Converted integer: %d\n", num);

    return 0;
}
