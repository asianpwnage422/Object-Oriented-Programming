#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
using namespace std;

class Shape{
    private:
        int x;
        int y;
    public:
        Shape(const int , const int);
        ~Shape();
        virtual void print() const;
        virtual void p_area() const = 0;
};
#endif