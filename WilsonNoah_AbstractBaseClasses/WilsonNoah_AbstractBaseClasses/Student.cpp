#include "Student.h"
#include <iostream>
void Student::DisplayRecord()
{
	std::cout << "Name: " << *_name << '\t' << "Program: " << *_program << '\t' << "GPA: " << _gpa << '\t' << "Likeability: " << _likeability << std::endl;
}

Student::Student(char* name, char* program, float gpa, int likeability)
{
	this->_name = new char(*name);
	this->_program = new char (*program);
	this->_gpa = gpa;
	this->_likeability = likeability;
}

Student::Student()
{
	char name[] = { "Ol' Mick" };
	char program[] = { "Custodian of the Porcelain Throne" };
	this->_name = name;
	this->_program = program;
	this->_gpa = 5;
	this->_likeability = 101;
}

Student::~Student()
{
	delete this->_name;
	delete this->_program;
}

Student::Student(const Student& other)
{
	this->_name = new char(*other._name);
	this->_program = new char(*other._program);
	this->_gpa = other._gpa;
	this->_likeability = other._likeability;
}