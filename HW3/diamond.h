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
        void setSize(int inputSize);
        int setBorder(char newborder);
        int setFill(char newFill);
        //Get functions should be const
        const int Getsize();
        const int Perimeter();
        const double Area();
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
