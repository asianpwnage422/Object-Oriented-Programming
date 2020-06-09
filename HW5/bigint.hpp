//
//  bigint.hpp
//  bigint
//
//  Created by raisemmina on 2020/5/12.
//  Copyright © 2020 raisemmina. All rights reserved.
//

#ifndef bigint_hpp
#define bigint_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

class bigint {
public:
    void initialize();
    friend long int count(long int x);
    bigint(); 
    bigint(long int x0);
    bigint(long int x0, long int x1);
    bigint(long int x0, long int x1, long int x2);
    bigint(long int x0, long int x1, long int x2, long int x3);
    bigint(long int x0, long int x1, long int x2, long int x3, long int x4);
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
    friend ostream& operator<<(ostream &os, const bigint& t);
    friend istream& operator>>(istream &is, bigint& t);
    void read(string str, bigint& t);
    
private:
    int size;
    long int num[5];
    long int len[5];
};
long int count(long int x);
long int pow10(long int x);
//long int str2int(char c[],int start,int end);
#endif /* bigint_hpp */
