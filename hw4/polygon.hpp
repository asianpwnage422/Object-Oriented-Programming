#ifndef POLYGON_H
#define POLYGON_H
#include <iostream>
#include <string>
using namespace std;

class Polygon{
    private:
            unsigned int _m; // the number of points 
            unsigned int _n; // the dimension of every point 
            double** _point; // point[i]: the i-th point
            // point[i][j]: the j-th coordinate of i-point
    public:
        // default constructor
        // m is the number of points
        // n is the dimension of the points
        Polygon (unsigned int m, unsigned int n);
        Polygon (const Polygon& mt); // copy constructor ~Polygon (); 
        ~Polygon ();// destructor
        double* FindCentroid() const; // return the centroid of the
        // polygon
        const int getNumOfPoints() const;
        const int getDimension() const;
        // Accessor: Get the value stored at the m-th point and n-th dimension
        const double getValue (unsigned int m, unsigned int n) const;
        //Mutator: Set the value at the m-th point and n-th coordinate
        bool setValue (double & value, unsigned int m, unsigned int n);
};

#endif