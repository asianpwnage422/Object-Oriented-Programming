//
//  bigint.hpp
//  bigint
//
//  Created by raisemmina on 2020/5/12.
//  Copyright © 2020 raisemmina. All rights reserved.
//

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
using namespace std;

class bigint {
private:
    int size;
    int v[5];//input num
    int length_v[5];//its digit length
public:
    void initialize();
    void print_v();
    friend long get(long x);
    bigint(); 
    bigint(long x0);
    bigint(long x0, long x1);
    bigint(long x0, long x1, long x2);
    bigint(long x0, long x1, long x2, long x3);
    bigint(long x0, long x1, long x2, long x3, long x4);

    friend ostream& operator<<(ostream &os, const bigint& number);
    friend istream& operator>>(istream &is, bigint& t);
    friend bool operator > (const bigint& tl, const bigint& tr);
    friend bool operator < (const bigint& tl, const bigint& tr);
    friend bool operator == (const bigint& tl, const bigint& tr);
    friend bool operator <= (const bigint& tl, const bigint& tr);
    friend bool operator >= (const bigint& tl, const bigint& tr);
    friend bool operator != (const bigint& tl, const bigint& tr);
    friend bigint operator + (const bigint& tl, const bigint& tr);
    friend bigint operator + (const bigint& t, const int );
    friend bigint operator - (const bigint& tl, const bigint& tr);
    friend bigint operator - (const bigint& t, const int );
    
    void read(string str, bigint& t);
    
};
long count(long x);
long pow10(long x);
//long str2int(char c[],int start,int end);
#endif 
