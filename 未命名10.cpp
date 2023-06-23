#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int i;
	char s1[20],s2[20];
	cin>>s1;
	for(i=0;i<strlen(s1)+1;i++)
	{
		s2[i]=s1[i];
	}
		cout<<s2;
		if(s1[i]=='\0')
		cout<<"\\"<<"0";
	
	return 0;
}
