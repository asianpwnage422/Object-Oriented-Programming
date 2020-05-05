#include <iostream>
#include <string>
using namespace std;

//diamond defintion
class Diamond{
    public:
        Diamond(int inputSize, char inputBorder, char inputFill){
            
        }
        //set functions should not be const
        int setSize(int inputSize);
        int setBorder(char newborder);
        int setFIll(char newFill);
        //Get functions should be const
        const int Getsize();
        const int Perimeter();
        const double Area();
        //Grow and Shrink return 1 if success
        int Grow();
        int Shrink();
        int Draw();
        int Summary();

    private:
        int size;
        char border;
        char fill;
};