#include <iostream>
#include <fstream>

using namespace std;

void ReadList(char *argv,int Array[],int N){
    ifstream inFile;
    inFile.open(argv);
    inFile >> N;
    for(int i = 0; i < N; i++){
        inFile >> Array[i];
    }
}
void Avgs(int Array[], int N, float& ave, float& aveP, float& aveN){
    int p_count = 0, n_count = 0, total = 0, p_total = 0, n_total = 0;
    int i;
    for(i = 0; i < N; i++){
        total = total + Array[i];
        //negative total
        if(Array[i] < 0){
            n_total = n_total + Array[i];
            n_count++;
        }
        if(Array[i] > 0){
            p_total = p_total + Array[i];
            p_count++;
        }
    }
    aveP = p_total / p_count;
    aveN = n_total / n_count;
    ave = total / N;
}
int Large(int Array[], int N){
    int max = -100000;
    for(int i = 0; i < N; i++){
        if(Array[i] > max)
        max = Array[i];
    }
    return max;
}

void Display(int Array[], int N){
    int i, max;
    float ave, aveP, aveN;
    Avgs(Array,N,ave,aveP,aveN);
    max = Large(Array, N);
    cout << "ave is " << ave;
    cout << "aveP is " << aveP;
    cout << "aveN is " << aveN;
    cout << "max is " << max;
    cout << endl;
}
int main(int argc, char* argv[])
{
    ifstream inFile;
    inFile.open(argv[1]);
    int N;
    inFile >> N;
    int Array[N];
    ReadList(argv[1],Array,N);
    Display(Array, N);
    return 0;
}