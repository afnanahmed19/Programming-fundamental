#include <iostream>
//code topic is variable like bool and local and global variable concept
using namespace std;
int glo= 6; // global variable
void sum(){ // void sum specifies that the function doesn't return a value
    int a;
    cout<< glo;
}

int main(){  
    int glo=9;  //this is proof local>global (presedense)
    
    int a=14, b=15;
    float pi=3.15;
    char c ='d';
    bool is_false =false; // in result you see that true as 1 and false as 0
    sum();
    cout<<glo<<" "<<is_false; // 
 
return 0;   
}
