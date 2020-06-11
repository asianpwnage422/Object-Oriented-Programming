#include <iostream>
#include "shape.hpp"
using namespace std;

Shape::Shape(int x_c, int y_c) : x(x_c), y(y_c){}
Shape::~Shape(){}
void Shape::print() const{
    cout << "x is " << x << "y is " << y << endl;
}
