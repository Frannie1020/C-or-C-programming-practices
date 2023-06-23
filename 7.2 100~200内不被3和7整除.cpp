#include<iostream>
using namespace std;
int main()
{
	int i;
	for(i=100;i<=200;i++)
	{
		if(i%3!=0&&i%7!=0)
		cout<<i;
	}
	return 0;
}
