#include <iostream>
#include <conio.h> // a non-standard header file that is used in C and C++ code.//use for to hold the output screen //use along with getch(); function

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
   getch(); // use along with #include <conio.h>  //return 0; is not use in that case  // you will need to press button twice time
}
