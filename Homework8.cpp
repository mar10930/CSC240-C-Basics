/*
Name: Mario Luja
Date:2/23/2021
Program name : Homework8.cpp
The purpose of this program is to know how to declare
C-strings. Also how to use C-strings as input.
*/
#include<iostream>
using namespace std;

int main()
{
	//5 inputs declared as c-strings
	char name [81];
	char verb[81];
	char object[81];
	char adjective[81];
	char sillyWord[81];
	
	//Entering information used in the Mad Lib
	
	cout<<"What is your name?: ";
	cin>>name;
	cout<<"Enter a verb: ";
	cin>>verb;
	cout<<"What is your favorite object?: ";
	cin>>object;
	cout<<"What adjective best describes you?: ";
	cin>>adjective;
	cout<<"Enter a silly word: ";
	cin>>sillyWord;
	
	
	//Output of the madlib
	
	cout<<"\nThis is the following Mad Lib based on your inputs:"<<endl;
	
	cout<<"\nHi my name is "<<name<<", and I know how to "
		<<verb<<" a/an "<< object<<"."<<endl;
	cout<<"I am a very "<<adjective<<" person."<<endl;
	cout<<"Thank you, have a "<<sillyWord<<" day!"<<endl;
	
	return 0;
}
