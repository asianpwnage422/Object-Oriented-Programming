#include <iostream>
#include <string>
#include "polygon.hpp"
#include "polynomial.hpp"
using namespace std;
void PrintPoints (Polygon p) {
    for (unsigned int i=0; i<p.getNumOfPoints(); i++) {
        for (unsigned int j=0; j<p.getDimension(); j++)
            cout << p.getValue(i, j) << " ";
        cout << endl;
    }
}
int main(){
    cout << "Polygon:" << endl;
    Polygon p(3, 4);
    double k = 0;
    for (int i=0; i<p.getNumOfPoints(); i++){
        for (int j=0; j<p.getDimension(); j++) {
            k += 1;
            p.setValue(k, i, j);
        }
    }
    PrintPoints(p);
    double* centroid = p.FindCentroid();
    for (int n=0; n<p.getDimension(); n++) cout <<centroid[n]<< " ";
    cout << endl << endl;
    
    //Polynomial
    cout << "Polynomial:" << endl;
    int polyn_a[5] = {1,2,3,4,5};
    int expon[5] = {1,2,3,4,5};
    Polynomial example(polyn_a,expon,5);
    example.display();
    example.add(4,2);
    cout << "after added 4,2:"<< endl;
    example.display();
    example.differentiate();
    cout << "after differentiation:"<< endl;
    example.display();
    
}