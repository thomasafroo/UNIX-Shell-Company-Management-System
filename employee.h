#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "company.h"
#include "position.h"

#define MAX_COMPANIES 50
#define MAX_POSITIONS 80
#define MAX_EMPLOYEES 100
#define MAX_INPUT_SIZE 250

// Abstraction of the structure of a company
typedef struct {
    int id;
    char name[50];
    int positionId; // Links to a specific position
    float salary;
} Employee;

extern Employee employees[MAX_EMPLOYEES];
extern int employeeCount;

void addEmployee(int id, const char *name, int positionId, float salary);

void listEmployees(int positionId);

void updateEmployeeSalary(int id, float newSalary);

void deleteEmployee(int id);

#endif // EMPLOYEE_H