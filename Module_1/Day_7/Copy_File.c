#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void copyFile(FILE* source, FILE* destination, char option) {
    int ch;

    while ((ch = fgetc(source)) != EOF) {
        if (option == 'u')
            ch = toupper(ch);
        else if (option == 'l')
            ch = tolower(ch);
        else if (option == 's') {
            static int firstChar = 1;
            if (firstChar) {
                ch = toupper(ch);
                firstChar = 0;
            } else {
                ch = tolower(ch);
            }
        }

        fputc(ch, destination);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments!\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        printf("Options:\n");
        printf("-u : Change file content to Upper Case\n");
        printf("-l : Change file content to Lower Case\n");
        printf("-s : Change file content to Sentence Case\n");
        printf("No option: Perform normal copy\n");
        return 1;
    }

    char* option = argv[1];
    char* sourceFile = argv[2];
    char* destinationFile = argv[3];

    FILE* source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Error opening source file!\n");
        return 1;
    }

    FILE* destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        printf("Error creating destination file!\n");
        fclose(source);
        return 1;
    }

    if (option[0] == '-' && option[1] != '\0') {
        copyFile(source, destination, option[1]);
    } else {
        copyFile(source, destination, '\0');
    }

    printf("File copied successfully!\n");

    fclose(source);
    fclose(destination);

    return 0;
}
