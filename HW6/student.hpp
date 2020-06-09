#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include <iostream>
using namespace std;
class Student{
    protected :
        char* first_name;
        char* last_name;
        int course;
    public :
        Student(string, string , string);
        char* getName() const;
        int getCourse() const;
        ~Student();
        virtual void print() const = 0;
};

#endif