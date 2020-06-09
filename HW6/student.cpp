#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "student.hpp"

Student::Student(string inputFirst, string inputLast, string numCourse){
    last_name = new char[inputFirst.length()+1];
    first_name = new char[inputLast.length()+1];
    inputFirst.copy(last_name,inputFirst.length(),0);
    inputLast.copy(first_name,inputLast.length(),0);
    if(numCourse.compare("English") == 0)
        course = 1;
    else if(numCourse.compare("History") == 0)
        course = 2;
    else if(numCourse.compare("Math") == 0)
        course = 3;
    else
    {
            course = 0;
            cout << "Not valid course" << endl;
    }
}
int Student::getCourse()const{return course;}
char* Student::getName()const{;}
Student::~Student(){
    delete first_name;
    delete last_name;
    cout << "Base Destructor" << endl;
}

