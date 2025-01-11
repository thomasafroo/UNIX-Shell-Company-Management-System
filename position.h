#ifndef POSITION_H
#define POSITION_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "company.h"
#include "employee.h"


#define MAX_COMPANIES 50
#define MAX_POSITIONS 80
#define MAX_EMPLOYEES 100
#define MAX_INPUT_SIZE 250

// Abstraction of the structure of a company
typedef struct {
    int id;
    char title[50];
    int companyId; // Link to a company
    float minSalary;
    float maxSalary;
} Position;

extern Position positions[MAX_POSITIONS];
extern int positionCount;

// Position functions--------------------
void addPosition(int id, int companyId, const char *title, float minSalary, float maxSalary);

void listPositions(int companyId);

void deletePosition(int id);

#endif // POSITION.H