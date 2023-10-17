#include <iostream>

using namespace std;
int glo= 6; // but dominant is local // it is possible to make same local and global variable with same name // but local>global
void sum(){
    int a;
}

int main(){  
    int glo=9;  //this is proof local>global (presedense)
    
     // int a = 14;
     // int b = 15;
    int a=14, b=15;
    float pi=3.15;
    char c ='d';
    sum();
    cout<<glo;
    return 0;
}
