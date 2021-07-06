/*
Program #7
Name:Mario Luja
Date: 4/5/2021
Description: The purpose of this program is to 
find the frequency of letters in a c-string while also
using ascii arithmetic.

*/
#include <iostream>
using namespace std;
void readInput(char message[501]);
char toLowercase(char character);
void letterRate(char message[501] ,int letters[25]);
void printTable(int letters[25]);
void getLine(char buffer[501]);
int main()
{
	char confirm;
	char message [501];	//C string message
	int letters [25];	// 25 characters
	do
	{	

		readInput(message);
		letterRate(message,letters);
		printTable(letters);
		cout<<"Do you want to enter another message (y or n): ";
		cin>>confirm;
	}while(confirm == 'y' ||confirm == 'Y');
	
	return 0;
	
}

void getLine(char buffer[501])
{
	int i;
	char c;
	
	i = 0;
	while( (c = cin.get()) == '\n');
	do{
		buffer[i] =c;
		i++;
		c = cin.get();
	}
	while(c != '\n');
	buffer[i] = '\0';
}

void readInput(char message[501])
{

	cout<<"Enter message: ";
	getLine(message);

}

void letterRate(char message[501],int letters[25])
{

	int j = 0;
	int index;
	char lowercase;
	
	//Set letter count array to 0
	for (int i = 0; i<= 25; i++)
	{
		letters[i] = 0;
	}
	
	//Obtain index of each character
	while(message[j] != '\0')
	{
		//conver char in array to lowercase
		lowercase = toLowercase(message [j]);
		
		index = lowercase - 'a';
		letters[index] += 1;
		
		j++;	
	}
	
}

char toLowercase(char character)
{
	char lowercase;
	//Check if char is upercase
	if (character <= 'Z' && character >= 'A')
	{
		lowercase = character + ('a' - 'A');
	}
	
	//Character passed is already lowercase
	else
	{
		return character;
	}	
	
	//Return lowercase character
	return lowercase;
	
}

void printTable(int letters[25])
{
	char letter;
	double frequency;
	int total =0;
	char print;
	  
	//Display table header
	cout<<"letter\tcount\tfrequency"<<endl;
	
	//count total
	for(int j = 0; j <= 25; j++)
	{
		total += letters[j];
	} 
	
	//Print first half of table
	for(int i = 0; i <= 12; i++)
	{
		letter = (char)('a' + i);
		frequency = (letters[i] /(double) total) * 100;	
		cout<<letter<<"\t"<<letters[i]<<"\t"<<frequency<<"%"<<endl;
	}
	
	cout<<"Plese press y to continue printing table:";
	cin>>print;
	while(print != 'y')
	{
		cout<<"Enter the character y to continue printing the table: ";
		cin>>print;
	}
	
	//Print second half of table
	for(int k = 13; k <= 25; k++)
	{
		letter = (char)('a' + k);
		frequency = (letters[k] /(double) total) * 100;	
		cout<<letter<<"\t"<<letters[k]<<"\t"<<frequency<<"%"<<endl;
	}
	
}
