#include<iostream>
using namespace std;
int main(void)
{
	int y,m,d;
	int b=31,s=30,c=29,s2=28;
	cin>>y>>m;
	if(m>=12)
	m%=12;
	if(y%400==0||(y%4==0&&y%100!=0))
	{
		if(m==2)
		cout<<"days:"<<c;
		else if(m==4||m==6||m==9||m==11)
		cout<<"days:"<<s;
		else
		cout<<"days:"<<b;
	}
	else
	{
		if(m==2)
		cout<<"days:"<<s2;
		else if(m==4||m==6||m==9||m==11)
		cout<<"days:"<<s;
		else
		cout<<"days:"<<b;
	}
	return 0;
}
