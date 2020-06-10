#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "student.hpp"

Student::Student(char* inputFirst, char* inputLast, char* numCourse){
    strcpy(first,inputFirst);
    strcpy(last,inputLast);   
    strcpy(course,numCourse);
}
char* Student::getCourse()const
char* getLast();
char* getFirst();
Student::~Student(){
    delete first;
    delete last;
    cout << "Base Destructor" << endl;
}

