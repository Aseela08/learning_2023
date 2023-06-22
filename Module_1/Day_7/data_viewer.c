#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    char sensorNo[3];
    float temperature;
    int humidity;
    int light;
    char time[9];
};

void extractLogEntries(FILE* file, struct LogEntry logEntries[], int* count) {
    char line[100];

    // Skip the header line
    fgets(line, sizeof(line), file);

    *count = 0;
    while (fgets(line, sizeof(line), file)) {
        struct LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]", &entry.entryNo, entry.sensorNo, &entry.temperature, &entry.humidity, &entry.light, entry.time);
        logEntries[*count] = entry;
        (*count)++;
    }
}

void displayLogEntries(struct LogEntry logEntries[], int count) {
    printf("EntryNo  SensorNo  Temperature  Humidity  Light  Time\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-8d %-9s %-12.1f %-9d %-6d %s\n", logEntries[i].entryNo, logEntries[i].sensorNo, logEntries[i].temperature, logEntries[i].humidity, logEntries[i].light, logEntries[i].time);
    }
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int count = 0;

    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening data.csv file!\n");
        return 1;
    }

    extractLogEntries(file, logEntries, &count);
    fclose(file);

    displayLogEntries(logEntries, count);

    return 0;
}

// OUTPUT

// EntryNo  SensorNo  Temperature  Humidity  Light  Time
// --------------------------------------------------
// 1        S1        36.5         100       50     10:30:50
// 2        S3        30.0         100       50     10:30:55
// 3        S2        -6.6         100       10     10:31:00

