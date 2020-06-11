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
    in.open("text.txt");
	out.open("outfile.txt");
	// do
	// {	
	// 	cout << "Please enter the name of the input file." << \n << "Filename:" << endl;
	// 	cin.getline(instream,40);
	// 	in.open(instream);
		
	// 	if (!in)
	// 		cout << "Invalid name, Please re-enter."<< endl;
	// }while (!in);
	
	// do 
	// {
	
	// 	cout << "Please enter the name of the output file "<< \n << "Filename:" << endl;
	// 	cin.getline(outstream,40);
	// 	out.open(outstream);
		
	// 	if (!out)
	// 		cout << "Invalid name, Please re-enter."<< endl;
	// }while(!out);

	int numStudents;
	string l;
	string f;
	string c;
	
	in >> numStudents;
	
	int attE,projE,midE,finalE;//english grade
    int termH,midH,finalH;//history grade
    int q1,q2,q3,q4,q5,t1,t2,finalM;//math grade	
	Student **gradeList = new Student *[numStudents];
	for (int i = 0; i < numStudents; i++)
	{
		getline(in, l, ',');
		getline(in,f);
		in >> c;		    
		if (c == "English")			
		{
			in >> attE;
			in >> projE;
			in >> midE;
			in >> finalE;
			gradeList[i] = new English(l, f, c, attE, projE, midE, finalE);
			cout << f << " " << l << " course is " << c << "\n attendance is " << attE << "\n projE is " << projE << "\n and mid and final is " << midE << " " << finalE << endl;
		}
		if (c == "History")			
		{
			in >> termH;
			in >> midH;
			in >> finalH;
			gradeList[i] = new History(f, l, c, termH, midH, finalH);
			cout << f << " " << l << " is History : " << termH << " " << midH << " " << finalH << endl;
		}
			if (c == "Math")		
		{	
			in >> q1;
			in >> q2;
			in >> q3;
			in >> q4;
			in >> q5;
			in >> t1;
			in >> t2;
			in >> finalM;
			gradeList[i] = new Math(f, l, c, q1, q2, q3, q4, q5, t1, t2,finalM);
			cout << f << " " << l << " Math is " << q1 << " " << q2 << " " << q3  << " " << q4 << " " << q5 << " " << t1  << " " << t2 << " " << finalM << endl;
		}
	}
    in.close();	
	out << "Student Grade Summary" << endl;
    out << "----------------------------------"<< endl<<endl;
    out << "English Class"<<endl<<endl;
    out << "Student" << setw(35);
    out << "Final" << setw(20);
    out << "Final" << setw(20);
    out << "Letter" << setw(6) << endl ;
    out << "Name" << setw(35);
    out  <<"Exam" << setw(20);
    out  << "Avg" << setw(20);
    out << "Grade" << setw(6) << endl;
    out << "---------------------------------------------------------------------------"<< endl;
    // for (int i = 0; i < n; i++)
    // {
    //     if(c[i]=="English")
    //     {
    //         out <<gradeList[i]->getName();
    //         out <<setw(14)<<gradeList[i]->Final()<<setw(10);
    //         out<< setiosflags(ios::fixed)<<setprecision(2)<<gradeList[i]->ComputeAverage()<<setw(8);
    //         if(gradeList[i]->ComputeAverage()>=90) out<<"A";
    //         else if(gradeList[i]->ComputeAverage()>=80 &&gradeList[i]->ComputeAverage()<90 ) out<<"B";
    //         else if(gradeList[i]->ComputeAverage()>=70 &&gradeList[i]->ComputeAverage()<80) out<<"C";
    //         else if(gradeList[i]->ComputeAverage()>=60 &&gradeList[i]->ComputeAverage()<70) out<<"D";
    //         else if(gradeList[i]->ComputeAverage()<60) out<<"F";
    //         out<<endl<<endl;
    //     }
    // }
    // out<<endl;
    // out << "History Class"<<endl<<endl;
    // out <<"Student"<<"             ";
    // out << "Final"<<"     ";
    // out << "Final"<< "     ";
    // out << "Letter"<<endl;
    // out << "Name   "<<"               ";
    // out  <<"Exam "<<"     ";
    // out  << "Avg  "<<"     ";
    // out << "Grade "<<endl;
    // out << "---------------------------------------------------------------------------"<< endl;
    // for (int i = 0; i < n; i++)
    // {

    //     if(c[i]=="History"){
    //         out <<gradeList[i]->getName();
    //         out <<setw(14)<<gradeList[i]->Final()<<setw(10);
    //         out<< setiosflags(ios::fixed)<<setprecision(2)<<gradeList[i]->ComputeAverage()<<setw(8);
    //         if(gradeList[i]->ComputeAverage()>=90) out<<"A";
    //         else if(gradeList[i]->ComputeAverage()>=80 &&gradeList[i]->ComputeAverage()<90 ) out <<"B";
    //         else if(gradeList[i]->ComputeAverage()>=70 &&gradeList[i]->ComputeAverage()<80) out<<"C";
    //         else if(gradeList[i]->ComputeAverage()>=60 &&gradeList[i]->ComputeAverage()<70) out<<"D";
    //         else if(gradeList[i]->ComputeAverage()<60) out<<"F";
    //         out<<endl<<endl;
    //     }
    // }
    // out<<endl;
    // out << "Math Class"<<endl<<endl;
    // out <<"Student"<<"             ";
    // out << "Final"<<"     ";
    // out << "Final"<< "     ";
    // out << "Letter"<<endl;
    // out << "Name   "<<"               ";
    // out  <<"Exam "<<"     ";
    // out  << "Avg  "<<"     ";
    // out << "Grade "<<endl;
    // out << "---------------------------------------------------------------------------"<< endl;
    // for (int i = 0; i < ; i++)
    // {
    //     if(c[i]=="Math"){
    //         out <<gradeList[i]->getName();
    //         out <<setw(14)<<gradeList[i]->Final()<<setw(10);
    //         out<< setiosflags(ios::fixed)<<setprecision(2)<<gradeList[i]->ComputeAverage()<<setw(8);
    //         if(gradeList[i]->ComputeAverage()>=90) out<<"A";
    //         else if(gradeList[i]->ComputeAverage()>=80 &&gradeList[i]->ComputeAverage()<90 ) out<<"B";
    //         else if(gradeList[i]->ComputeAverage()>=70 &&gradeList[i]->ComputeAverage()<80) out<<"C";
    //         else if(gradeList[i]->ComputeAverage()>=60 &&gradeList[i]->ComputeAverage()<70) out<<"D";
    //         else if(gradeList[i]->ComputeAverage()<60) out<<"F";
    //         out<<endl<<endl;
    //     }
    // }
    // out.close();
    
    // delete []gradeList;
    // return 0;
	out.close();
	return 0;
}