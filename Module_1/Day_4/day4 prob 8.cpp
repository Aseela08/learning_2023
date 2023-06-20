#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateSeconds(char timeStr[]) {
    char *token;
    int hours, minutes, seconds;
    
    token = strtok(timeStr, ":");
    hours = strtoul(token, NULL, 10);

    token = strtok(NULL, ":");
    minutes = strtoul(token, NULL, 10);

    token = strtok(NULL, ":");
    seconds = strtoul(token, NULL, 10);

    int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;

    return totalSeconds;
}

int main() {
    char timeStr[100];

    printf("Enter time in HH:MM:SS format: ");
    fgets(timeStr, sizeof(timeStr), stdin);

    // Remove newline character from fgets
    timeStr[strcspn(timeStr, "\n")] = '\0';

    int totalSeconds = calculateSeconds(timeStr);

    printf("Total seconds: %d\n", totalSeconds);

    return 0;
}
