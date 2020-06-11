#include <iostream>
using namespace std;
#include "oov.hpp"

int main()
{
    Array A1(4);
    Array A2(4);
    cout << "input for array " << endl;
    cin >> A1;
    cout << "Array1 is :" << A1 << endl;
    cout << "input for array " << endl;
    cin >> A2;
    cout << "Array2 is :" << A2 << endl;
    cout << "Added is :" << A1+A2 << endl;
    cout << "Array1 is :" << A1 << endl;
    cout << "Are they equal? " << (A1==A2) << endl;
    cout << "A2[2] is " << A2[2] << endl; 
    Array A3(A2);
    cout << "Array3 is :" << A3 << endl;
    return 0;
}