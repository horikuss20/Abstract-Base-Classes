#pragma once
#include "Base.h"
class Employee :
    public Base
{
public:
    char* _name = new char [50];
    int _salary = 7;
    char* _department = new char[50];

    void DisplayRecord();

    ~Employee();// deconstructor

    Employee();

    Employee(char* name, int salary, char* department);

    Employee(const Employee& other); //copy constructor

    Employee& operator=(const Employee& other) //assignment operator
    {
        if (this == &other) { return *this; }
            this->_name = other._name;
            this->_salary = other._salary;
            this->_department = other._department;

        return *this;
    }


};;

