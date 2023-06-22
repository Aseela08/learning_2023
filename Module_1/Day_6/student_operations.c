#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to parse the input string and initialize an array of structures
void parseString(char* inputString, struct Student* students, int size) {
    char* token = strtok(inputString, " ");
    int i = 0;

    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Invalid input string!\n");
            return;
        }

        strcpy(students[i].name, token);

        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Invalid input string!\n");
            return;
        }

        students[i].marks = atof(token);

        token = strtok(NULL, " ");
        i++;
    }
}

// Function to initialize all members in an array of structures
void initializeStructArray(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

// Function to display all members in an array of structures
void displayStructArray(struct Student* students, int size) {
    printf("\nArray of Structures:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
}

// Function to sort the array of structures in descending order based on marks
void sortStructArray(struct Student* students, int size) {
    struct Student temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (students[j].marks < students[j + 1].marks) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to perform a search operation on the array of structures based on the name of the student
void searchStructArray(struct Student* students, int size, char* searchName) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Student found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with name '%s' not found!\n", searchName);
    }
}

int main() {
    int size;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array of structures
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    char inputString[100];
    getchar();  // Clear input buffer
    printf("Enter the input string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove trailing newline character
    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }

    // Parse the input string and initialize the array of structures
    parseString(inputString, students, size);

    // Display the initialized array of structures
    displayStructArray(students, size);

    // Sort the array of structures in descending order based on marks
    sortStructArray(students, size);

    // Display the sorted array of structures
    printf("Array of Structures (Sorted in Descending Order):\n");
    displayStructArray(students, size);

    // Perform a search operation on the array of structures based on the name of the student
    char searchName[20];
    printf("Enter the name of the student to search: ");
    scanf("%s", searchName);

    searchStructArray(students, size, searchName);

    // Free the dynamically allocated memory
    free(students);

    return 0;
}

// STDIN
// 3
// 45 helo 90 35 ron 56 56 brun 34
// helo

// Output:

// Enter the number of students: Enter the input string: 
// Array of Structures:
// Student 1:
// Roll No: 45
// Name: helo
// Marks: 90.00

// Student 2:
// Roll No: 35
// Name: ron
// Marks: 56.00

// Student 3:
// Roll No: 56
// Name: brun
// Marks: 34.00

// Array of Structures (Sorted in Descending Order):

// Array of Structures:
// Student 1:
// Roll No: 45
// Name: helo
// Marks: 90.00

// Student 2:
// Roll No: 35
// Name: ron
// Marks: 56.00

// Student 3:
// Roll No: 56
// Name: brun
// Marks: 34.00

// Enter the name of the student to search: Student found:
// Roll No: 45
// Name: helo
// Marks: 90.00
