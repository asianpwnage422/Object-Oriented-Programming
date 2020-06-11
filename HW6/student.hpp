#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include <iostream>
using namespace std;
class Student 
{
    public:
        Student();
        ~Student();
        Student(string f, string l, string c);

        //Both are pure virtual functions. Retrieves specific
        //data from derived classes.
        virtual double ComputeAverage()=0;
        virtual int getFinal()=0;
        const string getCourse()const;
        const string getName()const;

    protected:
        string first;
        string last;
        string course;
};

class English : public Student 
{
    public:
        English();
        ~English();
        English(string f, string l, string c, int attEND, int proJ,
                int miD, int finalEXAM);

    private:
        double ComputeAverage();
        int getFinal();
        int attend;
        int proj;
        int midterm;
        int finalExam;
};

class History : public Student 
{
    public:
        History();
        ~History();
        History(string f, string l, string c, int term, int mid,
                int final);

    private:
        //ComputeAverage() and getFinal() are called from the
        //pure virtual function in the 'Student' class.
        double ComputeAverage();
        int getFinal();
        int termPaper;
        int midterm;
        int finalExam;
};

class Math : public Student
{
    public:
        Math();
        ~Math();
        Math(string f, string l, string c, int qOne, int qTwo, 
             int qThree, int qFour, int qFive, int tOne, int tTwo, 
             int final);

    private:
        //ComputeAverage() and getFinal() are called from the
        //pure virtual function in the 'Student' class.
        double ComputeAverage();
        int getFinal();
        int quiz_Average;
        int quizOne;
        int quizTwo;
        int quizThree;
        int quizFour;
        int quizFive;
        int testOne;
        int testTwo;
        int finalExam;
};

#endif