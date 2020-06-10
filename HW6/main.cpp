#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "student.hpp"
char* name_handler(const char* str);
int main()
{
    int numStudents = 0;
    string input_name;
    string output_name;
    cout << "Please enter the name of the input file :" << endl;
    cin >> input_name;
    cout << "Please enter the name of the output file :" << endl;
    cin >> output_name;
    ifstream input (input_name.c_str());
    ofstream output (output_name.c_str());
    cout << "Processing complete " << endl;
    input >> numStudents;
    // char* temp = new char[50];
    // input.getline(temp,50);//moves to next line
    Student **gradelist = new Student *[numStudents];

    for(int i = 0; i < numStudents; i++){
        char* temp1 = new char[50];
        input.getline(temp1,50);
        name_handler(temp1);
        // cout << temp1 << endl;
        char* temp2 = new char[100];
        input.getline(temp2,100);
        // cout << "temp2 " << temp2 << endl;
    }
    input.close();
    output.close();
    return 0;
}
char* name_handler(const char* str){
    char* last = new char[20];
    char* first = new char[20];
    int length = strlen(str);
    int i = 0;
    while(str[i] != ',') ++i;
    strncpy(last,str,i-1);
    strncpy(first,str+(i+1),(length-i)+1);
    cout << first << last << endl;//first[0], last[0] 沒錯; last[i]有錯
    char* name = new char[strlen(first) + strlen(last) +1];//+1 is for space in middle
    strcpy(name,first);
    strcat(name," ");
    strcat(name,last);
    cout << name << endl;
}