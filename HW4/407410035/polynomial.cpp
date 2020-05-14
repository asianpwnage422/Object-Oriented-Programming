//
//  polynomial.cpp
//  polynomial
//
//  Created by raisemmina on 2020/5/5.
//  Copyright © 2020 raisemmina. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "polynomial.hpp"
using namespace std;
void Polynomial::add(CoefType c, int e) {
    NodePointer terms = head;
    NodePointer t;
    while (terms->next!=NULL){
        if (terms->next->data.expo < e){ // find an internal position
            NodePointer temp = terms->next;
            t = new Node(c,e);
            terms->next = t;
            t->next = temp;
            return;
        }
        else if (terms->next->data.expo == e){ //clash with existing exponent
            terms->next->data.coef += c;
            return;
        }
        terms = terms->next;
    }
    t = new Node(c,e);
    terms->next = t;
    
}
Polynomial::Polynomial(CoefType* c, int* e, int num){
    NodePointer terms = new Node();
    head = terms;
    for (int i = 0 ; i<num ; i++) {
        add(c[i], e[i]);
    }
    cout << "constructor" <<endl;
}
Polynomial::~Polynomial(){
    NodePointer terms = head ;
    while (terms!=NULL) {
        terms = terms->next;
        delete head;
        head = terms;
    }
    cout << "destructor" << endl;
}
void Polynomial::differentiate(){
    NodePointer terms = head;
    while (terms!= NULL) {
        if (terms->next->data.expo == 0) { // constant term
            NodePointer temp = terms->next;
            terms->next = temp->next;
            delete temp;
        }
        else
            terms->next->data.coef = terms->next->data.coef * terms->next->data.expo--;
        terms = terms->next;
    }
}
void Polynomial::show(){
    NodePointer terms = head;
    while (terms!= NULL) {
        cout << terms->next->data.coef<<" "<<terms->next->data.expo << endl;
        terms = terms->next;
        if(terms->next==NULL)break;
        
    }
}
