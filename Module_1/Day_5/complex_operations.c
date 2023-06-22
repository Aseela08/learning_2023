#include <stdio.h>

// Structure to represent a complex number
struct Complex {
    float real;
    float imaginary;
};

// Function to read a complex number
void readComplex(struct Complex *num) {
    printf("Enter the real part: ");
    scanf("%f", &(num->real));
    printf("Enter the imaginary part: ");
    scanf("%f", &(num->imaginary));
}

// Function to write a complex number
void writeComplex(struct Complex num) {
    printf("The complex number is: %.2f + %.2fi\n", num.real, num.imaginary);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex sum;
    sum.real = num1.real + num2.real;
    sum.imaginary = num1.imaginary + num2.imaginary;
    return sum;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex num1, struct Complex num2) {
    struct Complex product;
    product.real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
    product.imaginary = (num1.real * num2.imaginary) + (num1.imaginary * num2.real);
    return product;
}

int main() {
    struct Complex complex1, complex2, result;

    printf("Reading the first complex number:\n");
    readComplex(&complex1);

    printf("\nReading the second complex number:\n");
    readComplex(&complex2);

    printf("\nThe first complex number is: ");
    writeComplex(complex1);

    printf("The second complex number is: ");
    writeComplex(complex2);

    result = addComplex(complex1, complex2);
    printf("\nAddition of the complex numbers: ");
    writeComplex(result);

    result = multiplyComplex(complex1, complex2);
    printf("Multiplication of the complex numbers: ");
    writeComplex(result);

    return 0;
}

//Output:
//
//Reading the first complex number:
//Enter the real part: Enter the imaginary part:
//Reading the second complex number:
//Enter the real part: Enter the imaginary part:
//The first complex number is: The complex number is: 5.00 + 10.00i
//The second complex number is: The complex number is: 5.00 + 10.00i
//
//Addition of the complex numbers: The complex number is: 10.00 + 20.00i
//Multiplication of the complex numbers: The complex number is: -75.00 + 100.00i
