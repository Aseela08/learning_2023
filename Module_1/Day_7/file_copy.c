#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFileName[100], destinationFileName[100];
    char ch;

    printf("Enter the source file name: ");
    scanf("%s", sourceFileName);

    printf("Enter the destination file name: ");
    scanf("%s", destinationFileName);

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error opening the source file.\n");
        return 1;
    }

    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Error creating the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}

// OUTPUT
// Enter the source file name: source.txt
// Enter the destination file name: destination.txt
// File copied successfully.

