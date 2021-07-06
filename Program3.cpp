/*Name: Mario Luja, The purpose of this program is to find the
population of pigs in a pig farm using a formula. The programmer
will implement the formula in the program to get the total pig
population. Loops will also be used to print a table of pig 
population per month.
*/
#include <iostream>
using namespace std; 

int numPigs(int months,int initialPopulation,int carryingCapacity,int table,double growthRate);
int main()
{
	//Variables declared
	int carryingCapacity = 0;
	int initialPopulation = 0;
	int newPopulation = 0;
	int months = 0;
	int table = 0;
	int sameCarryingCapacity = 0;
	int newFarm = 0;
	double birthRate = 0.0;
	double deathRate = 0.0;
	double growthRate = 0.0;
	
	
	//Intro to program
	
	cout<<"Welcome to the pig population growth program!"
	<<"The program will ask for the carrying capacity of the "<<endl;
	cout<<"farm, the initial pig population, death rate, and birth rate. "
	<<"It will also print the number of pigs per "<<endl;
	cout<<"month through a table. \n\n\n"<<endl;
	
	
	
	//Ask for Input	
	do
	{
		//Ask for carrying capacity
		cout<<"Please enter the carrying capacity"
		<<"(POSITIVE INTEGERS ONLY): ";
		cin>> carryingCapacity;
		cout<<"\n";
		
		while(carryingCapacity < 1 )
		{
			cout<<"Please enter a positive integer for the "
			<<"carrying capacity: ";
			cin>>carryingCapacity;
			cout<<"\n";
		}
	
	do{	
		//Ask for initial pig population
		cout<<"Please enter the initial pig population"
		<<"(POSITIVE INTEGERS GREATER THAN 0): ";
		cin>> initialPopulation;
		cout<<"\n";
	
		//Check if initial population is positive
		while(initialPopulation < 1 )
		{
			cout<<"Please enter a positive integer for the "
			<<"initial pig population: ";
			cin>>initialPopulation;
			cout<<"\n";
		}
		
		//Ask for the amount of time in months
		cout<<"Please enter the amount of time in months(1-12): ";
		cin>> months;
		cout<<"\n";
		
		//Check if months is between 1 and 12	
		while(months < 1 || months > 12 )
		{
			cout<<"Please enter a positive integer for the "
			<<"amount of moths (1-12): ";
			cin>>months;
			cout<<"\n";
		}
			
		//Ask for birth rate
		cout<<"Please enter the birth rate(NON-NEGATIVE ONLY 0-1): ";
		cin >> birthRate;
		cout<<"\n";
		
		//Check if birth rate is between 0 and 1
		while(birthRate > 1 || birthRate < 0 )
		{
			cout<<"Please enter a number between 1 and 0 for "
			<<"the birth rate: ";
			cin>>birthRate;
			cout<<"\n";
		}
		
		//Ask for death rate
		cout<<"Please enter the death rate(NON-NEGATIVE ONLY 0-1): ";
		cin >> deathRate;
		cout<<"\n";
		
		//Check if death rate is between 0 and 1
		while(deathRate > 1 || deathRate < 0 )
		{
			cout<<"Please enter a number between 1 and 0 for "
			<<"the death rate: ";
			cin>>deathRate;
			cout<<"\n";
		}
		
		//Ask to answer same questions with same carrying capacity
		cout<<"Do you want to answer the same questions with the"
		<<" same carrying capacity? (0 = NO, 1 = YES): ";
		cin>>sameCarryingCapacity;
		cout<<"\n";
		
		//Check carrying capacity input is 0 or 1
		while(sameCarryingCapacity != 1 && sameCarryingCapacity != 0 )
		{
			cout<<"Enter 0 or 1 to indicate if you want to answer"
			<<"the questions with the same "
			<<"carrying capacity.(0 = NO, 1 = YES): ";
			cin>>sameCarryingCapacity;
			cout<<"\n";
		}
		
	}while(sameCarryingCapacity == 1);
		
	//How do you want the results?
	cout<<"Do you want to print the results as a table?"
	<<"(0 = NO, 1 = YES): ";
	cin>> table;
	cout<<"\n";
		
	//Check if user entered 0 oi
	while(table != 1 && table != 0 )
	{
		cout<<"Enter 0 or 1 to indicate if you want a table"
		<<" printed?(0 = NO, 1 = YES): ";
		cin>>table;
		cout<<"\n";
	}
	
	
		//Calculate growth rate
		
		growthRate = birthRate - deathRate;
		
		//Calculations		
	
		numPigs(months,initialPopulation,carryingCapacity,table,growthRate);
		
		//Ask to start a new farm
		cout<<"Do you want to start a new farm?"
		<<"(0 = NO, 1 = YES): ";
		cin>>newFarm;
		cout<<"\n";
		
		//Check if user wants a new farm
		while(newFarm != 1 && newFarm != 0 )
		{
			cout<<"Enter 0 or 1 to indicate if you want to start"
			<<" a new farm?(0 = NO, 1 = YES): ";
			cin>>newFarm;
			cout<<"\n";
		}
	
	//Loop if user wants a new farm
	}while(newFarm == 1);
	
	//Program is terminated
	cout<<"\nProgram was terminated!";
	
	return 0;	
	
}

int numPigs(int months,int initialPopulation,int carryingCapacity,int table,double growthRate)
{
	double bOld;
	double bNew = 0.0;
	int pNew = 0;
	
	//Calculation
	
	if(table == 1)
	{
		//Month 0 population
		cout<<"\nMonth\tPigs";
		cout<<"\n0:\t" << initialPopulation<<endl;
		
		//Loop to print pig population per month
		for(int i = 1; i <= months; i++)
		{
	
			bOld = (double)initialPopulation/carryingCapacity;
			bNew = bOld + (growthRate * bOld *(1- bOld));
			pNew = (bNew * carryingCapacity) + 0.5;
			initialPopulation = pNew;
			
			cout<<i<<":\t"<<initialPopulation<<endl;
		}
	}
	
	else
	{
		//Loop to calculate pig population
		for(int i = 1; i <= months; i++)
		{
			bOld = (double)initialPopulation/carryingCapacity;
			bNew = bOld + (growthRate * bOld *(1- bOld));
			pNew = ((bNew * carryingCapacity) + 0.5);
			initialPopulation = pNew; 	
		}
		cout<<"The final number of pigs is: ";
		cout<<initialPopulation;
		cout<<"\n";
	}
	return initialPopulation;		
}
