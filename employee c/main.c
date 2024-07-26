#include <stdio.h>

#define MAX_EMPLOYEES 5
#define MAX_NAME_LENGTH 50

// For payment methods
#define HOURLY_RATE 0
#define SALARY 1

#define PF_RATE 0.083 // 8.3% PF rate

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

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees = MAX_EMPLOYEES; // Assuming 5 employees

    // Input employee details
    inputEmployeeDetails(employees, numEmployees);

    // Calculate total payment for each employee
    calculateTotalPayment(employees, numEmployees);

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
                employees[i].pf = employees[i].basicSalary * PF_RATE;
                // Calculate total payment including basic salary, PF, insurance, and extra
                employees[i].totalPayment = employees[i].basicSalary - employees[i].pf
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
