
#include "main.h"
#include <stdio.h>

#define HOURLY_RATE 0
#define SALARY 1

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
                printf("PF: ");
                scanf("%f", &employees[i].pf);
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
