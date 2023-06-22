#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

int main() {
    struct Box myBox;
    struct Box *ptrBox = &myBox;

    // Accessing members using the arrow operator
    ptrBox->length = 5.0;
    ptrBox->width = 3.0;
    ptrBox->height = 4.0;

    // Calculating volume and surface area
    double volume = ptrBox->length * ptrBox->width * ptrBox->height;
    double surfaceArea = 2 * (ptrBox->length * ptrBox->width + ptrBox->length * ptrBox->height + ptrBox->width * ptrBox->height);

    // Displaying the enchanting results
    printf("Volume of the box: %.2f\n", volume);
    printf("Surface area of the box: %.2f\n", surfaceArea);

    return 0;
}

//Output:
//
//Volume of the box: 60.00
//Surface area of the box: 94.00
