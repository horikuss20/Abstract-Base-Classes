#include "Employee.h"
#include <iostream>
void Employee::DisplayRecord()
{
    std::cout << "Name: "; 
    for (int i = 0; i < sizeof(_name); i++)
    {
        std::cout << _name[i];
    }
    std::cout << '\t' << "Salary: " << _salary << '\t' << "Department: ";
    for (int i = 0; i < sizeof(_department); i++)
    {
        std::cout << _department[i];
    }
    std::cout << std::endl;
}

Employee::~Employee() // deconstructor
{
    delete _name;
    delete _department;
}

Employee::Employee()
{
    char name[] = { "Franklin" };
    char department[] = { "Being Frank with Customers" };
    *_name = *name;
    *_department = *department;
    _salary = 100;
}

Employee::Employee(char* name, int salary, char* department)
{
    this->_name = new char(*name);
    this->_salary = salary;
   this->_department = new char(*department);
}
Employee::Employee(const Employee& other) //copy constructor
{
    this->_name = new char(*other._name);
    this->_salary = other._salary;
    this->_department = new char(*other._department);
}