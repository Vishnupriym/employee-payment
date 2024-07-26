#include <stdio.h>
#include "employee.h"

#define MAX_EMPLOYEES 10

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    inputEmployeeDetails(employees, numEmployees);

    return 0;
}

#endif
