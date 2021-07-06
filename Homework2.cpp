/*
Name: Mario Luja, Purpose: The purpose of this program is to get a better
understanding of C++ and how to use loops and math in C++, by calculating
the volume of spheres.
*/
#include <iostream>
#include <math.h>
using namespace std;


double volume(double PI, double radius);
int main()
{
	
	//Variables used in program
	const double PI = 3.14159;	//PI constant value
	int NSpheres = 0;			//The number of spheres
	double radius = 0.0;		
	double totalVolume = 0.0;
	

	//Entering number of spheres
	cout<<"Enter the number of spheres: ";
	cin>>NSpheres;
	
	do
	{
		//Entering the radius
		cout<<"Enter the radius: ";
		cin>>radius;
		
		//Check if the radius is positive
		while(radius < 0)
		{
			cout<<"Please enter a positive radius: ";
			cin>>radius;
		}
		//Add volume into a total
		totalVolume += volume(PI,radius);
		NSpheres--;
	}while(NSpheres > 0);
	
	//Display total volume
	cout<<"Total Volume: " << totalVolume;
	return 0;
}

//Function to calculate volume
double volume(double PI, double radius)
{
	double volume = 0.0;
	volume = ((4.0/3.0)*PI)*pow(radius,3);
	return volume;
}




