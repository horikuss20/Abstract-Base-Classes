#pragma once
#include "Base.h"
class Student :
    public Base
{
public:
    char* _name;
    char* _program;
    float _gpa = 2;
    int _likeability;

    void DisplayRecord();

    Student(char* name, char* program, float gpa, int likeability);

    Student();

    ~Student();

    Student(const Student& other);

   Student& operator=(const Student& other) //assignment operator
    {
        if (this == &other) { return *this; }
        this->_name = other._name;
        this->_program = other._program;
        this->_gpa = other._gpa;
        this->_likeability = other._likeability;

        return *this;
    }
};;

