#ifndef COMPANY_H
#define COMPANY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_COMPANIES 50
#define MAX_POSITIONS 80
#define MAX_EMPLOYEES 100
#define MAX_INPUT_SIZE 250

// Abstraction of the structure of a company
typedef struct Company {
    int id;
    char name[50];
    char location[50];
    char industry[50];
} Company;

// Grouping the parts together
extern Company companies[MAX_COMPANIES];
extern int companyCount;

// Company functions--------------------
void createCompany(int id, const char *name, const char *location, const char *industry);

void listCompanies();

void deleteCompany(int id);

#endif // COMPANY_H