//Homework #7
//Name:Mario Luja
//The purpose of this program is to understand
//pointers and adresses.
#include <iostream>
using namespace std;

int main( )
{
	int one;	//address 8171
	int *ptr;	//8170
	int list[3];	//8172,8173,8174
	
	list[0] =77;	//77 in address 8172
	list[1] = 88;	//88 in address 8173
	list[2] = 99;	//99 in address 8174
	one = 1111;		//1111 in address 8171
	ptr = &one;		//address value 8171 stored in address 8170
	
	cout << one << endl;	//Prints value of one 1111
	cout << &one << endl;	//prints address of one 8171
	
	cout << list << endl;	//Prints address of list
	cout << list[2] << endl;	//Prints values 99
	cout << *list << endl;	//Prints the value in the base address (77)
	
	cout << &ptr << endl;	//Prints address of ptr 8170
	cout << ptr << endl;	//Prints value of ptr 8171
	cout << *ptr << endl;	//Prints the value of one 8171
	
	cout << *(ptr + 2) << endl;	// *(8173) which dereferences element 0 in list
	cout << *(ptr - 1) << endl;	//*(8169) unknown value
	
	cout << *(++ptr) << endl;	//*(8172) which gives us list[2] value 99
	cout << *(ptr + 1) << endl;	//*(8172) which also gives 99
	cout << *ptr + 1 << endl;	// 8171 +1 = address value 8172
	
	return 0;
}
