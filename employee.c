#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

#define MAX_COMPANIES 50
#define MAX_POSITIONS 80
#define MAX_EMPLOYEES 100
#define MAX_INPUT_SIZE 250

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

// Employee functions--------------------
void addEmployee(int id, const char *name, int positionId, float salary) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Error: Maximum employee limit reached.\n");
        return;
    }

    employees[employeeCount].id = id;
    strncpy(employees[employeeCount].name, name, sizeof(employees[employeeCount].name));
    employees[employeeCount].positionId = positionId;
    employees[employeeCount].salary = salary;
    employeeCount++;

    printf("Employee '%s' added successfully.\n", name);
}

void listEmployees(int positionId) {
    int found = 0;

    printf("----------List of Employees:----------\n");
    for (int i = 0; i < employeeCount; i++) {
        if (positionId == -1 || employees[i].positionId == positionId) {
            printf("ID: %d, Name: %s, Position ID: %d, Salary: %.2f\n",
                   employees[i].id, employees[i].name,
                   employees[i].positionId, employees[i].salary);
            found = 1;
        }
    }

    if (!found) {
        printf("No employees found.\n");
    }
}

void updateEmployeeSalary(int id, float newSalary) {
    int found = 0;

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            employees[i].salary = newSalary;
            printf("Updated salary for Employee ID %d to %.2f.\n", id, newSalary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Employee with ID %d not found.\n", id);
    }
}

void deleteEmployee(int id) {
    int found = 0;

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            found = 1;
            // Shift remaining employees
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee with ID %d deleted successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Error: Employee with ID %d not found.\n", id);
    }
}
