// WilsonNoah_AbstractBaseClasses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Employee.h"
#include "Student.h"
#include "Base.h"
#include <vector>

std::vector<Base*> baseVec;

void ManageRecords();
void AddRecord();


int main()
{
    bool proceed = true;

    Student* s = new Student();
    Student* main = s;
    main = s;
    baseVec.push_back(main);

    Employee* e = new Employee();
    Employee* maine = e;
    maine = e;
    baseVec.push_back(maine);

    int userinput;
    char userchar;

    while (proceed)
    {
        std::cout << "Would you like to: " << std::endl;
        std::cout << "1) Add a Record" << std::endl;
        std::cout << "2) Display all Records" << std::endl;
        while (true)
        {
            std::cin >> userinput;
            if (std::cin.fail() || (userinput != 1 && userinput != 2))
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Please select a valid option." << std::endl;
                continue;
            }
            std::cin.clear();
            break;
        }
        if (userinput == 1) { AddRecord(); }
        else { ManageRecords(); }
        
        std::cout << "Would you like to continue? (Y)es or (N)o: ";
        while (true)
        {
            std::cin >> userchar;
            if (std::cin.fail() || (userchar != 'y' && userchar != 'Y' && userchar != 'n' && userchar != 'N'))
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Please select a valid option of Y for Yes, or N for no." << std::endl;
                continue;
            }
            std::cin.clear();
            break;
        }
        if (userchar == 'N' || userchar == 'n')
        {
            proceed = false;
        }
    }
    for (int i = 0; i < baseVec.size(); i++)
    {
        delete baseVec[i];
    }
}

void ManageRecords()
{
    char userchar;
    int userinput;

    std::cout << std::endl;
    for (int i = 0; i < baseVec.size(); i++)
    {
        Student* s = dynamic_cast<Student*>(baseVec[i]);
        Employee* e = dynamic_cast<Employee*>(baseVec[i]);
        std::cout << i << ")";
        if (s != nullptr)
        {
            std::cout << "Student: " << std::endl;
            s->DisplayRecord();
            std::cout << std::endl;
        }
        if (e != nullptr)
        {
            std::cout << "Employee: " << std::endl;
            e->DisplayRecord();
            std::cout << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Would you like to copy any records? (Y)es or (N)o" << std::endl;
        std::cin >> userchar;
        if (std::cin.fail() || (userchar != 'y' && userchar != 'Y' && userchar != 'n' && userchar != 'N'))
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Please select a valid option of Y for Yes, or N for no." << std::endl;
            continue;
        }
        std::cin.clear();
        break;
    }
    if (userchar == 'y' || userchar == 'Y')
    {
        while (true)
        {
            std::cout << "Please select one of the records to be replaced: ";
            std::cin >> userinput;
            if (std::cin.fail() || (userinput > (baseVec.size() - 1)) || userinput < 0)
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Please select a valid option." << std::endl;
                continue;
            }
            std::cin.clear();
            break;
        }
        int temp = userinput;
        while (true)
        {
            std::cout << "Please select a different record to be copied onto the previously selected record: ";
            std::cin >> userinput;
            Student* s = dynamic_cast<Student*>(baseVec[temp]);
            Employee* e = dynamic_cast<Employee*>(baseVec[temp]);
            Student* ds = dynamic_cast<Student*>(baseVec[userinput]);
            Employee* de = dynamic_cast<Employee*>(baseVec[userinput]);
            if (std::cin.fail() || (userinput > (baseVec.size() - 1)) || userinput < 0 || userinput == temp || (s != nullptr && de != nullptr || e != nullptr && ds != nullptr))
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Please select a valid option." << std::endl;
                continue;
            }
            else
            {
                if (s != nullptr)
                {
                    s->_name = ds->_name;
                    s->_program = ds->_program;
                    s->_gpa = ds->_gpa;
                    s->_likeability = ds->_likeability;
                    baseVec.erase(baseVec.begin() + temp);
                    baseVec.push_back(s);
                }
                if (e != nullptr)
                {
                    e->_name = de->_name;
                    e->_department = de->_department;
                    e->_salary = de->_salary;
                    baseVec.erase(baseVec.begin() + temp);
                    baseVec.push_back(e);
                }
            }
            std::cin.clear();
            break;
        }
    }

}

