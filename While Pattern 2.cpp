#include <iostream>
using namespace std;

int main()
{
	int m =1;
	int n = 0;
	int i= 1;
	int k = 1;
	int row = 1;
	cout<<"Enter the highest value printed (n): ";
	cin>>n;
	int spaces = n-1;
	while(row <= n)
	{
		i =1;
		m=1;
		while(m <= spaces)
		{
			cout<<" ";
			m++;
		}
		while(i <= k)
		{
			cout<<i;
			i++;
		}
		cout<<endl;
		row++;
		k++;
		spaces--;
		
	}
}
