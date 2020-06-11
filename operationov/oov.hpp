#ifndef OOV_HPP
#define OOV_HPP
#include <iostream>
using namespace std;
//overload array operations
//add, compare
//output, input
class Array{
    friend ostream &operator<<(ostream &, const Array &);
    friend istream &operator>>(istream &, Array &);
    private:
        int size;
        int* ptr;
        static int arraycnt;
    public:
    Array(int = 10);
    Array(const Array &);
    ~Array();
    int getsize() const;
    const Array & operator=(const Array &right);
    Array & operator+(Array &right);
    bool operator==(Array &right)const;
    int operator[](int) ;
    int operator[](const int)const;
};
#endif