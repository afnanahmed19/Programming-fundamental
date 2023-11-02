#include<iostream>
using namespace std;

int main(){
	//code to check person is eligible for vote
	
	int age;
	cout<<"tell me ur age"<<endl;
	cin>>age;
	
	if((age<18)&&(age>0)) {
		cout<<"u are not eligible for voting"<<endl;
	}
	else if (age==18){
	cout<<"u are eligible for voting"<<endl; }
	else if (age<1){
		cout<<"ur are not yet born"<<endl;
	}
	else {
		cout<<"you are welcome for voting"<<endl;
	}
	return 0;
	}