//fix userchar input

void AddRecord()
{

        std::cout << "What type of record would you like to add?" << std::endl;
        std::cout << "1) Employee" << std::endl;
        std::cout << "2) Student" << std::endl;
        int userinput;
        char* namechar = new char[50];
        char* secondarychar = new char[50];
        while (true)
        {
            std::cin >> userinput;
            if (std::cin.fail() || (userinput != 1 && userinput != 2))
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Please select a valid option." << std::endl;
                continue;
            }
            std::cin.clear();
            break;
        }
            if (userinput == 1)
            {
                Employee* ee = new Employee();
                while (true)
                {
                    std::cout << "What is the name: ";
                    std::cin >> namechar;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(CHAR_MAX, '\n');
                        std::cout << "Please input a valid name." << std::endl;
                    }
                    else
                    {
                        std::cin.clear();
                        std::cin.ignore(CHAR_MAX, '\n');
                        ee->_name = namechar;
                        break;
                    }
                    std::cin.clear();
                    break;
                }

                while (true)
                {
                    std::cout << "What is the salary: ";
                    userinput = 0;
                    std::cin >> userinput;
                    if (std::cin.fail() || userinput < 0)
                    {
                        std::cin.clear();
                        std::cin.ignore(INT_MAX, '\n');
                        std::cout << "Please input a valid salary." << std::endl;
                    }
                    else
                    {
                        std::cin.clear();
                        std::cin.ignore(CHAR_MAX, '\n');
                        ee->_salary = userinput;
                        break;
                    }
                    std::cin.clear();
                    break;
                }
                while (true)
                {
                    std::cout << "What is the department: ";
                    std::cin >> secondarychar;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(INT_MAX, '\n');
                        std::cout << "Please input a valid department." << std::endl;
                    }
                    else
                    {
                        std::cin.clear();
                        std::cin.ignore(CHAR_MAX, '\n');
                        ee->_department = secondarychar;
                        break;
                    }
                    std::cin.clear();
                    break;
                }
                std::cout << "You have created " << ee->_name << ", in the " << ee->_department << " department with a salary of " << ee->_salary << "." << std::endl;
                baseVec.push_back(ee);
            }
            else
            {
                Student* ss = new Student();
                while (true)
                {
                    std::cout << "What is the name: ";
                    std::cin >> namechar;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(CHAR_MAX, '\n');
                        std::cout << "Please input a valid name." << std::endl;
                    }
                    ss->_name = namechar;
                    std::cin.clear();
                    break;
                }
                while (true)
                {
                    std::cout << "What is the program: ";
                    std::cin >> secondarychar;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(CHAR_MAX, '\n');
                        std::cout << "Please input a valid program." << std::endl;
                    }
                    else
                    {
                        ss->_program = secondarychar;
                    }
                    std::cin.clear();
                    break;
                }
                while (true)
                {
                    std::cout << "What is the GPA: ";
                    std::cin >> userinput;
                    if (std::cin.fail() || userinput < 0)
                    {
                        std::cin.clear();
                        std::cin.ignore(CHAR_MAX, '\n');
                        std::cout << "Please input a valid GPA." << std::endl;
                    }
                    else
                    {
                        ss->_gpa = userinput;
                    }
                    std::cin.clear();
                    break;
                }
                while (true)
                {
                    std::cout << "What is the likeability: ";
                    std::cin >> userinput;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(CHAR_MAX, '\n');
                        std::cout << "Please input a valid likeability." << std::endl;
                    }
                    else
                    {
                        ss->_likeability = userinput;
                    }
                    std::cin.clear();
                    break;
                }
                std::cout << "You have created " << ss->_name << ", in the " << ss->_program << " program with a GPA of " << ss->_gpa << " and a likeability of " << ss->_likeability << "." << std::endl;
                baseVec.push_back(ss);
            }
            delete namechar;
            delete secondarychar;
        
}

