#include <iostream>
#include <assert.h>
#include <iomanip>
#include "oov.hpp"
using namespace std;

int Array::arraycnt = 0;

Array::Array(int arraysize){
    size = (arraysize > 0)? arraysize :  10;
    ptr = new int[10];
    // ptr = NULL;
    assert(ptr != NULL);
    ++arraycnt;
    for(int i = 0; i < size; i++){
        ptr[i] = 0;
    }
}
Array::Array(const Array & source):size(source.size){
    // size = source.size;
    ptr = new int[size];
    assert(ptr != 0);
    ++arraycnt;
    for(int i = 0; i < size; i++)
        ptr[i] = source.ptr[i]; 
}
Array::~Array(){
    delete [] ptr;
    --arraycnt;
}
int Array::getsize() const{return size;};
const Array& Array::operator=(const Array& right)
{
    if(&right != this){
        if(size != right.size){
            delete [] ptr;
            size = right.size;
            ptr = new int [size];
            assert(ptr != NULL);
        }
        for(int i = 0; i < size; i++)
            ptr[i] = right.ptr[i];
    }
    return *this;
}
Array& Array::operator+(Array &right){
    if(size >= right.size){
        for(int i = 0; i < size; i++){
            ptr[i] += right.ptr[i];
        }
    }
    else{
        int* temp = new int[right.size];
        for(int i=0; i<size; i++){
            temp[i] = ptr[i];
        }
        for(int i=0; i<right.size; i++){
            temp[i] = right.ptr[i];
        }
        ptr = temp;
    }
    return *this;
}
bool Array::operator==(Array & right)const{
    if(size != right.size)
        return false;
    for(int i = 0; i < size; i++){
        if(ptr[i] != right.ptr[i])
            return false;
    }
    return true;
}
int Array::operator[](int index){
    assert(index<=size && index>=0);
    return ptr[index];
}
int Array::operator[](const int index)const{
    assert(index<=size && index>=0);
    return ptr[index];
}
ostream &operator<<(ostream &output, const Array & a){
    int i;
    for(i = 0; i < a.size; i++){
        output << setw(12) << a.ptr[i];
        if((i+1)%4==0)
            output << endl;
    }
    return output;
}
istream &operator>>(istream &input, Array &a){
    for(int i = 0; i < a.size; i++)
        input >> a.ptr[i];
    return input;
}