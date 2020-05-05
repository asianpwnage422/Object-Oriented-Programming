#include <iostream>
#include <string>
using namespace std;

//diamond defintion
class Diamond{
    public:
        Diamond(int inputSize, char inputBorder, char inputFill){
            
        }
        void setSize(int inputSize){
            if(inputSize < 1)
                size = 1;
            else if(inputSize > 39)
                size = 39;
            else
                size = inputSize;
        }
        int setBorder(char new_border){
            if(new_border < 33 || new_border > 126)
                return 0;
            else
                border = new_border;
        }
        const int Getsize(){
            return size;
        }
        const int Perimeter(){
            return 4*size;
        }
        const double Area(){
        }
        //Grow and Shrink return 1 if success
        int Grow(){
            if(size >= 39)
                return 0;
            else{
                size++;
                return 1;
            }
        }
        int Shrink(){
            if(size <= 1)
                return 0;
            else{
                size--;
                return 1;
            }
        }
    private:
        int size;
        char border;
        char fill;
};