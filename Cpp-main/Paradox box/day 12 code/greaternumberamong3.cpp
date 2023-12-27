#include<iostream>
using namespace std;

int main() {
  
   double num1,num2,num3;

   cout<<"Plz enter first number";
   cin>>num1;

   cout<<"plz enter second number";
   cin>>num2;

   cout<<"plz enter third number";
   cin>>num3;

   //using conditional statement
    
    int largestNum;
    if (num1>=num2 && num1>=num3){
        largestNum=num1;
    } else if (num2>=num1 && num2>=num3){
             largestNum=num2;
    } else  {
        largestNum=num3;
    }
//result print
cout<<"Largest number is:  "<<largestNum<<endl;


    return 0;
}