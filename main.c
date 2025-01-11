// Unix shell for the managment system of a company
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "company.h"
#include "employee.h"
#include "position.h"

#define MAX_COMPANIES 50
#define MAX_POSITIONS 80
#define MAX_EMPLOYEES 100
#define MAX_INPUT_SIZE 250

void parseCommand(char *input) {
    // Remove newline from input
    input[strcspn(input, "\n")] = '\0';

    // Tokenize input
    char *command = strtok(input, " ");
    if (command == NULL) {
        printf("No command entered.\n");
        return;
    }

    // Handle commands
    if (strcmp(command, "add-company") == 0) {
        int id;
        char name[50], location[50], industry[30];
        printf("Enter ID, Name, Location, and Industry: ");
        scanf("%d %49s %49s %29s", &id, name, location, industry);
        createCompany(id, name, location, industry);
    } else if (strcmp(command, "list-companies") == 0) {
        listCompanies();
    } else if (strcmp(command, "delete-company") == 0) {
        int id;
        printf("Enter Company ID to delete: ");
        scanf("%d", &id);
        deleteCompany(id);
    } else if (strcmp(command, "add-position") == 0) {
        int id, companyId;
        char title[50];
        float minSalary, maxSalary;
        printf("Enter ID, Company ID, Title, Min Salary, and Max Salary: ");
        scanf("%d %d %49s %f %f", &id, &companyId, title, &minSalary, &maxSalary);
        addPosition(id, companyId, title, minSalary, maxSalary);
    } else if (strcmp(command, "list-positions") == 0) {
        int companyId;
        printf("Enter Company ID (-1 for all): ");
        scanf("%d", &companyId);
        listPositions(companyId);
    } else if (strcmp(command, "delete-position") == 0) {
        int id;
        printf("Enter Position ID to delete: ");
        scanf("%d", &id);
        deletePosition(id);
    } else if (strcmp(command, "add-employee") == 0) {
        int id, positionId;
        char name[50];
        float salary;
        printf("Enter ID, Name, Position ID, and Salary: ");
        scanf("%d %49s %d %f", &id, name, &positionId, &salary);
        addEmployee(id, name, positionId, salary);
    } else if (strcmp(command, "list-employees") == 0) {
        int positionId;
        printf("Enter Position ID (-1 for all): ");
        scanf("%d", &positionId);
        listEmployees(positionId);
    } else if (strcmp(command, "delete-employee") == 0) {
        int id;
        printf("Enter Employee ID to delete: ");
        scanf("%d", &id);
        deleteEmployee(id);
    } else if (strcmp(command, "update-salary") == 0) {
        int id;
        float newSalary;
        printf("Enter Employee ID and New Salary: ");
        scanf("%d %f", &id, &newSalary);
        updateEmployeeSalary(id, newSalary);
    } else {
        printf("Unknown command: %s\n", command);
    }

    // Clear input buffer
    while (getchar() != '\n');
}


int main() {
    char input[MAX_INPUT_SIZE];

    printf("Welcome to the Company Management System!\n");
    printf("Enter commands (type 'exit' to quit and 'help' to see commands):\n");

    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Handle EOF and prevent an infinite loop
        }

        // Remove trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Check for exit command
        if (strncmp(input, "exit", 4) == 0) {
            printf("Exiting system. Goodbye!\n");
            break;
        }

        // Check for help command
        if (strcmp(input, "help") == 0) {
            printf("\nAvailable Commands:\n");
            printf("  add-company         - Add a new company\n");
            printf("  list-companies      - List all companies\n");
            printf("  delete-company      - Delete a company by ID\n");
            printf("  add-position        - Add a new position to a company\n");
            printf("  list-positions      - List all positions (or by company ID)\n");
            printf("  delete-position     - Delete a position by ID\n");
            printf("  add-employee        - Add a new employee to a position\n");
            printf("  list-employees      - List all employees (or by position ID)\n");
            printf("  delete-employee     - Delete an employee by ID\n");
            printf("  update-salary       - Update an employee's salary\n");
            printf("  exit                - Quit the system\n");
            printf("  help                - Display this help message\n\n");
            continue;
        }
        // Parse and execute the command
        parseCommand(input);
    }

    return 0;
}