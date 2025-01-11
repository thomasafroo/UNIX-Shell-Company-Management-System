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
/*
// Abstraction of the structure of a company
typedef struct Company {
    int id;
    char name[50];
    char location[50];
    char industry[30];
} Company;

typedef struct Position {
    int id;
    char title[50];
    int companyId; // Link to a company
    float minSalary;
    float maxSalary;
} Position;

typedef struct {
    int id;
    char name[50];
    int positionId; // Links to a specific position
    float salary;
} Employee;

// Grouping the parts together
Company companies[MAX_COMPANIES];
int companyCount = 0;

Position positions[MAX_POSITIONS];
int positionCount = 0;

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

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
*/
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