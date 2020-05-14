#include <iostream>
#include "polygon.hpp"
using namespace std;

Polygon::Polygon(unsigned int m, unsigned int n) : _m(m), _n(n){
    cout << "default constructor" << endl; // default constructor
    _point = new double*[_m];
    for(int i = 0; i < _m; i++ ){
        _point[i] = new double[_n];
        for(int j = 0; j < _n; j++ )
            _point[i][j] = 0;//initialize _point array to zero;
    }
}
Polygon::Polygon (const Polygon& mt){
    cout << "copy constructor"<< endl;
    if( mt._point == NULL ){
        _m = 0;
        _n = 0;
        _point = NULL;
    }//polygon has no points
    else{
        _m = mt._m;
        _n = mt._n;
        _point = new double*[_m];
        for(int i = 0; i < _m; i++ ){
            _point[i] = new double[_n];
            for(int j = 0; j < _n; j++ )
                _point[i][j] = mt._point[i][j];
        }
    }
}
Polygon::~Polygon (){
    cout << "destructor" << endl;
    if(_point == NULL) {
        return;
    }
    else{
        for(int i = 0; i < _m; i++ )
            delete [] _point[i];
        delete [] _point;
    }
};
double * Polygon::FindCentroid() const{
    double *cen = new double[_n];
    for(int i = 0; i < _n; i++){
        cen[i] = 0;
        for(int j = 0; j < _m; j++)
            cen[i] += _point[j][i];//add jth element of ith dimension
        cen[i] = cen[i]/_m;
    }
    return cen;
}
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