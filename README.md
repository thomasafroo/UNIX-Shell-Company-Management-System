# Unix Shell Company Management System

## Motive 
While taking software construction and data structures courses in second year, I was independently learning about Unix shells, and wanted to model a real-world construct with these areas of knowledge. Thus, I sought to design a company management system where users could keep track of information at different levels in a company's hierarchy.

## Description
The Unix Shell Company Management System is a command-line interface written in C that simulates a company's management system. It allows users to manage companies, positions, and employees with various commands.

This project was built to demonstrate modular programming, file organization, and efficient resource management in C.

---

## Features
- **Company Management**:
  - Add, list, and delete companies.
- **Position Management**:
  - Add, list, and delete job positions.
- **Employee Management**:
  - Add, list, delete, and update employee information.

---

## File Structure
```
UNIX-SHELL
  ├── company.c Implementation of company-related functions 
  ├── company.h Header file for the company module 
  ├── employee.c Implementation of employee-related functions
  ├── employee.h Header file for the employee module
  ├── position.c  Implementation of position-related functions
  ├── position.h Header file for the position module
  ├── main.c Main program logic and command parser
  ├── Makefile Build automation file 
  └── README.md
```
## Requirements
- GCC compiler or equivalent C compiler.
- Unix/Linux environment or equivalent for shell compatibility.

---

## Compilation
To compile the program, use the included `Makefile`. Simply run:

```
make
```

This will generate the executable file named `program`. Now run:
```
./program
```


