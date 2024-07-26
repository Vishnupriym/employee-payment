#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 3
#define MAX_NAME_LENGTH 50

// For payment methods
#define HOURLY_RATE 0
#define SALARY 1

#define PF_PERCENTAGE 0.083 // 8.3%

// Structure to represent an employee
struct Employee {
    char name[MAX_NAME_LENGTH];
    int hoursWorked;
    float hourlyRate;
    float basicSalary; // Basic salary
    float totalPayment;
    float pf; // Provident Fund
    float insurance;
    float extra;
    int paymentMethod; // Payment method
};

// Function prototypes
void inputEmployeeDetails(struct Employee employees[], int numEmployees);
void calculateTotalPayment(struct Employee employees[], int numEmployees);
void displayPaymentDetails(struct Employee employees[], int numEmployees);
void saveEmployeeDetails(struct Employee employees[], int numEmployees, const char* filename);
void loadEmployeeDetails(struct Employee employees[], int* numEmployees, const char* filename);

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    // Load employee details from file
    loadEmployeeDetails(employees, &numEmployees, "employees.txt");

    // Input employee details
    inputEmployeeDetails(employees, numEmployees);

    // Calculate total payment for each employee
    calculateTotalPayment(employees, numEmployees);

    // Save employee details to file
    saveEmployeeDetails(employees, numEmployees, "employees.txt");

    // Display payment details for each employee
    displayPaymentDetails(employees, numEmployees);

    return 0;
}

// Function to input employee details
void inputEmployeeDetails(struct Employee employees[], int numEmployees) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Hours worked: ");
        scanf("%d", &employees[i].hoursWorked);
        printf("Choose payment method (0 for Hourly Rate, 1 for Salary): ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case HOURLY_RATE:
                employees[i].paymentMethod = HOURLY_RATE;
                printf("Hourly rate: ");
                scanf("%f", &employees[i].hourlyRate);
                break;
            case SALARY:
                employees[i].paymentMethod = SALARY;
                printf("Basic Salary: ");
                scanf("%f", &employees[i].basicSalary);
                printf("Insurance: ");
                scanf("%f", &employees[i].insurance);
                printf("Extra: ");
                scanf("%f", &employees[i].extra);
                break;
            default:
                printf("Invalid choice, defaulting to Hourly Rate.\n");
                employees[i].paymentMethod = HOURLY_RATE;
                printf("Hourly rate: ");
                scanf("%f", &employees[i].hourlyRate);
                break;
        }
    }
}

// Function to calculate total payment for each employee
void calculateTotalPayment(struct Employee employees[], int numEmployees) {
    for (int i = 0; i < numEmployees; i++) {
        switch (employees[i].paymentMethod) {
            case HOURLY_RATE:
                // Calculate total payment based on hourly rate
                employees[i].totalPayment = employees[i].hourlyRate * employees[i].hoursWorked;
                break;
            case SALARY:
                // Calculate PF amount
                employees[i].pf = employees[i].basicSalary * PF_PERCENTAGE;
                // Calculate total payment including basic salary, PF, insurance, and extra
                employees[i].totalPayment = employees[i].basicSalary + employees[i].pf
                                            + employees[i].insurance + employees[i].extra;
                break;
        }
    }
}

// Function to display payment details for each employee
void displayPaymentDetails(struct Employee employees[], int numEmployees) {
    printf("\nPayment details for each employee:\n");
    printf("Name\t\tTotal Payment\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%s\t%.2f\n", employees[i].name, employees[i].totalPayment);
    }
}

// Function to save employee details to a file
void saveEmployeeDetails(struct Employee employees[], int numEmployees, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < numEmployees; i++) {
        fprintf(file, "%s %d %f %f %f %f %f %d\n",
                employees[i].name, employees[i].hoursWorked, employees[i].hourlyRate,
                employees[i].basicSalary, employees[i].pf, employees[i].insurance,
                employees[i].extra, employees[i].paymentMethod);
    }

    fclose(file);
}

// Function to load employee details from a file
void loadEmployeeDetails(struct Employee employees[], int* numEmployees, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading. Starting with an empty list.\n");
        *numEmployees = MAX_EMPLOYEES;
        return;
    }

    *numEmployees = 0;
    while (fscanf(file, "%s %d %f %f %f %f %f %d",
                  employees[*numEmployees].name, &employees[*numEmployees].hoursWorked,
                  &employees[*numEmployees].hourlyRate, &employees[*numEmployees].basicSalary,
                  &employees[*numEmployees].pf, &employees[*numEmployees].insurance,
                  &employees[*numEmployees].extra, &employees[*numEmployees].paymentMethod) == 8) {
        (*numEmployees)++;
        if (*numEmployees >= MAX_EMPLOYEES) {
            break;
        }
    }

    fclose(file);
}
