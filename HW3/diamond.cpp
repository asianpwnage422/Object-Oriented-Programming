#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "diamond.h"
using namespace std;

//diamond defintion
Diamond::Diamond(int inputSize, char new_border, char new_fill){
    SetSize(inputSize);
    SetBorder(new_border);
    SetFill(new_fill);
}

void Diamond::SetSize(int inputSize){
    if(inputSize < 1)
        size = 1;
    else if(inputSize > 39)
        size = 39;
    else
        size = inputSize;
}
void Diamond::SetBorder(char new_border){
    if(new_border < 33 || new_border > 126)
        return ;
    else
        border = new_border;
}
void Diamond::SetFill(char new_fill){
    if(new_fill < 33 || new_fill > 126)
        return ;
    else
        fill = new_fill;
}
const int Diamond::GetSize(){
    return size;
}
int Diamond::Perimeter(){
    return 4*size;
}
double Diamond::Area(){
    double ans = 0;
    ans = (sqrt(3)/2) * pow(size,2);
    return ans;
}
//Grow and Shrink return 1 if success
int Diamond::Grow(){
    if(size >= 39)
        return 0;
    else{
        ++size;
        return 1;
    }
}
int Diamond::Shrink(){
    if(size <= 1)
        return 0;
    else{
        --size;
        return 1;
    }
};
void Diamond::Draw()
{
    if(size==1) printf("%c\n",border);
    else
    {
        
        for(int i=1;i<=size;i++)
        {
            
            for(int j=1;j<=(size-i);j++)printf(" ");
            printf("%c ",border);
            if(i==1)printf("\n");
            for(int j=1;j<=(i-2);j++) printf("%c ",fill);
            if(i!=1)printf("%c\n",border);
        
        }
        for(int i=(size-1);i>=1;i--)
        {
            for(int j=1;j<=(size-i);j++)printf(" ");
            printf("%c ",border);
            if(i==1)printf("\n");
            for(int j=1;j<=(i-2);j++) printf("%c ",fill);
            if(i!=1)printf("%c\n",border);
        }
        
    }
}
void Diamond::Summary()
{
    printf("Size of diamond's side = %d units.\n",size);
    printf("Perimeter of diamond = %d units.\n",Perimeter());
    printf("Area of diamond = %.2f units.\n",Area());
    printf("Diamond looks like:\n");
    Draw();
}   
