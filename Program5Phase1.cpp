/*
Name:Mario Luja
Date:2/26/2021
The purpose of the program is to gain knowledge on
functions,pass by values, pass by reference, and
the function return value.
*/
#include <iostream>
#include <math.h>
using namespace std;

//Function prototypes
void optionOneCustomerService();
void optionOneEngineer(double x1,double x2,double y1,double y2,
double *distance,double *degHorizontalAngle);
void optionTwoCustomerService();
double optionTwoEngineer(double velocity,double elevationAngle);
void optionThreeCustomerService();
void optionThreeEngineer(double x1, double y1,double distance,
double horizontalAngle, double &x2, double &y2);
void enterPoints(double *x,double *y);


int main()
{
	int choice;
	char confirm;
	
	//Introduction Header for program 5a
	cout<<"Welcome to Program 5 phase 1!"<<endl;
	cout<<"Please enter a number to perform a task.\n"<<endl;
	do
	{
	
		//Menu for program 5
		cout<<"Enter 1 to compute the distance between two points."<<endl;
		cout<<"Enter 2 to compute the horizontal distance an object"<< 
		"travels."<<endl;
		cout<<"Enter 3 compute the destination point.\n\n"<<endl;
		//Enter what calculation they want to do
		cout<<"Please chooses and instruction (1-3): ";
		cin>>choice;
		//Verify choice is between 1-3
		while(choice < 1 || choice > 3)
		{
			cout<<"Please enter an instruction using 1,2,or 3: ";
			cin>>choice;
		}
		
		if (choice ==1)
		{
			optionOneCustomerService();
			cout<<"Do you want to do another calculation (y or n): ";
			cin>>confirm;

			
		}
		
		else if(choice ==2)
		{
			
			optionTwoCustomerService();
			cout<<"Do you want to do another calculation (y or n): ";
			cin>>confirm;
		}
		
		else
		{
			optionThreeCustomerService();
			cout<<"Do you want to do another calculation (y or n): ";
			cin>>confirm;
			while(confirm !='y' && confirm !='n')
			{
				cout<<"Please indicate if you want to do another calculation" 
				<<"(\"y\" or \"n\"): ";
				cin>>confirm;
			}	
		}
	//Check if user wants to quit or do another calculation	
	}while (confirm == 'y');
	
	return 0;
			
}

void optionOneCustomerService()
{
	double x1,x2,y1,y2;
	double distance;
	double degHorizontalAngle;
	
	cout<<"You chose option 1:\n\n"<<endl;	
	
	enterPoints(&x1,&y1);
	enterPoints(&x2,&y2);
	
	
	
	optionOneEngineer(x1,x2,y1,y2,&distance,&degHorizontalAngle);
	cout<< "The distance between both points is: "<<distance<<"ft"<<endl;
	cout<< "The horizontal angle is: "<<degHorizontalAngle<<"degrees"<<endl;
		
}

void optionOneEngineer(double x1,double x2,double y1,double y2,
double *distance, double *degHorizontalAngle)
{
	const double PI = 3.14159;
	double dx;
	double dy;
	double radHorizontalAngle;
	double xSquared;
	double ySquared;
	double sum;
	
	dx = x2-x1;
	dy = y2-y1;
	
	if(dx > 0)
	{
		radHorizontalAngle = atan(dy/dx);
	}
	
	else if(dx < 0)
	{
		radHorizontalAngle = atan(dy/dx) + PI;
	}
	
	else if(dx == 0 && dy >= 0)
	{
		radHorizontalAngle = PI/2;
	}
	
	else
	{
		radHorizontalAngle = -(PI/2);
	}
	
	*degHorizontalAngle = radHorizontalAngle *(180/PI);
	
	
	xSquared = pow(dx,2);
	ySquared = pow(dy,2);
	sum = xSquared + ySquared;
	*distance = sqrt(sum);
		
}

void optionTwoCustomerService()
{
	double velocity;
	double elevationAngle;
	double horizontalDistance;
	
	cout<<"You chose option 2:\n\n"<<endl;	
	
	cout<<"Please enter the velocity (MPH)(positive): ";
	cin>>velocity;	
	
	while(velocity <= 0)
	{
		cout<<"Plese enter a positive value for velocity(MPH): ";
		cin>>velocity;
	}
	
	cout<<"Please enter the elevation angle (0-90): ";
	cin>>elevationAngle;
	
	while(elevationAngle <= 0||elevationAngle >= 90)
	{
		cout<<"Please enter angle between 0 and 90 exclusively: ";
		cin>>elevationAngle;
	}
	
	horizontalDistance = optionTwoEngineer(velocity,elevationAngle);
	
	cout<<"The horizontal distance is: "<<horizontalDistance<<"ft"<<endl;
		
}

double optionTwoEngineer(double velocity,double elevationAngle)
{
	const double GRAVITY = 32.172; 
	const int FEETPERMILE = 5280;
	const int SECONDSPERHOUR = 3600;
	const double PI = 3.14159;
	double horizontalDistance;
	double velocityFeet;
	double radElevationAngle;
	
	radElevationAngle = elevationAngle*(PI/180);
	velocityFeet = velocity * ((double)FEETPERMILE/SECONDSPERHOUR);
	horizontalDistance = pow(velocityFeet,2)* sin(2*radElevationAngle)
	/GRAVITY;
	
	return horizontalDistance;
	
}

void optionThreeCustomerService()
{
	double distance;
	double x1;
	double y1;
	double horizontalAngle;
	double x2;
	double y2;
	
	cout<<"You chose option 3:\n\n"<<endl;	
	
	cout<<"Please enter the distance (ft)(positive): ";
	cin>>distance;
	
	while(distance <= 0 )
	{
		cout<<"Plese enter a positive value for distance: ";
		cin>>distance;
	}
	
	enterPoints(&x1,&y1);
	
	cout<<"Please enter the horizontal angle (0-360): ";
	cin>>horizontalAngle;
	
	while(horizontalAngle < 0||horizontalAngle > 360)
	{
		cout<<"Please enter angle between 0 and 360 inclusive: ";
		cin>>horizontalAngle;
	}
	
	optionThreeEngineer(x1,y1,distance,horizontalAngle,x2,y2);
	cout<<"The destination point is: ("<<x2<<","<<y2<<")"<<endl;
}

void optionThreeEngineer(double x1, double y1,double distance,
double horizontalAngle, double &x2, double &y2)
{
	const double PI = 3.14159;
	double radHorizontalAngle;
	double differenceX;
	double differenceY;

	
	radHorizontalAngle = horizontalAngle * (PI/180);
	differenceX = distance *cos(radHorizontalAngle);
	differenceY = distance *sin(radHorizontalAngle);
	x2 = x1 +differenceX;
	y2 = y1 +differenceY;
}

void enterPoints(double *x,double *y)
{
	cout<<"Please enter the x-value (in feet): ";
	cin>>*x;
	cout<<"Please enter the y-value (in feet)): ";
	cin>>*y;

}


