#include <iostream>
#include <string>
#include<iomanip>
#include<math.h>
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
int main()
{
    // set decimal outputs to 2 decimal places
    cout << setiosflags( ios::fixed | ios::showpoint ) << setprecision( 2 );
    // create some Diamonds
    Diamond d1( -5 ), d2( 7, '^' ), d3( 12, 'X', 'O' ), d4( 50 , '$' , 'o');
    // display original Diamonds
    cout << "d1 has size = " << d1.GetSize() << " units.\n";
    d1.Draw();
    cout << "\nd2 has size = " << d2.GetSize() << " units.\n";
    d2.Draw();
    cout << "\nd3 has size = " << d3.GetSize() << " units.\n";
    d3.Draw();
    cout << "\nd4 has size = " << d4.GetSize() << " units.\n";
    d4.Draw(); cout << '\n';
    d1.Shrink(); // demonstrate shrink
    d2.Shrink();
    d3.Grow(); // and grow
    d4.Grow();
    cout << "d1 now has size = " << d1.GetSize() << " units.\n";
    cout << "d2 now has size = " << d2.GetSize() << " units.\n";
    cout << "d3 now has size = " << d3.GetSize() << " units.\n";
    cout << "d4 now has size = " << d4.GetSize() << " units.\n";
    // demonstrate perimeter
    cout << "d2 has perimeter = " << d2.Perimeter() << " units.\n";
    cout << "d3 has perimeter = " << d3.Perimeter() << " units.\n";
    // and area
    cout << "d2 has area = " << d2.Area() << " square units.\n\n";
    cout << "d3 has area = " << d3.Area() << " square units.\n\n";
    d1.Draw();
    d1.Grow(); // show that fill character
    cout << "d1 grows:\n"; // appears only when size
    d1.Draw(); // is at least 3
    d1.Grow();
    cout << "... and grows:\n";
    d1.Draw();
    cout << '\n';
    d1 = d2; // demonstrate the default overload of the
    // assignment operator
    cout << "d1 now has size = " << d1.GetSize() << " units.\n";
    d1.Draw();
    // demonstrate the changing of border and fill characters
    d2.SetBorder('@');
    d2.SetFill('-');
    cout << "d2 now looks like:\n";
    d2.Draw();
    cout << '\n';
    d2.SetBorder('\n'); // illegal border
    d2.SetFill('\a'); // illegal fill
    cout << "d2 now looks like:\n";
    d2.Draw();
    cout << '\n';
    cout << "\nHere is a summary on d3:\n"; // demonstrate summary
    d3.Summary();
    return 0;
} 