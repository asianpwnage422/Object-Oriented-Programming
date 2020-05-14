#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP
#include <iostream>
using namespace std;

#define NodePointer Node*
typedef int CoeffType;
// term in a polynomial
class Term {
    public:
    CoeffType coef;
    int expo;
};
// node in a linked list
class Node {
    private:
    Term data;
    NodePointer next;
    public:
    // node constructor
    Node (CoeffType co = 0, int ex = 0, Node * ptr = NULL) {
        data.coef = co;
        data.expo = ex;
        next = ptr; 
    }
    friend class Polynomial; 
};
// polynomial ADT
class Polynomial {
    private:
    NodePointer head; // pointing to the first dummy node
    public:
    // constructor
    Polynomial (CoeffType* c = NULL, int* e = NULL, int num
    = 0);
    // destructor
    ~Polynomial();
    // add a term into the polynomial
    void add (CoeffType c, int e);
    // differentiation
    void differentiate();
    // display elements
    void display();
};

#endif