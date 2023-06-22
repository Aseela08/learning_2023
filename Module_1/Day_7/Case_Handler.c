#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void convertToUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void convertToLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void convertToSentenceCase(char *str) {
    if (str[0] != '\0') {
        str[0] = toupper(str[0]);
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i - 1] == ' ' || str[i - 1] == '\n') {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

void copyFile(const char *sourceFileName, const char *destinationFileName, char *option) {
    FILE *sourceFile, *destinationFile;
    char line[MAX_LENGTH];

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error opening the source file.\n");
        return;
    }

    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Error creating the destination file.\n");
        fclose(sourceFile);
        return;
    }

    while (fgets(line, sizeof(line), sourceFile)) {
        if (strcmp(option, "-u") == 0) {
            convertToUpperCase(line);
        } else if (strcmp(option, "-l") == 0) {
            convertToLowerCase(line);
        } else if (strcmp(option, "-s") == 0) {
            convertToSentenceCase(line);
        }
        fputs(line, destinationFile);
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);
}

int main(int argc, char *argv[]) {
    if (argc != 3 && argc != 4) {
        printf("Invalid number of arguments.\n");
        printf("Usage: ./case_handler [option] source_file destination_file\n");
        printf("Options:\n");
        printf("-u: Change file content to Upper Case\n");
        printf("-l: Change file content to Lower Case\n");
        printf("-s: Change file content to Sentence Case\n");
        return 1;
    }

    char *option = "";
    char *sourceFileName = argv[argc - 2];
    char *destinationFileName = argv[argc - 1];

    if (argc == 4) {
        option = argv[1];
    }

    copyFile(sourceFileName, destinationFileName, option);

    return 0;
}

// OUTPUT
// ./case_handler -s f1 f2
// File copied successfully.

// ./case_handler -l f1 f3
// File copied successfully.

// ./case_handler -u f1 f4
// File copied successfully.

// ./case_handler f1 f5
// File copied successfully.