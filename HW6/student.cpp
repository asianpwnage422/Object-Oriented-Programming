#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "student.hpp"

//base
Student::Student(string inputFirst, string inputLast, string c):first(inputFirst),last(inputLast),course(c){};
Student::~Student(){
    cout << "Base Destructor" << endl;
}
const string Student::getName()const{return first+last;}
const string Student::getCourse()const{return course;}
//constructors
English::English(string f, string l, string c, int attEND, int proJ, int miD, int finalEXAM):
                Student(f,l,c),attend(attEND),proj(proj),midterm(miD),finalExam(finalEXAM){}
History::History(string f, string l, string c,int term, int mid,const int finalEX):
                Student(f,l,c),termPaper(term),midterm(mid),finalExam(finalEX){}
Math::Math(string l, string f, string c, int qOne, int qTwo, 
             int qThree, int qFour, int qFive, int tOne, int tTwo, 
             int final) :
                Student(f,l,c),quizOne(qOne),quizTwo(qTwo),quizThree(qThree),quizFour(qFour),quizFive(qFive),testOne(tOne),testTwo(tTwo),finalExam(final){}
//destructors
English::~English(){
    cout << "English Destructor" << endl;
}
History::~History(){
    cout << "History Destructor" << endl;
}
Math::~Math(){
    cout << "Math Destructor" << endl;
}
//Compute Average
// double Student::ComputeAverage(){return 0;};
double English::ComputeAverage()
{
    return(attend*0.1+proj*0.3+midterm*0.3+finalExam*0.3);
}
double History::ComputeAverage()
{
    return(termPaper*0.25+midterm*0.35+finalExam*0.4);
}double Math::ComputeAverage()
{
    double AVR = 0;
    AVR = (quizOne+quizTwo+quizThree+quizFour+quizFive)*0.03 + testOne*0.25 + testTwo*0.25 + finalExam*0.35;
    return AVR;
}
//Get Final
int English::getFinal(){return finalExam;}
int History::getFinal(){return finalExam;}
int Math::getFinal(){return finalExam;}
