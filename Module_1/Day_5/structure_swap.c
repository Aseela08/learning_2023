#include <stdio.h>

// Structure to represent a student
struct Student {
    int rollNumber;
    float marks;
};

// Function to swap the fields of two structures using pointers
void swapStructures(struct Student *s1, struct Student *s2) {
    // Swap the roll numbers
    int tempRollNumber = s1->rollNumber;
    s1->rollNumber = s2->rollNumber;
    s2->rollNumber = tempRollNumber;

    // Swap the marks
    float tempMarks = s1->marks;
    s1->marks = s2->marks;
    s2->marks = tempMarks;
}

int main() {
    struct Student student1, student2;

    printf("Enter details for student 1:\n");
    printf("Roll Number: ");
    scanf("%d", &(student1.rollNumber));
    printf("Marks: ");
    scanf("%f", &(student1.marks));

    printf("\nEnter details for student 2:\n");
    printf("Roll Number: ");
    scanf("%d", &(student2.rollNumber));
    printf("Marks: ");
    scanf("%f", &(student2.marks));

    printf("\nBefore swapping:\n");
    printf("Student 1: Roll Number = %d, Marks = %.2f\n", student1.rollNumber, student1.marks);
    printf("Student 2: Roll Number = %d, Marks = %.2f\n", student2.rollNumber, student2.marks);

    // Swap the fields of the structures
    swapStructures(&student1, &student2);

    printf("\nAfter swapping:\n");
    printf("Student 1: Roll Number = %d, Marks = %.2f\n", student1.rollNumber, student1.marks);
    printf("Student 2: Roll Number = %d, Marks = %.2f\n", student2.rollNumber, student2.marks);

    return 0;
}
