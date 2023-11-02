#include<iostream>
using namespace std;

int main(){
	//code to check person is eligible for vote
	
	int age;
	cout<<"tell me your age: "<<endl;
	cin>>age;
	
	if((age<18)&&(age>0)) {
		cout<<"you are not eligible for voting"<<endl;
	}
	else if (age==18){
	cout<<"you are eligible for voting"<<endl; }
	else if (age<1){
		cout<<"your are not yet born"<<endl;
	}
	else {
		cout<<"you are welcome for voting :)"<<endl;
	}
	return 0;
	}
