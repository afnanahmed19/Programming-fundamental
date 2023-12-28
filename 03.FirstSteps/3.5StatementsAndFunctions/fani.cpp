#include <iostream>
using namespace std;

//function declearation
    int addnumbers(int first_para ,int second_para){
    int result = first_para + second_para;
    return result;
   
     
}

int main(){
        int num1,num2;
     cout<<"please enter number"<<endl;
       cin>>num1;

     cout<<"please enter second number"<<endl;
      cin>>num2;

    int  sum =addnumbers(num1,num2);
     cout << "The sum of " << num1 << " and " << num2 << " is: " << sum ;

    return 0;
}