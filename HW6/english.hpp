#ifndef ENGLISH_HPP
#define ENGLISH_HPP
#include <string>
#include <iostream>
using namespace std;
class English : public Student{
    protected :
        char* first_name;
        char* last_name;
        int course;
    public :
        English(string, string , string);
        char* getName() const;
        int getCourse() const;
        ~English();
        virtual void print() const;
};

#endif