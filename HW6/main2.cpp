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
	// do
	// {	
	// 	cout << "Please enter the name of the file that you want open ending with (.txt)"<< endl;
	// 	cin.getline(instream,40);
	// 	in.open(instream);
		
	// 	if (!in)
	// 		cout << "Invalid name, Please re-enter."<< endl;
	// }while (!in);
	
	// do 
	// {
	
	// 	cout << "Please enter the name of the outputfile ending with (.txt))"<<endl;
	// 	cin.getline(outstream,40);
	// 	out.open(outstream);
		
	// 	if (!out)
	// 		cout << "Invalid name, Please re-enter."<< endl;
	// }while(!out);

	int size;
	string l;
	string f;
	string c;
	double t1;
	double t2;
	double proj;
	double fe;
	double m;
	double a;
	double term;
	double qu[4];
	char finalM;
	char finalH;
	char finalE;
	int aa = 0;
	int bb = 0;
	int cc = 0;
	int dd = 0;
	int ff = 0;
	
	in >> size;
	
		
	Student **gradeList = new Student *[size];
	for (int i = 0; i < size; i++)
    	{
 		getline(in, l, ',');
                getline(in,f);
                in >> c;		    
        	if (c == "English")			
        	{
         		
            		in >> term;
            		in >> m;
            		in >> fe;
            		// gradeList[i] = new English(l, f, c, term, m, fe);
			cout << f << " " << l << " course is " << c << " is term, m ,fe" << term << m << fe << endl;
           	}
        	
		if (c == "History")			
        	{
			in >> a;
			in >> proj;
			in >> m;
			in >> fe;
            		// gradeList[i] = new History(f, l, c, a, proj, m, fe);
            cout << c << " is a, proj, m ,fe : " << a << " " << proj << " " << " " << m << " " << fe << endl;
        	}
        	if (c == "Math")		
        	{
            		
		
			for (int p= 0; p < 5; p++)
				in >> qu[i];
			in >> t1;
			in >> t2;
			in >> fe;
            		// gradeList[i] = new Math(f, l, c, qu, t1, t2, fe);
            cout << c << " is t1, t2 ,fe : " << t1 << t2 << fe << endl;
        	}
    	}
    
       
    	in.close();	
   
	// for (int i = 0; i < size; i++)		
    // 	{
    //     if (gradeList[i]->Average() >= 90 && gradeList[i]->Average() <= 100)
    //     {
    //         	finalE = 'A';
	// 	finalH = 'A';
	// 	finalM = 'A';
	// 	aa++;	
    //     }
    //     if (gradeList[i]->Average() >= 80 && gradeList[i]->Average() <= 89 )
    //     {
    //         	finalE = 'B';
    //            	finalH = 'B';
    //           	finalM = 'B';
	// 	bb++;	
    //     }
    //     if (gradeList[i]->Average() >= 70 && gradeList[i]->Average() <= 79 )
    //     {
    //         	finalE = 'C';
    //             finalH = 'C';
    //             finalM = 'C';
	// 	cc++;	
    //     }
    //     if (gradeList[i]->Average() >= 60 && gradeList[i]->Average() <= 69 )
    //     {
    //         	finalE = 'D';
    //             finalH = 'D';
    //             finalM = 'D';
	// 	dd++;	
    //     }
    //     if (gradeList[i]->Average() >= 0 && gradeList[i]->Average() <= 59 )
    //     {
    //         	finalE = 'F';
    //             finalH = 'F';
    //             finalM = 'F';
	// 	ff++;	
    //     }
	
    // }
    
    // 	cout << "Processing Complete......" << endl;
	// out << "Grade Summary" << endl;
	// out << "English Class\n\n";
	// out << "Student Name"<<"                              ";
	// out << "Final Exam    ";
	// out << "Final Avg    ";
	// out << "Letter Grade\n";
	// out << "-------------------------------------------------------------------------------------"<<endl << endl;
	// for (int i = 0; i < size; i++)
    // 	{
	// 	if(c == "English")
    //     	out <<gradeList[i]->GetFname() << " " << gradeList[i]->GetLname()<<"                                                 "<< gradeList[i]->Final() << "         "<<setprecision(2)<< gradeList[i]->Average() <<"    "<< finalE << endl;
    // 	}
	// out << "Grade Summary" << endl;
    //     out << "History Class\n\n";
    //     out << "Student Name"<<"                              ";
    //     out << "Final Exam    ";
    //     out << "Final Avg    ";
    //     out << "Letter Grade\n";
    //     out << "-------------------------------------------------------------------------------------"<<endl << endl;
	// for (int i = 0; i < size; i++)
    //     {
    //             if (c == "History")
    //             {
    //                     out <<gradeList[i]->GetFname() << " " << gradeList[i]->GetLname()<<"                                         "<< gradeList[i]->Final() << "         "<< setprecision(2)<<gradeList[i]->Average() <<"    "<< finalH <<endl;
	// 	}
	// }
	// out << "Grade Summary" << endl;
    //     out << "Math Class\n\n";
    //     out << "Student Name"<<"                              ";
    //     out << "Final Exam    ";
    //     out << "Final Avg    ";
    //     out << "Letter Grade\n";
    //     out << "------------------------------------------------------------------------------------"<<endl<< endl;
	// for (int i = 0; i < size; i++)
    //     {
    //             if (c == "Math")
    //             {
    //                     out <<gradeList[i]->GetFname() << " " << gradeList[i]->GetLname()<<"                                         "<< gradeList[i]->Final() << "        "<<setprecision(2)<< gradeList[i]->Average() <<"    "<<finalM <<endl;
	// 	}
	// }

	// out << "\n\nOVERALL GRADE DISTRIBUTION:" << endl;
    // 	out << "A:  " << aa << endl;
    // 	out << "B:  " << bb << endl;
    // 	out << "C:  " << cc << endl;
    // 	out << "D:  " << dd << endl;
    // 	out << "F:  " << ff << endl;
		
	// out.close();
	
	return 0;
}