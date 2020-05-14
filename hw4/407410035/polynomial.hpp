//
//  polynomial.hpp
//  polynomial
//
//  Created by raisemmina on 2020/5/5.
//  Copyright © 2020 raisemmina. All rights reserved.
//

#ifndef polynomial_hpp
#define polynomial_hpp
#include <stdio.h>

#define NodePointer Node*
typedef int CoefType;

class Term {
public:
    CoefType coef;
    int expo;
};

class Node {
private:
    Term data;
    NodePointer next;
    
public:
    Node (CoefType co = 0, int ex = 0, Node * ptr = NULL) {
        data.coef = co;
        data.expo = ex;
        next = ptr; }
    friend class Polynomial;
};

class Polynomial {
private:
    NodePointer head;
public:
    Polynomial (CoefType* c = NULL, int* e = NULL, int num = 0);

    ~Polynomial();
  
    void add (CoefType c, int e);

    void differentiate();
    void show();
};
#endif /* polynomial_hpp */
