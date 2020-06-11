#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <cctype>
#include <string.h>
#include "base.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin;//inputfile
    ofstream fout;//outputfile
    char instream[40];
    char outstream[40];

    //input the name of inputfile
    cout << "Please enter the name of the input file."<< endl;
    cout<<"Filename:";
    cin.getline(instream,40);
    fin.open(instream);
    //input the name of outputfile
    cout << "Please enter the name of the output file."<<endl;
    cout<<"Filename:";
    cin.getline(outstream,40);
    fout.open(outstream);
    
    int n;
    fin>>n;//num of students
    string l,f,c[n];
    
    int attE,projE,midE,finalE;//english grade
    int termH,midH,finalH;//history grade
    int q1,q2,q3,q4,q5,t1,t2,finalM;//math grade
    Student **gradeList = new Student *[n];
    for (int i = 0; i < n; i++)
    {
        //student name and subject
        getline(fin,l,',');
        getline(fin,f);
        fin >> c[i];
        
        //input grade
        if (c[i] == "English")
        {
            fin >> attE;
            fin >> projE;
            fin >> midE;
            fin >> finalE;
            gradeList[i] = new English(f, l, c[i], attE, projE,midE, finalE);
        }
        if (c[i]== "History")
        {
            fin >> termH;
            fin >> midH;
            fin >> finalH;
            gradeList[i] = new History(f, l, c[i], termH, midH, finalH);
        }
        if (c[i]== "Math")
        {
            fin >> q1;
            fin >> q2;
            fin >> q3;
            fin >> q4;
            fin >> q5;
            fin >> t1;
            fin >> t2;
            fin >> finalM;
            gradeList[i] = new Math(f, l, c[i], q1,q2,q3,q4,q5, t1, t2, finalM);
        }
    }
    fin.close();
    
    fout << "Student Grade Summary" << endl;
    fout << "------------------------------------------------------------"<< endl<<endl;
    fout << "English Class"<<endl<<endl;
    fout <<"Student"<<"             ";
    fout << "Final"<<"     ";
    fout << "Final"<< "     ";
    fout << "Letter"<<endl;
    fout << "Name   "<<"               ";
    fout  <<"Exam "<<"     ";
    fout  << "Avg  "<<"     ";
    fout << "Grade "<<endl;
    fout << "---------------------------------------------------------------------------"<< endl;
    for (int i = 0; i < n; i++)
    {
        if(c[i]=="English")
        {
            fout <<gradeList[i]->Getname();
            fout <<setw(14)<<gradeList[i]->Final()<<setw(10);
            fout<< setiosflags(ios::fixed)<<setprecision(2)<<gradeList[i]->Average()<<setw(8);
            if(gradeList[i]->Average()>=90) fout<<"A";
            else if(gradeList[i]->Average()>=80 &&gradeList[i]->Average()<90 ) fout<<"B";
            else if(gradeList[i]->Average()>=70 &&gradeList[i]->Average()<80) fout<<"C";
            else if(gradeList[i]->Average()>=60 &&gradeList[i]->Average()<70) fout<<"D";
            else if(gradeList[i]->Average()<60) fout<<"F";
            fout<<endl<<endl;
        }
    }
    fout<<endl;
    fout << "History Class"<<endl<<endl;
    fout <<"Student"<<"             ";
    fout << "Final"<<"     ";
    fout << "Final"<< "     ";
    fout << "Letter"<<endl;
    fout << "Name   "<<"               ";
    fout  <<"Exam "<<"     ";
    fout  << "Avg  "<<"     ";
    fout << "Grade "<<endl;
    fout << "---------------------------------------------------------------------------"<< endl;
    for (int i = 0; i < n; i++)
    {

        if(c[i]=="History"){
            fout <<gradeList[i]->Getname();
            fout <<setw(14)<<gradeList[i]->Final()<<setw(10);
            fout<< setiosflags(ios::fixed)<<setprecision(2)<<gradeList[i]->Average()<<setw(8);
            if(gradeList[i]->Average()>=90) fout<<"A";
            else if(gradeList[i]->Average()>=80 &&gradeList[i]->Average()<90 ) fout <<"B";
            else if(gradeList[i]->Average()>=70 &&gradeList[i]->Average()<80) fout<<"C";
            else if(gradeList[i]->Average()>=60 &&gradeList[i]->Average()<70) fout<<"D";
            else if(gradeList[i]->Average()<60) fout<<"F";
            fout<<endl<<endl;
        }
    }
    fout<<endl;
    fout << "Math Class"<<endl<<endl;
    fout <<"Student"<<"             ";
    fout << "Final"<<"     ";
    fout << "Final"<< "     ";
    fout << "Letter"<<endl;
    fout << "Name   "<<"               ";
    fout  <<"Exam "<<"     ";
    fout  << "Avg  "<<"     ";
    fout << "Grade "<<endl;
    fout << "---------------------------------------------------------------------------"<< endl;
    for (int i = 0; i < n; i++)
    {
        if(c[i]=="Math"){
            fout <<gradeList[i]->Getname();
            fout <<setw(14)<<gradeList[i]->Final()<<setw(10);
            fout<< setiosflags(ios::fixed)<<setprecision(2)<<gradeList[i]->Average()<<setw(8);
            if(gradeList[i]->Average()>=90) fout<<"A";
            else if(gradeList[i]->Average()>=80 &&gradeList[i]->Average()<90 ) fout<<"B";
            else if(gradeList[i]->Average()>=70 &&gradeList[i]->Average()<80) fout<<"C";
            else if(gradeList[i]->Average()>=60 &&gradeList[i]->Average()<70) fout<<"D";
            else if(gradeList[i]->Average()<60) fout<<"F";
            fout<<endl<<endl;
        }
    }
    fout.close();
    
    delete []gradeList;
    return 0;
}
