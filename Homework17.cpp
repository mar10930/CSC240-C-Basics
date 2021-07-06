/*
Homework 17
Name:Mario Luja
Date: 4/19/2021
Description: The purpose of this program is to 
use records to return more then one value.

*/
#include <iostream>
#include <math.h>
using namespace std;

struct ScreenDimension
{
	double height;
	double width; 
};
ScreenDimension computeDimensions(double aspectRatio, double diagonal);
int main()
{
	ScreenDimension dimensions;
	double diagonal;
	double aspectRatio;
	
	cout<<"Enter the diagonal length in inches: ";
	cin>>diagonal;
	
	cout<<"Enter the aspect ratio (width over height): ";
	cin>>aspectRatio;
	
	dimensions = computeDimensions (aspectRatio,diagonal);
	cout<<dimensions.height<<endl;
	cout<<dimensions.width<<endl;
	
	return 0;
}

ScreenDimension computeDimensions (double aspectRatio, double diagonal)
{
	ScreenDimension dimensions;
	dimensions.height = sqrt((pow(diagonal,2))/(1+pow(aspectRatio,2)));
	dimensions.width = dimensions.height * aspectRatio;
	return dimensions;

}
