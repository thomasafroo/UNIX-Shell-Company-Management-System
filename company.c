#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "company.h"

#define MAX_COMPANIES 50
#define MAX_POSITIONS 80
#define MAX_EMPLOYEES 100
#define MAX_INPUT_SIZE 250

Company companies[MAX_COMPANIES];
int companyCount = 0;

// Company functions--------------------
void createCompany(int id, const char *name, const char *location, const char *industry) {
    if (companyCount >= MAX_COMPANIES) {
        printf("Error: Maximum company limit reached.\n");
        return;
    }

    companies[companyCount].id = id;
    strncpy(companies[companyCount].name, name, sizeof(companies[companyCount].name));
    strncpy(companies[companyCount].location, location, sizeof(companies[companyCount].location));
    strncpy(companies[companyCount].industry, industry, sizeof(companies[companyCount].industry));
    companyCount++;

    printf("Company '%s' added successfully.\n", name);
}

void listCompanies() {
    if (companyCount == 0) {
        printf("No companies available.\n");
        return;
    }

    printf("----------List of Companies:----------\n");
    for (int i = 0; i < companyCount; i++) {
        printf("ID: %d, Name: %s, Location: %s, Industry: %s\n",
               companies[i].id, companies[i].name, companies[i].location, companies[i].industry);
    }
}

void deleteCompany(int id) {
    int found = 0;

    for (int i = 0; i < companyCount; i++) {
        if (companies[i].id == id) { 
            found = 1;
            // Shift remaining companies
            for (int j = i; j < companyCount - 1; j++) {
                companies[j] = companies[j + 1];
            }
            companyCount--;
            printf("Company with ID %d deleted successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Error: Company with ID %d not found.\n", id);
    }
}
