
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_NAME_LENGTH 50

struct Employee {
    char name[MAX_NAME_LENGTH];
    int hoursWorked;
    int paymentMethod;
    float hourlyRate;
    float basicSalary;
    float pf;
    float insurance;
    float extra;
};

void inputEmployeeDetails(struct Employee employees[], int numEmployees);

#endif
