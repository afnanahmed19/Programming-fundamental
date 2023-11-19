#include <iostream>
using namespace std;

// declaration of functions
void  printMessage(void);
float calAverage(int,int,int);

int main(){
	int a,b,c;
	float avg;
	// calling first function
	printMessage();
	cout<<"Enter first number :"; cin>>a;
	cout<<"Enter second number:"; cin>>b;
	cout<<"Enter third number :"; cin>>c;
	// calling calAverage function
	avg=calAverage(a,b,c);
	cout<<"\nAverage is = "<< avg <<"\n";
	return 0;
}


/***********************************************
 *function name	: printMessage
 *description	: to print some message
 *return type	: No (void)
 *argument list	: No (void)
***********************************************/
void	printMessage(void)
{
	cout<<"\nHello.. I am function's body !!!\n";
}

/***********************************************
 *function name	: calAverage
 *description   : to calculate average 
 *return type	: int,int,int (3 integer values)
 *argument list	: float 
***********************************************/
float calAverage(int x,int y,int z)
{
	int sum=0;
	sum=(x+y+z);
	return ((float)sum/3);
}
