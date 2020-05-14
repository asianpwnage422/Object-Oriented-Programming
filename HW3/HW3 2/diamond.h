#ifndef DIAMOND_H
#define DIAMOND_H
#include <iostream>
#include <string>
using namespace std;
//diamond defintion
class Diamond{
    public:
        Diamond(int = 0, char = '#', char = '*');
        //set functions should not be const
        void SetSize(int inputSize);
        void SetBorder(char newborder);
        void SetFill(char newFill);
        //Get functions 
        const int GetSize();
        int Perimeter();
        double Area();
        //Grow and Shrink return 1 if success
        int Grow();
        int Shrink();
        void Draw();
        void Summary();

    private:
        int size;
        char border;
        char fill;
};
#endif
