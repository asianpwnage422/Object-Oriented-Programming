//
//  polygon.cpp
//  poly
//
//  Created by raisemmina on 2020/4/30.
//  Copyright © 2020 raisemmina. All rights reserved.
//

#include "polygon.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

Polygon::Polygon (unsigned int m , unsigned int n ):_m(m),_n(n) {
    cout << "default constructor" << endl; // default constructor
    _point = new double*[_m];
    for( unsigned int i=0; i<m; i++ ){
        _point[i] = new double[n];
        for( unsigned int j=0; j<_n; j++ )
            _point[i][j] = 0;
    }
    
}
Polygon::Polygon (const Polygon& mt) {
    cout << "copy constructor"<< endl;
    if( mt._point == NULL ){
        _m=0;
        _n=0;
        _point=NULL;
    }
    else{
        _m = mt._m;
        _n = mt._n;
        _point = new double*[_m];
        for( unsigned int i=0; i<_m; i++ ){
            _point[i] = new double[_n];
            for( unsigned int j=0; j<_n; j++ )
                _point[i][j] = mt._point[i][j];
        }
    }
}
double* Polygon::FindCentroid() const // return the centroid
{
    double* centroid = new double[_n];
    for( int j=0; j<_n; j++ ){
        centroid[j] = 0;
        for( int i=0; i<_m; i++ ) {
            centroid[j]+=_point[i][j];
        }
        centroid[j]/=_m;
    }
    return centroid;
}
Polygon::~Polygon (){
    cout << "destructor" << endl;
    if(_point!=NULL) {
        for( unsigned int i=0; i<_m; i++ ) delete [] _point[i];
        delete [] _point;
    }
}; // destructor
const int Polygon::getNumOfPoints() const { return _m; }
const int Polygon::getDimension() const { return _n; }
const double Polygon::getValue (unsigned int m, unsigned int n) const {
    if (m<0 || m>=_m || n<0 || n>=_n) {
        cerr << "ERROR: Index our of range" << endl;
        exit(-1);
    }
    else return _point[m][n];
}
bool Polygon::setValue (double &value, unsigned int m, unsigned int n) {
    _point[m][n]=0;
    if (m>=0 && m<_m && n>=0 && n<_n) {
        _point[m][n] = value;
        return true;
    }
    else return false;
}



