#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include "student.hpp"
using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	char instream[40];
	char outstream[40];
	do
	{	
		cout << "Please enter the name of the input file.\n" << "Filename:" << endl;
		cin.getline(instream,40);
		in.open(instream);
		
		if (!in)
			cout << "Invalid name, Please re-enter."<< endl;
	}while (!in);
	
	do 
	{
	
		cout << "Please enter the name of the output file.\n" << "Filename:" << endl;
		cin.getline(outstream,40);
		out.open(outstream);
		
		if (!out)
			cout << "Invalid name, Please re-enter."<< endl;
	}while(!out);

	int numStudents;
	string l;
	string f;

	in >> numStudents;
	
	int attE,projE,midE,finalE;//english grade
    int termH,midH,finalH;//history grade
    int q1,q2,q3,q4,q5,t1,t2,finalM;//math grade	
	Student **gradeList = new Student *[numStudents];
	string c[numStudents];
	for (int i = 0; i < numStudents; i++)
	{
		getline(in, l, ',');
		getline(in,f);
		in >> c[i];		    
		if (c[i] == "English")			
		{
			in >> attE;
			in >> projE;
			in >> midE;
			in >> finalE;
			gradeList[i] = new English(f, l, c[i], attE, projE, midE, finalE);
			// cout << f << " " << l << " course is " << c[i] << "\n attendance is " << attE << "\n projE is " << projE << "\n and mid and final is " << midE << " " << finalE << endl;
		}
		else if (c[i] == "History")			
		{
			in >> termH;
			in >> midH;
			in >> finalH;
			gradeList[i] = new History(f, l, c[i], termH, midH, finalH);
			// cout << f << " " << l << " is History : " << termH << " " << midH << " " << finalH << endl;
		}
	    else if (c[i] == "Math")		
		{	
			in >> q1;
			in >> q2;
			in >> q3;
			in >> q4;
			in >> q5;
			in >> t1;
			in >> t2;
			in >> finalM;
			gradeList[i] = new Math(f, l, c[i], q1, q2, q3, q4, q5, t1, t2,finalM);
			// cout << f << " " << l << " Math is " << q1 << " " << q2 << " " << q3  << " " << q4 << " " << q5 << " " << t1  << " " << t2 << " " << finalM << endl;
		}
	}
    in.close();	
    out << setiosflags(ios::left);
	out << "Student Grade Summary" << endl;
    out << "----------------------------------"<< endl<<endl;
    out << "ENGLISH CLASS"<<endl<<endl;
    out << setw(35) << "Student";
    out << setw(20) << "Final";
    out << setw(20) << "Final";
    out << setw(8) << "Letter" << endl ;
    out << setw(35) << "Name";
    out << setw(20) << "Exam";
    out << setw(20) << "Avg";
    out << setw(8) << "Grade" << endl;
    out << "---------------------------------------------------------------------------------"<< endl;
    for (int i = 0; i < numStudents; i++)
    {
        if(c[i]=="English")
        {
            //cout << gradeList[i]->getName() << endl;
            out << setiosflags(ios::left) << setw(35) << gradeList[i]->getName() << setw(20)
                << gradeList[i]->getFinal() << 
                setiosflags(ios::fixed) << setw(20) << setprecision(2) << gradeList[i]->ComputeAverage()<<setw(8);
            if(gradeList[i]->ComputeAverage()>=90) out <<"A";
            else if(gradeList[i]->ComputeAverage()>=80 &&gradeList[i]->ComputeAverage()<90 ) out<<"B";
            else if(gradeList[i]->ComputeAverage()>=70 &&gradeList[i]->ComputeAverage()<80) out<<"C";
            else if(gradeList[i]->ComputeAverage()>=60 &&gradeList[i]->ComputeAverage()<70) out<<"D";
            else if(gradeList[i]->ComputeAverage()<60) out<<"F";
            out<<endl;
        }
    }
    out<<endl;
    out << setiosflags(ios::left);
    out << "HISTORY CLASS"<<endl<<endl;
    out << setw(35) << "Student";
    out << setw(20) << "Final";
    out << setw(20) << "Final";
    out << setw(8) << "Letter" << endl ;
    out << setw(35) << "Name";
    out << setw(20) << "Exam";
    out << setw(20) << "Avg";
    out << setw(8) << "Grade" << endl;
    out << "---------------------------------------------------------------------------------"<< endl;
    for (int i = 0; i < numStudents; i++)
    {
        if(c[i]=="History")
        {
            //cout << gradeList[i]->getName() << endl;
            out << setiosflags(ios::left) << setw(35) << gradeList[i]->getName() << setw(20)
                << gradeList[i]->getFinal() << 
                setiosflags(ios::fixed) << setw(20) << setprecision(2) << gradeList[i]->ComputeAverage()<<setw(8);
            if(gradeList[i]->ComputeAverage()>=90) out <<"A";
            else if(gradeList[i]->ComputeAverage()>=80 &&gradeList[i]->ComputeAverage()<90 ) out<<"B";
            else if(gradeList[i]->ComputeAverage()>=70 &&gradeList[i]->ComputeAverage()<80) out<<"C";
            else if(gradeList[i]->ComputeAverage()>=60 &&gradeList[i]->ComputeAverage()<70) out<<"D";
            else if(gradeList[i]->ComputeAverage()<60) out<<"F";
            out<<endl;
        }
    }
    out<<endl;
    out << setiosflags(ios::left);
    out << "MATH CLASS"<<endl<<endl;
    out << setw(35) << "Student";
    out << setw(20) << "Final";
    out << setw(20) << "Final";
    out << setw(8) << "Letter" << endl ;
    out << setw(35) << "Name";
    out << setw(20) << "Exam";
    out << setw(20) << "Avg";
    out << setw(8) << "Grade" << endl;
    out << "---------------------------------------------------------------------------------"<< endl;
    for (int i = 0; i < numStudents; i++)
    {
        if(c[i]=="Math")
        {
            out << setiosflags(ios::left) << setw(35) << gradeList[i]->getName() << setw(20)
                << gradeList[i]->getFinal() << 
                setiosflags(ios::fixed) << setw(20) << setprecision(2) << gradeList[i]->ComputeAverage()<<setw(8);
            if(gradeList[i]->ComputeAverage()>=90) out <<"A";
            else if(gradeList[i]->ComputeAverage()>=80 &&gradeList[i]->ComputeAverage()<90 ) out<<"B";
            else if(gradeList[i]->ComputeAverage()>=70 &&gradeList[i]->ComputeAverage()<80) out<<"C";
            else if(gradeList[i]->ComputeAverage()>=60 &&gradeList[i]->ComputeAverage()<70) out<<"D";
            else if(gradeList[i]->ComputeAverage()<60) out<<"F";
            out<<endl;
        }
    }
    delete []gradeList;
	out.close();
	return 0;
}