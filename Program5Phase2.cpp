/*
Name:Mario Luja
Date:2/28/2021
The purpose of the program is to gain knowledge on
functions,pass by values, pass by reference, and
the function return value. As well as building off
the code of phase 1.
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
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
void optionOne();
void artilleryTable();
void inputVelocity(double *initialVelocity);
void inputVericalAngle(double*initialAngle);
void inputHorizontalAngle(double *horizontalAngle);
void inputRows(int *rows);
void varyValue(double *verticalAngle,double *initialVelocity,
int *varyChoice, double *varyAmount);
void randomPoint(double *x1, double *y1);
void targetPractice();
void targetPrompt(int *difficulty);
void placeCannon(double *cannonX, double * cannonY);
void compareDistance(int radius, double distance,int *hitTarget);
int easyMode(int radius);
int normalMode(int radius);
int hardMode(int radius);
void cheating(int *cheat);

int main()
{
	int choice;
	char confirm;
	//Introduction Header for program
	do
	{
		
		cout<<"Welcome to Program 5 phase 2!"<<endl;
		cout<<"Please enter a number to perform a task.\n"<<endl;
		
		//Options for actions to perform
		cout<<"(1) Basic calculations"<<endl;
		cout<<"(2) Create artillery table"<<endl;
		cout<<"(3) Target practice"<<endl;
		cout<<"(4) Quit the program"<<endl;
	
		cout<<"Enter the task you want to perform (1-4): "<<endl;
		cin>>choice;
		
		while(choice < 1 || choice > 4)
		{
			cout<<"Please enter a number 1-4 to indicate a task: ";
			cin>>choice;
		}
		
		if(choice == 1)
		{
			optionOne();		
		}
	
		else if(choice == 2)
		{
			artilleryTable();
		}
		
		else if(choice == 3)
		{
			targetPractice();
		}
		
		else
		{
			cout<<"Thank you for using this program!"<<endl;
		}
	}while(choice !=4);

	
	return 0;
			
}
void optionOne()
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
			while(confirm !='y' &&confirm != 'n')
			{
				cout<<"Please indicate if you want to do another calculation" 
				<<"(\"y\" or \"n\"): ";
				cin>>confirm;
			}	
		}
	//Check if user wants to quit or do another calculation	
	}while (confirm == 'y');
}

void artilleryTable()
{
	double initialVelocity;
	double initialAngle;
	int rows;
	double varyAmount;
	int varyChoice;
	
	inputVelocity(&initialVelocity);
	inputVericalAngle(&initialAngle);
	inputRows(&rows);
	
	varyValue(&initialAngle,&initialVelocity,&varyChoice,&varyAmount);
	
	//Vary vertical angle
	if(varyChoice == 1)
	{
		cout<<"Angle\t\tDistance"<<endl;
		cout<<"(degs)\t\t(feet)"<<endl;
		for(int i = 0; i < rows; i++)
		{
			cout<<initialAngle<<"\t\t";
			cout<<optionTwoEngineer(initialVelocity,initialAngle)<<endl;
			initialAngle += varyAmount;
		}
	}
	
	//vary inital velocity
	else
	{
		cout<<"Velocity\t\tDistance"<<endl;
		cout<<"(MPH)\t\t(feet)"<<endl;
		for(int i = 0; i < rows; i++)
		{
			cout<<initialVelocity<<"\t\t";
			cout<<optionTwoEngineer(initialVelocity,initialAngle)<<endl;
			initialVelocity += varyAmount;
		}
	}
	
}

void targetPractice()
{
	//Variables declared
	int difficulty;
	double cannonX;
	double cannonY;
	double x2;
	double y2;
	double landX;
	double landY;
	double elevation;
	double horizontalAngle;
	double velocity;
	double distance;
	int radius;
	int hitTarget;
	int shots;
	int cheat;
	char repeat;
	
	do
	{
		targetPrompt(&difficulty);
		
		//Target coordinates are returned to (0,0) if repeated
		x2 = 0;
		y2 = 0;
		
		//Selects radius
		if(difficulty ==1)
		{
			radius = easyMode(radius);
		}
		
		else if(difficulty ==2)
		{
			radius = normalMode(radius);
		}
		
		else
		{
			radius = hardMode(radius);
		}
		
		//place cannon at (2500,0)
		placeCannon(&cannonX,&cannonY);	
		randomPoint(&x2,&y2);
		
		
		//Display coordinates of target
		cout<<"The coordinates of the target are: ("<<x2<<","<<y2<<")."<<endl;
		
		//Cheat?
		cheating(&cheat);
		
		if(cheat ==1)
		{
			optionOneEngineer(x2,cannonX,y2,cannonY, &distance,&horizontalAngle);
			cout<<"The required distance is: "<<distance<<"ft"<<endl;
			cout<<"The required angle is: "<<horizontalAngle<<"degrees"<<endl;
			
		}
		
		//Input direction
		inputHorizontalAngle(&horizontalAngle);
		//Input elevation
		inputVericalAngle(&elevation);
		//Input velocity
		inputVelocity(&velocity);
		
		//calculate distance
		distance = optionTwoEngineer(velocity,elevation);
		
		//Calulate where the shell lands
		optionThreeEngineer(x2,y2,distance,horizontalAngle,landX,landY);
		
		//Calculate distance from position and target
		optionOneEngineer(x2,landX,y2,landY, &distance,&horizontalAngle);
		
		//	Compare distance and the radius
		compareDistance(radius,distance,&hitTarget);
		shots++;
		//Another shot?
		cout<<"Do you want to take another shot?(y or n):";
		cin>>repeat;
		while(repeat != 'y'&&repeat!='n')
		{
			cout<<"Please indicate if you want to shoot (\"y\" or \"n\"): ";
			cin>>repeat;
		}
	}while(repeat =='y');
	
	cout<<"\nShots made: "<<hitTarget<<endl;
	cout<<"Amount of total shots: "<<shots<<endl;
}
void targetPrompt(int *difficulty)
{
	cout<<"Welcome to the target practice!"<<endl;
	cout<<"Please select game difficulty: "<<endl;
	cout<<"1 for easy."<<endl;
	cout<<"2 for normal."<<endl;
	cout<<"3 for hard.\n"<<endl;
	cin>>*difficulty;
	while(*difficulty >3||*difficulty <1)
	{
		cout<<"Please enter 1,2,or 3 as a choice: ";
		cin>>*difficulty;
	}
}

void randomPoint(double *x1, double *y1)
{
	srand(time(NULL));	
	
	*x1 = rand()%5000;
	*y1 = rand()%5000;	
	
}


void placeCannon(double *cannonX, double * cannonY)
{
	*cannonX = 2500;
	*cannonY = 0;
}

int easyMode(int radius)
{
	return radius = 100;
}

int normalMode(int radius)
{
	return radius = 25;
}

int hardMode(int radius)
{
	return radius = 5;
}

void cheating(int *cheat)
{
	cout<<"Do you want to cheat?(1 = yes,0 = no): ";
	cin>>*cheat;
	while(*cheat != 1&& *cheat!=0)
	{
		cout<<"Please enter 0 for no, or 1 for yes if you want"
		<< "to cheat:";
		cin>>*cheat;
	}
}

void compareDistance(int radius, double distance,int *hitTarget)
{
	if (distance <= radius)
	{
		cout<<"BOOM!"<<endl;
		cout<<"Shell has hit the target!"<<endl;
		*hitTarget+=1;
	}
	else
	{
		cout<<"OOPS!"<<endl;
		cout<<"The shell did not hit the target..."<<endl;
	}
}
void inputVelocity(double*initialVelocity)
{
	cout<<"Please enter inital velocity (mph): ";
	cin>>*initialVelocity;
	while(*initialVelocity <= 0)
	{
		cout<<"Please enter a positive inital velocity (mph): ";
		cin>>*initialVelocity;	
	}
	
}

void inputHorizontalAngle(double *horizontalAngle)
{
	
	cout<<"Please enter horizontal angle (degrees): ";
	cin>>*horizontalAngle;
	while(*horizontalAngle < 0|| *horizontalAngle > 180 )
	{
		cout<<"Please a horizontal angle between 0 and 180 inclusively "
		<<"(degrees): ";
		cin>>*horizontalAngle;	
	}
	
}
void inputVericalAngle(double *initialAngle)
{
	cout<<"Please enter inital vertical angle (degrees): ";
	cin>>*initialAngle;
	while(*initialAngle <= 0|| *initialAngle >= 90 )
	{
		cout<<"Please a vertical angle between 0 and 90 exclusively "
		<<"(degrees): ";
		cin>>*initialAngle;	
	}
	
}

void varyValue(double *verticalAngle,double *initialVelocity,
int *varyChoice, double *varyAmount)
{

	cout<<"Choose what you want to vary \"1\" for vertical angle"
		<<" or \"2\" for initial velocity:";
	cin>>*varyChoice;
	while(*varyChoice != 1 && *varyChoice !=2)
	{
		cout<<"Choose what you want to vary \"1\" for vertical angle"
		<<" or \"2\" for initial velocity:";
		cin>>*varyChoice;
	}
	
	cout<<"How much do you want to vary by: ";
	while(*varyAmount < 0 )
	{
		cout<<"Vary amount cannot be negative: ";
		cin>>*varyAmount;
	}
	cin>>*varyAmount;
	
}

void inputRows(int *rows)
{
	cout<<"How many rows do you want printed in the table: "<<endl;
	cin>>*rows;
	while(*rows <= 0)
	{
		cout<<"Please enter a positive number of rows: "<<endl;
		cin>>*rows;
	}
	
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
	
	cout<<"Please enter the distance (ft) (positive): ";
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
