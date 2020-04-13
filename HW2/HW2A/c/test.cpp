#include <iostream> 
using namespace std;
// the call f(arr) is implemented as
// call-by-reference.

void f (int val, int &ref) { val++; ref++;};
void g() {
    int i = 1,
    j = 1;
    f(i, j);
    cout << i << j << endl; // 1 2
    }
int main(){
    int i = 5;
    int *p=&i;
    int *&r = p;
    cout << &r << endl;
    printf("r:%p %d p:%p %d\n",&r,*r,&p,*p);
    return 0;
}