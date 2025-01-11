#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "position.h"

#define MAX_COMPANIES 50
#define MAX_POSITIONS 80
#define MAX_EMPLOYEES 100
#define MAX_INPUT_SIZE 250

Position positions[MAX_POSITIONS];
int positionCount = 0;

// Position functions--------------------
void addPosition(int id, int companyId, const char *title, float minSalary, float maxSalary) {
    if (positionCount >= MAX_POSITIONS) {
        printf("Error: Maximum position limit reached.\n");
        return;
    }

    positions[positionCount].id = id;
    positions[positionCount].companyId = companyId;
    strncpy(positions[positionCount].title, title, sizeof(positions[positionCount].title));
    positions[positionCount].minSalary = minSalary;
    positions[positionCount].maxSalary = maxSalary;
    positionCount++;

    printf("Position '%s' added successfully.\n", title);
}

void listPositions(int companyId) {
    int found = 0;

    printf("----------List of Positions at company %d:----------\n", companyId);
    for (int i = 0; i < positionCount; i++) {
        if (companyId == -1 || positions[i].companyId == companyId) {
            printf("ID: %d, Company ID: %d, Title: %s, Min Salary: %.2f, Max Salary: %.2f\n",
                   positions[i].id, positions[i].companyId, positions[i].title,
                   positions[i].minSalary, positions[i].maxSalary);
            found = 1;
        }
    }

    if (!found) {
        printf("No positions found.\n");
    }
}

void deletePosition(int id) {
    int found = 0;

    for (int i = 0; i < positionCount; i++) {
        if (positions[i].id == id) {
            found = 1;
            // Shift remaining positions
            for (int j = i; j < positionCount - 1; j++) {
                positions[j] = positions[j + 1];
            }
            positionCount--;
            printf("Position with ID %d deleted successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Error: Position with ID %d not found.\n", id);
    }
}
