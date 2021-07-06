/*
Name: Mario Luja
Description: This program displays the volume of a ring.
The purpose of this program is to understand how to write
multiple subprograms.
*/
#include <iostream>
#include <math.h>
using namespace std;

void introHeader();
void programInput(double & ringRadius, double & crossSectionRadius);
double calculateVolume(double &ringRadius, double &crossSectionRadius);
void displayVolume(double & volume);

//main program that will execute all subprograms
int main()
{
	//Variables used in this scope
	double ringRadius = 0.0;
	double crossSectionRadius = 0.0;
	double volume = 0.0;
	
	//All four methods that will be executed
	introHeader();
	programInput(ringRadius,crossSectionRadius);
	volume = calculateVolume(ringRadius,crossSectionRadius);
	displayVolume(volume);
	
	return 0;
}

//First subprogram that is the intro
void introHeader()
{
	cout<<"Welcome to the Compute Ring Volume program. You will be asked"
	<<" the ring radius and cross section radius, both in inches.\n"<<endl;	
}

//Second subprogram for input
void programInput(double & ringRadius, double & crossSectionRadius)
{;
	
	cout<<"Please enter the ring radius(inches): ";
	cin>>ringRadius;
	
	while(ringRadius <= 0)
	{
		cout<<"Please enter a positive integer for ring radius:";
		cin>>ringRadius;	
	}
	
	cout<<"Please enter the cross section radius(inches): ";
	cin>>crossSectionRadius;
	
	while(crossSectionRadius <= 0)
	{
		cout<<"Please enter a positive integer for cross section radius:";
		cin>>crossSectionRadius;	
	}
	

}


//Method to calculate the volume of the ring
double calculateVolume(double &ringRadius, double &crossSectionRadius)
{
	double volume = 0.0;
	double const PI = 3.14159;
	
	volume = (2*pow(PI,2))*(ringRadius*pow(crossSectionRadius,2));
	
	return volume;
}

//Method to display the final volume
void displayVolume(double & volume)
{
	   cout<<"\nThe volume of the ring is: "<<volume<<" inches";
}
