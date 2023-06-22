#include <stdio.h>

// Structure to represent time
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
void calculateTimeDifference(struct Time start, struct Time end, struct Time *difference) {
    int startTimeInSeconds, endTimeInSeconds, differenceInSeconds;

    // Convert start time to seconds
    startTimeInSeconds = start.hours * 3600 + start.minutes * 60 + start.seconds;

    // Convert end time to seconds
    endTimeInSeconds = end.hours * 3600 + end.minutes * 60 + end.seconds;

    // Calculate difference in seconds
    differenceInSeconds = endTimeInSeconds - startTimeInSeconds;

    // Convert difference back to hours, minutes, and seconds
    difference->hours = differenceInSeconds / 3600;
    differenceInSeconds %= 3600;
    difference->minutes = differenceInSeconds / 60;
    differenceInSeconds %= 60;
    difference->seconds = differenceInSeconds;
}

int main() {
    struct Time startTime, endTime, difference;

    printf("Enter the start time (hh:mm:ss): ");
    scanf("%d:%d:%d", &(startTime.hours), &(startTime.minutes), &(startTime.seconds));

    printf("Enter the end time (hh:mm:ss): ");
    scanf("%d:%d:%d", &(endTime.hours), &(endTime.minutes), &(endTime.seconds));

    calculateTimeDifference(startTime, endTime, &difference);

    printf("\nDifference between the two time periods: %d hours, %d minutes, %d seconds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}

// Output:

// Enter the start time (hh:mm:ss): Enter the end time (hh:mm:ss): 21:05:23 23:00:00
// Difference between the two time periods: 1 hours, 54 minutes, 37 seconds
