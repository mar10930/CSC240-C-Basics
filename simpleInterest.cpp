#include <iostream>
using namespace std;

int main()
{
	double principal = 0;
	double rate = 0;
	double time = 0;
	double result = 0;
	
	cout<<"Enter principal amnt: ";
	cin>>principal;
	cout<<"Enter rate amnt: ";
	cin>>rate;
	cout<<"Enter time in yrs: ";
	cin>>time;
	result = principal*rate*time;
	cout <<result;
}
