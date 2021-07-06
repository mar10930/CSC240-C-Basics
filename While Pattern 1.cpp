#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int i= 1;
	int k = 1;
	int row = 1;
	cout<<"Enter the highest value printed (n): ";
	cin>>n;
	while(row <= n)
	{
		i =1;
		while(i <= k)
		{
			cout<<i;
			i++;
		}
		cout<<endl;
		row++;
		k++;
	}
}
