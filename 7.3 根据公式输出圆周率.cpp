#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int s=1,n=1;
    double PI=0.0,t=1;
    while(fabs(t)>1e-8)
    {
    	PI+=t;
    	n+=2;
    	s=-s;
    	t=s*1.0/n; 
	}
	cout<<"steps="<<(n+1)/2<<" "<<"PI="<<PI*4;
	return 0;
}
