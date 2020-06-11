#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape{
    private :
        int x;
        int y;
        int r;
    public :
        Circle(const int , const int, const int);
        ~Circle();
        virtual void print() const;
        virtual void p_area() const;
}
#endif 