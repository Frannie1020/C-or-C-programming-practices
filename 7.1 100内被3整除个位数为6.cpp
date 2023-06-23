#include<iostream>
using namespace std;
int main(void)
{
   int i,j;
   for(i=0;i<=9;i++)
   {
     j=i*10+6;
	 if(j%3)
	 continue;
	 cout<<j;
   }
   return 0;
}
