//
//  polygon.hpp
//  poly
//
//  Created by raisemmina on 2020/4/30.
//  Copyright © 2020 raisemmina. All rights reserved.
//

#ifndef polygon_hpp
#define polygon_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class Polygon {
public:

    Polygon (unsigned int m=0, unsigned int n=0);
    Polygon (const Polygon& mt);
    ~Polygon ();
    double* FindCentroid() const;
    const int getNumOfPoints() const;
    const int getDimension() const;
    const double getValue (unsigned int m, unsigned int n) const;
    bool setValue (double  &value, unsigned int m, unsigned int n);
private:
    unsigned int _m;
    unsigned int _n;
    double** _point; 
};
#endif /* polygon_hpp */
