#include <iostream>
#include "circle.hpp"
using namespace std;
Circle::Circle(const int x_c, const int y_c, const int r_c): Shape(x_c,y_c),r(r_c){}
void Circle::print() const{
    cout << "x is " << x << "y is " << y << "r is " << r << endl;
}
void Circle::p_area() const{
    cout << "area of circle is " << r*r << endl;
}
